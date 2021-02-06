from base64 import b64decode
from Crypto.Cipher import AES

def read_decode_file():
    with open("7.txt") as input_file:
        return (b64decode(input_file.read()))

ciphertext = read_decode_file()
key = b'YELLOW SUBMARINE'
cipher = AES.new(key, AES.MODE_ECB)
plaintext = cipher.decrypt(ciphertext)
print(plaintext)