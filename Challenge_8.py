#read the file
with open('8.txt') as f:
    line_list = [bytes.fromhex(line) for line in f]

repeats_max  = 0
block_size = 16
line_number = 0
counter = 0
for cipher in line_list:
    counter = counter + 1
    blocks = [cipher[i : i + block_size] for i in range(0, len(cipher), block_size)]
    repeats = len(blocks) - len(set(blocks))

    if repeats > repeats_max:
        ciphertext = blocks
        repeats_max = repeats
        line_number = counter

print(ciphertext)
print(repeats_max)
print(line_number)


