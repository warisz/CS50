#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do{
        height = get_int("Height: ");
    }
    while(height <= 0 || height > 8);

    printf("Stored: %i\n", height);

    for(int i=0; i<height; i++){
        for(int j=0; j<height-(i+1); j++){
            printf(" ");
        }
        for(int k=0; k<i+1; k++){
            printf("#");
        }
        printf("\n");
    }
}
