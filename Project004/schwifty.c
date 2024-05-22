#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char *argv[]) {
    if (argc !=3){
        printf("Invalid number of arguments\n");
        return 0;
    }

    FILE *fp ;
    fp = fopen(argv[1], "r"); 
    if(fp == NULL){
       printf("Could not open file '%s'\n", argv[1]);
       return 0;      
    }

    for (int i = 0; argv[2][i] != '\0'; i++){
        if (argv[2][i] != 'L' || (argv[2][i] != 'R' || (argv[2][i] != 'I' || (argv[2][i] != 'D'){
            printf( "You threw off my schwiftiness with schwifty '%c'!", argv[2][i]);
        }
    }

    char fileword[101];

    while(fgets(fileword, 99, fp){
        char *word = strtok(fileword, "\n");

        while(word != NULL){
            printf("")
        }
    }

    fclose(fp);

   return 0;
}

void left(char word[]) {
   char leftch = word[0];
   int len = strlen(word);
   for (int i = 0; i < len - 1; i++){
       word[i] = word[i+1];
   }

}

void right(char word[]) {
   
}

void inc(char word[]) {
   
}

void dec(char word[]) {
   
}
