/* My name is Leonard Carpenter and this program will take user inputted information regarding how the user is doing in their studies.
   Depending on what they answer for the series of questions, the program will either output "You need to study!" or "Do something fun"*/
#include <stdio.h>
#include <string.h>

int main(){

char userInp1[20];
char userInp2[20];
char userInp3[20];
char userInp4[20];
char userInp5[20];
char userInp6[20];

printf("What are you worried about?");
scanf("%s", userInp1);

printf("\n");

if (strcmp(userInp1,"project")==0){
    printf("What kind?");
    scanf("%s", userInp2);
        if (strcmp(userInp2,"huge")==0){
            printf("Due soon?");
            scanf("%s", userInp3);
                if (strcmp(userInp3,"tomorrow")==0){
                    printf("You need to study!");
                    return 0;
                }
                else if (strcmp(userInp3,"this-week")==0){
                    printf("Almost finished?");
                    scanf("%s", userInp4);
                        if (strcmp(userInp4,"yes")==0){
                            printf("Do something fun!");
                            return 0;
                        }
                        else if (strcmp(userInp4,"no")==0){
                            printf("Have you started?");
                            scanf("%s", userInp5);
                                if (strcmp(userInp5,"no")==0){
                                printf("You need to study!");
                                return 0;
                                }
                                if (strcmp(userInp5,"yes")==0){
                                printf("Do something fun!");
                                return 0;
                                }
                        }
                }
                else if (strcmp(userInp3,"next-week")==0){
                    printf("Busy weekend?");
                    scanf("%s", userInp4);
                        if (strcmp(userInp4,"yes")==0){
                            printf("You need to study!");
                            return 0;
                        }
                        else if (strcmp(userInp4,"no")==0){
                            printf("Do something fun!");
                            return 0;
                        }
                }
        }
        else if (strcmp(userInp2,"normal")==0){
            printf("Can you drop one?");
            scanf("%s", userInp3);
                if (strcmp(userInp3,"no")==0){
                    printf("You need to study!");
                    return 0;
                }
                else if (strcmp(userInp3,"yes")==0){
                    printf("Already dropped one?");
                    scanf("%s", userInp5);
                        if (strcmp(userInp5, "no")==0){
                            printf("Do something fun!");
                            return 0;
                        }
                        else if (strcmp(userInp5, "yes")==0){
                            printf("You need to study!");
                            return 0;
                        }
                }
        }
        else if (strcmp(userInp2,"extra-credit")==0){
            printf("Course grade?");
            scanf("%s", userInp3);
                if (strcmp(userInp3,"great")==0){
                    printf("Do something fun!");
                    return 0;
                }
                else if (strcmp(userInp3,"not-great")==0){
                    printf("You need to study!");
                    return 0;
                }
        }
}
else if (strcmp(userInp1,"test")==0){
    printf("How big a test?");
    scanf("%s", userInp2);
        if (strcmp(userInp2,"quiz")==0){
            printf("Pass the last quiz?");
            scanf("%s", userInp3);
                if (strcmp(userInp3,"no")==0){
                    printf("You need to study!");
                    return 0;
                }
                else if (strcmp(userInp3,"yes")==0){
                    printf("Pass easily?");
                    scanf("%s", userInp4);
                        if (strcmp(userInp4,"yes")==0){
                            printf("Do something fun!");
                            return 0;
                        }
                        if (strcmp(userInp4,"no")==0){
                            printf("You need to study!");
                            return 0;
                        }
                }
        }
        else if (strcmp(userInp2,"midterm")==0){
            printf("A class in major?");
            scanf("%s", userInp3);
                if (strcmp(userInp3,"no")==0){
                    printf("Easy class?");
                    scanf("%s", userInp4);
                        if (strcmp(userInp4, "yes")==0){
                            printf("Do something fun!");
                            return 0;
                        }
                        else if (strcmp(userInp4, "no")==0){
                            printf("You need to study!");
                            return 0;
                        }


                }
                else if (strcmp(userInp3,"yes")==0){
                    printf("Required class?");
                    scanf("%s", userInp4);
                        if (strcmp(userInp4,"no")==0){
                            printf("Doing well?");
                            scanf("%s",userInp5);
                                if (strcmp(userInp5, "yes")==0){
                                    printf("Do something fun!");
                                    return 0;
                                }
                                else if (strcmp(userInp5, "no")==0){
                                    printf("You need to study!");
                                    return 0;
                                }
                        }
                        else if (strcmp(userInp4,"yes")==0){
                            printf("Taken it before?");
                            scanf("%s",userInp5);
                                if (strcmp(userInp5,"yes")==0){
                                    printf("You need to study!");
                                    return 0;
                                }
                                else if (strcmp(userInp5,"no")==0){
                                    printf("Are you ready?");
                                    scanf("%s", userInp6);
                                        if (strcmp(userInp6,"no")==0){
                                            printf("You need to study!");
                                            return 0;
                                        }
                                        else if (strcmp(userInp6,"yes")==0){
                                            printf("Do something fun!");
                                            return 0;
                                        }
                                }
                }
        }
}
}







return 0;
}