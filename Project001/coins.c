#include <stdio.h>

int main(){
    
int twenties;
int tens;
int fives;
int ones;
int totalCash;
double coinHeight;
double coinWeight;

printf("Enter the number of $20s you have:\n");
scanf("%d", &twenties);
printf("Enter the number of $10s you have:\n");
scanf("%d", &tens);
printf("Enter the number of $5s you have:\n");
scanf("%d", &fives);
printf("Enter the number of $1s you have:\n");
scanf("%d", &ones);

totalCash = (twenties*20) + (tens*10) + (fives*5) + (ones*1);
printf("You have $%d in total cash.\n", totalCash);

coinHeight = totalCash * 0.0787402;
printf("Your stack of coins is %0.2f inches high.\n", coinHeight);

coinWeight = totalCash * 0.0178574;
printf("Your stack of coins weighs %0.2f pounds.\n", coinWeight);

    return 0;
}