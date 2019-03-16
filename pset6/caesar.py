import cs50
import sys

if(len(sys.argv) != 2):
    print("Usage: python caesar.py k")
    exit(1)

shift = int(sys.argv[1]) % 26

plaintext = input("plaintext: ")
ciphertext = ""

for letter in plaintext:
    if(not letter.isalpha()):
        ciphertext += letter
        continue
    if(letter.islower()):
        #97-122
        x = ((ord(letter)+shift)%97)%26
        ciphertext += chr(x + 97)
    if(letter.isupper()):
        #65-90
        x = ((ord(letter)+shift)%65)%26
        ciphertext += chr(x + 65)

print("ciphertext: " + ciphertext)