#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    long cardNum = get_long("Number: ");

    int total = 0;
    //%mod will start at second last digit
    long mod = 10;
    int amntOfDigits = 0;
    int firstTwo;
    while(true){
        amntOfDigits++;
        int digit = (cardNum % mod)/(mod/10);
        if(amntOfDigits%2==0){
            digit*=2;
        }

        //adding digits to total
        total += digit%10;
        if(digit>=10){
            total += (digit%100)/10;
        }

        if(cardNum % mod == cardNum){
            if(amntOfDigits%2==0){
                digit/=2;
            }
            firstTwo = (digit*10) + cardNum%(mod/10)/(mod/100);
            break;
        }
        mod*=10;
    }


    if(total%10==0 && amntOfDigits>12){
        if(amntOfDigits == 16){

            if(firstTwo >50 && firstTwo <= 55){
                printf("MASTERCARD\n");
            }else if(firstTwo/10==4){
                printf("VISA\n");
            }
        }else if(amntOfDigits == 15){
            if(firstTwo == 34 || firstTwo == 37){
                printf("AMEX\n");
            }

        }else if(amntOfDigits == 13){
            if(firstTwo/10==4){
                printf("VISA\n");
            }
        }
    }else{
        printf("INVALID\n");
    }
}
