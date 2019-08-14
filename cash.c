
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    
    float change;
    
    // prompt use for a positive float
    do {
         change = get_float("Change owed: ");
    
    } while (change <= 0);
    
    // convert change in dollars to cents
    int cents = round(change * 100);
    int coins;
    
    // distribute change
    int quaters = cents / 25;
    cents -= (quaters * 25);
    
    int dimes = cents / 10;
    cents -= (dimes * 10);
    
    int nickels = cents / 5;
    cents -= (nickels * 5);
    
    int pennies = cents;
    
    coins = quaters + dimes + nickels + pennies;
    
    printf("%i\n", coins);
     
    return 0;
    
} // end main
