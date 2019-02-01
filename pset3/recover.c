#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(stderr, "Enter only one cli argument: name of forensic image from which to recover JPEGs\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


    int isPic = 0;
    int fileCounter = 0;
    FILE *img = NULL;
    unsigned char buffer[512];
    char fileName[8];

    while(1){
        fread(buffer, 512, 1, inptr);

        if(feof(inptr)){
            break;
        }

        //is it a new image?
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            isPic = 1;

            if(fileCounter>0){
                fclose(img);
            }

            sprintf(fileName, "%03i.jpg", fileCounter);
            img = fopen(fileName, "w");
            fileCounter++;

            }

        if(isPic==1){
            // writing
            fwrite(buffer, 512, 1, img);
        }
    }

    fclose(img);
    fclose(inptr);
    return 0;
}

