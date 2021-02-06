from base64 import b64decode

def read_decode_file():
    with open("test.txt") as input_file:
        return (b64decode(input_file.read()))

def hamming_distance(str1, str2):
    char = []
    for x, y in zip(str1, str2):
        char.append(x ^ y)
    
    counter = 0
    for n in char:
        while(n != 0):
            n = n & (n-1)
            counter = counter + 1
    return counter
    #print(counter)

def finding_key(ciphertext):
    only_key = 0
    normalized_list = []
    lowest = 0
    for keysize in range(2, 40):
        ending_index = 0
        while(True):
            starting_index = ending_index
            ending_index+= keysize

            distance = hamming_distance(ciphertext[starting_index:ending_index], ciphertext[ending_index:ending_index + keysize])
            normalized = distance / keysize
            normalized_list.append(normalized)
            ending_index = ending_index + keysize

            if(ending_index > (len(ciphertext) - 1)):
                break

        average = sum(normalized_list) / len(normalized_list)
        normalized_list = []
        
        if (lowest == 0) or (average < lowest):
            lowest = average
            only_key = keysize

    return only_key
 
def divide_into_chunks(ciphertext, key_length):
    #create a dictionary
    chunks = dict.fromkeys(range(key_length))
    counter = 0
    for c in ciphertext:
        if (counter == key_length):
            counter = 0
        
        if (chunks[counter] == None):
            chunks[counter] = []

        chunks[counter].append(c)
        counter+=1

    return chunks

def brute_force(blocks):
    common = 'ETAOIN SHRDLU'
    key = ''
    for i in blocks:
        current_high_score  = 0
        current_key_char = ''
        for j in range(128):
            xored = [j ^ x for x in blocks[i]]

            #convert into bytes
            b = bytes(xored)
            #convert into strings
            s = str(b, 'utf-8')

            score = 0
            for k in s.upper():
                if k in common:
                    score+=1

            if score > current_high_score:
                current_high_score = score
                current_key_char = chr(j)

        key += current_key_char

    return key

def decrypt(ciphertext, key):
    i = 0
    decrypted = b''
    for c in ciphertext:
        if (i == len(key)): i = 0
        xor = ord(key[i]) ^ c
        decrypted += bytes([xor])
        i+=1
    return decrypted



#main
ciphertext = read_decode_file()
best_key_length = finding_key(ciphertext)
chunks = divide_into_chunks(ciphertext, best_key_length)
key = brute_force(chunks)
print(key)
decrypted = decrypt(ciphertext,key)
print(decrypted)
#print(best_key_length)
#print(chunks)

