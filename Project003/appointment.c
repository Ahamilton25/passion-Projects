/* My name is Leonard Carpenter and I have created a program that takes a user's input and finds their name, appointment time, and where the appointment is located at and outputs these three things back in 
in a sentence.*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){



char userTxt[5000];
char chName[50] = "<not provided>";
char chBuilding[50] = "<not provided>";
char chMonthDay[50] = "<not provided>";
char chTime[50] = "<not provided>";



char* line = fgets(userTxt, sizeof(userTxt), stdin);

while (line != NULL){
    if (feof(stdin)) break;

    char *word = strtok(line, " "); //May not be correct

    for (int i = 0; i < strlen(word); i++){ 
        //Name
        if (isupper(word[i])){
            for (int j = i+1; word[j] != ' '; j++){
                if (islower(word[j])){
                    for (int a = i; word[a] != '\0'; a++){
                        int k = 0;
                        chName[k] = word[a];
                    }
                    if (isalpha(chName)){
                        return chName;
                    }
                    else {
                        strcpy(chName, "<not provided>");
                    }
                }
            }
        }

        //MonthDay
        else if ((userTxt[i] >= '0' && userTxt[i] <= '9') && (userTxt[i+1] >= '0'&& userTxt[i+1] <= '9') && (userTxt[i+2] == '-')){
            for(int j = 0; userTxt[j]!= ' '; j++){
                 chMonthDay[j] = userTxt[j+i];
            }
        }

        //Time
        else if ((userTxt[i] >= '1' && userTxt[i] <= '9') && userTxt[i-1] != '0') {
            if((userTxt[i+1] == 'a') || (userTxt[i+1] == 'p')){
                if(userTxt[i+2] == 'm'){
                    for(int j = 0; userTxt[j]!= ' '; j++){
                        chTime[j] = userTxt[j+i];
                    }
                }
            }
            else if ((userTxt[i+1] >= '0' && userTxt[i+1] <= '9')) { 
                if((userTxt[i+2] == 'a') || (userTxt[i+2] == 'p')){
                    if(userTxt[i+3] == 'm'){
                        for(int j = 0; userTxt[j]!= ' '; j++){
                            chTime[j] = userTxt[j+i];
                        }
                    }
                }
            }
        }



        //Building
        else if ((userTxt[i] >= 'A' && userTxt[i] <= 'Z') && (userTxt[i+1] >= 'A'&& userTxt[i+1] <= 'Z') && (userTxt[i+2] >= 'A'&& userTxt[i+2] <= 'Z')){
            for (int j = 0; userTxt[j] != ' '; j++){
                chBuilding[j] = userTxt[j+i-1];
                if (strlen(chBuilding) < 6){
                    strcpy(chBuilding,"<not provided>");
                }
            }
        }
















    }

    word = strtok(NULL, " ");
}

printf("Appointment with %s is on %s at %s in %s\n", chName, chMonthDay, chTime, chBuilding);






    return 0;
}