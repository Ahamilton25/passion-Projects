#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{
    FILE* fp;
    fp = fopen(filename, "r");
        if (fp == NULL){
            return NULL;
        }
        ImagePPM* PPM = (ImagePPM*)malloc(sizeof(ImagePPM));
        fscanf(fp,"%s",PPM->magic);
        fscanf(fp,"%d",PPM->numRows);
        fscanf(fp,"%d",PPM->numCols);
        fscanf(fp,"%d",PPM->maxVal);
                    
                    // 
        PPM->pixels = (Pixel**)malloc(sizeof(Pixel*) * PPM->numRows);
        for (int q = 0; q < PPM->numRows; q++){
            PPM->pixels[q] = (Pixel*)malloc(sizeof(Pixel) * PPM->numCols);   
        }

        for (int q = 0; q < PPM->numRows; q++){
            for (int w = 0; w < PPM->numCols; w++);
                fscanf(fp, "%d%d%d", &PPM->Pixel[q][w].red, &PPM->Pixel[q][w].green, &PPM->Pixel[q][w].blue);
        }
    fclose(fp);
    return PPM;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "w");
        if (fp == NULL){
            return 0;
        }

        fprintf(fp, "%s\n", PPM->magic);
        fprintf(fp, "%d %d\n", PPM->numRows, PPM->numCols);
        fprintf(fp, "%d\n", PPM->maxVal);

    return 1;
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    return;
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename)
{
    return NULL;
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{
    return 0;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
    return;
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{
    return NULL;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    return NULL;
}
