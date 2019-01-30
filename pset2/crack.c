#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check(char word[], char salt[], string hash);
int main(int argc, string argv[])
{
    //finding the salt (first two chars of hash)
    if(argc!=2){
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string hash = argv[1];
    char salt[3];
    strncpy(salt, hash, 2);

    //looping through every possible combo to see if it is the password
    char hack[6];
    string letters = "0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int loopAmnt = strlen(letters);

    for(int fifth=0; fifth<loopAmnt; fifth++){
        if(letters[fifth]=='0'){
            hack[4]='\0';
        }else{
            hack[4]=letters[fifth];
            hack[5]='\0';
        }

        for(int fourth=0; fourth<loopAmnt; fourth++){
            if(letters[fourth]=='0'){
                hack[3]='\0';
            }else{
                hack[3]=letters[fourth];
            }

                for(int third=0; third<loopAmnt; third++){
                    if(letters[third]=='0'){
                        hack[2]='\0';
                    }else{
                        hack[2]=letters[third];
                    }

                    for(int second=0; second<loopAmnt; second++){
                        if(letters[second]=='0'){
                            hack[1]='\0';
                        }else{
                            hack[1]=letters[second];

                        }

                        for(int first=1; first<loopAmnt; first++){
                            hack[0] = letters[first];

                            string hackHash = crypt(hack, salt);
                            if(strcmp(hackHash, hash)==0){
                                printf("%s\n", hack);
                                exit(0);
                            }
                    }
                }
            }
        }
    }
}
