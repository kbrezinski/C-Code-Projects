#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    
    // check user inputted the correct number of args
    if (argc != 2 || !isdigit(argv[1][0])){
        printf("Usage: ./ceasar key\n");
        return 1;     
    }
    // store input argument as the cipher
    int cipher = atoi(argv[1]);
    
    // prompt user for their input
    string word = get_string("plaintext: ");
    
    // iterate over the string char by char
    for (int i = 0, n = strlen(word); i < n; i++){
        // check if its in the alphabet
        if (word[i] >= 'a' && word[i] <= 'z'){
            if (word[i] + cipher > 'z'){
                word[i] = word[i] + cipher - 26;
            }
            else{
                word[i] = word[i] + cipher;
            }        
        } // end if
        else if (word[i] >= 'A' && word[i] <= 'Z'){
            if (word[i] + cipher > 'Z'){
                word[i] = word[i] + cipher - 26;
            }
            else{
                word[i] = word[i] + cipher;
            }    
        } // end if     
    } // end for
    
    // print ciphertext
    printf("ciphertext: %s\n", word);
    
    return 0;

} // end main
