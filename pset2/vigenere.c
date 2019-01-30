#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);
bool isNumber(string x);
int main(int argc, string argv[])
{
    string key;
    if(argc == 2 && isNumber(argv[1])){
        key = argv[1];
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        exit(0);
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = "";
    printf("ciphertext: ");

    int keywordIndex = 0;
    for(int i=0; i<strlen(plaintext); i++){

        if(keywordIndex == strlen(key)){
            keywordIndex = 0;
        }

        char currentLetter = plaintext[i];
        char currentKeyLetter = key[keywordIndex];
        int shiftAmnt = shift(currentKeyLetter);
        char cipheredLetter;
        if(islower(currentLetter)){
            cipheredLetter = (plaintext[i] - 97 + shiftAmnt) % 26 + 97;

        }else if(isupper(currentLetter)){
            cipheredLetter = (plaintext[i] - 65 + shiftAmnt) % 26 + 65;

        }else{
            cipheredLetter = currentLetter;
            keywordIndex--;
        }

        printf("%c", cipheredLetter);
        keywordIndex++;
    }
    printf("\n");
}

int shift(char c)
{
    int lowerChar = tolower(c);
    int shift = lowerChar % 97;
    return shift;
}

bool isNumber(string x)
{
    for(int i=0; i<strlen(x); i++){
        if(isdigit(x[i])){
            return false;
        }
    }
    return true;
}
