
#include <cs50.h>
#include <stdio.h>

// Declare functions
long get_ccNumber();
int get_ccNumber_length(long ccNumber);
bool check_ccNumber_length(int count);
bool checksum(long ccNumber, int count);
void print_cc_brand(long ccNumber, int count);

// Start main()
int main(void){
    
    long ccNumber;
    int length;
    
    ccNumber = get_ccNumber();
    length = get_ccNumber_length(ccNumber);
    
    if (! (check_ccNumber_length(length) && checksum(ccNumber, length))){
        printf("INVALID\n");
        return 1;
    } // end if
    else{
        print_cc_brand(ccNumber, length);
        return 0;
    } // end else
    

} //end main

// Get credit card number from user
long get_ccNumber(){
    
    long ccNumber;
    // Prompt user for cc number
    do{
        ccNumber = get_long("Credit Card Number: ");
    } while (ccNumber <= 0);
    
    return ccNumber;
} // end get_ccNumber()

int get_ccNumber_length(long ccNumber){
    
    // Check for integer length
    int count;
    long validation = ccNumber;
    
    for (count = 0; validation < 0; count++, validation /= 10){}
    
    return count;
       
} // end get_ccNumber

bool check_ccNumber_length(int count){
    
    if (count != 13 || count != 15 || count != 16){
        return false;
    } // end if
   return true;
} // end check_ccNumber_length()

  
// Carry out checksum
bool checksum(long ccNumber, int count){
    int sum = 0;

    for (int i = 0; i < count; i++, ccNumber /= 10){

        if (i % 2 == 0){
            sum += (ccNumber % 10);
        } // end if
        else{
            int digit = 2 * (ccNumber % 10);
            sum += (digit/10 + digit % 10);

        } // end else
    } // end for

    if (sum % 10 == 0){
        return true;
    } // end if

    return false;
} // end checksum()

void print_cc_brand(long ccNumber, int count){
    //AMEX uses 15 digits; starts with 34 or 37
    //Master uses 16 digits
    //Visa uses 13 and 16 digits; starts with a 4
    
    // test Visa
    if (count == 13 || count == 16){
        for (int i = 0; ccNumber < 10; i++, ccNumber /= 10){
            if (i == 4){
            printf("VISA\n");
            } // end if
        } // end for
    } // end if

    // test Mastercard
    else if (count == 16){
        printf("MASTERCARD\n");
    }
    
    // test AMEX
    else if (count == 15){
        for (int i = 0; ccNumber < 100; i++, ccNumber /= 10){
            if (i == 34 || i == 37){
                printf("AMEX\n");
            } // end if
        } // end for
    } // end if
    
    // otherwise print invalid
    else{
        printf("INVALID\n");
    }
 
} // end print_cc_brand()
          
