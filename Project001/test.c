#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

//main function with command line args
int main(int argc,char *argv[]) {
   FILE *rfp;//read file pointer
   char word[100];//maximum word length 100
   char ch;//schwifty char
  
   if(argc!=3)//not exactly 3 args
   {
       printf("\nInvalid number of arguments");
       return 1; //error code 1
   }
  
   rfp=fopen(argv[1],"r");//open file for reading
   if(rfp==NULL)//file open failed
       printf("\nCould not open file %s",argv[1]);
      
   if(argv[2][0]!='L' && argv[2][0]!='R' && argv[2][0]!='I' && argv[2][0]!='D') //if not valid schwities
       printf("\nYou threw off my schwiftiness with schwifty %c!",argv[2][0]);
  
  
   //if all arguments are fine
   ch=argv[2][0]; //get schwifty character to ch
  
   fgets(word,100,rfp); //read 1st word from file
   while(!feof(rfp)) //read until end of file
   {
       if(word[strlen(word)-1]=='\n') //when new line break is found
           word[strlen(word)-1]=0; //remove it
          
       switch(ch) //compare character ie L,R,I or D
       {
           case 'L':
                       left(word);
                       break;
           case 'R':
                       right(word);
                       break;
           case 'I':
                       inc(word);
                       break;
           case 'D':
                       dec(word);
                       break;
      
       }
       printf("%s\n",word);//print after schwifty
      
       fgets(word,100,rfp); //read next word from file
   }
          

return 0;
}

void left(char word[])
{
       char lch=word[0];//get left most character
       int i;//required for each character traversal
      
       for(i=0;word[i]!='\0';i++)//traverse upto null character
           word[i]=word[i+1];//left shift
       word[i-1]=lch;//finally first character to last
       word[i]='\0';//set back null character
}

void right(char word[]) {
       char rch=word[strlen(word)-1];//get right most character
       int i;//required for each character traversal
      
       for(i=strlen(word)-1;i>0;i--)//traverse upto 2nd character(ie idx=1)
           word[i]=word[i-1];//right shift
       word[0]=rch;//finally last character to first
       word[strlen(word)]='\0';//set back null character
}

void inc(char word[]) {
   int i;//required for each character traversal
      
       for(i=0;word[i]!='\0';i++)//traverse upto null character
       {
              
           if(isalpha(word[i])) //when alphabet
           {
               if(word[i]=='Z' ||word[i]=='z')//when last character 'z'
                   word[i]=word[i]-25;// set back to 'A' or 'a'
               else if((word[i]>='a' && word[i]<'z') || (word[i]>='A' && word[i]<'Z')) //between A to Y(small or caps)
                   word[i]=word[i]+1;//increment one character
           }
          
           else if(isdigit(word[i])) //when digit
           {
               if(word[i]=='9')//when last character '9'
                   word[i]=word[i]-9;// set back to 0
               else if((word[i]>='0' && word[i]<'9')) //between 0 to 8
                   word[i]=word[i]+1;//increment one character(ie digit)
           }
           //others no change
       }
}

void dec(char word[]) {
       int i;//required for each character traversal
      
       for(i=0;word[i]!='\0';i++)//traverse upto null character
       {
           if(isalpha(word[i])) //when alphabet
           {
               if(word[i]=='A' ||word[i]=='a')//when first character 'a'
                   word[i]=word[i]+25;// set back to 'Z' or 'Z'
               else if((word[i]>'a' && word[i]<='z') || (word[i]>'A' && word[i]<='Z')) //between B to Z(small or caps)
                   word[i]=word[i]-1;//decrement one character
           }
           else if(isdigit(word[i])) //when digit
           {
              
               if(word[i]=='0')//when first character '0'
                   word[i]=word[i]+9;// set back to 9
               else if((word[i]>'0' && word[i]<='9')) //between 1 to 9
                   word[i]=word[i]-1;//increment one character(ie digit)
           }
           //others no change
       }

} 