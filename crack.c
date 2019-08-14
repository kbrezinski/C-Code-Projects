#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    // test the number of input args in the cmd line, with 1 being the default
    if (argc != 2){
        printf("Invalid command\n");
        return 1;
    }
    
    // create a string that is looped through later on, comprised of 53 items
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 53;
    
    // takes the input as the hash
    string hash = argv[1];
    
    // creates a hash 3 chars long
    char salt[3];
    // copy first two bytes to the salt
    memcpy(salt, hash, 2);
    // add the null character to the end of the salt
    salt[2] = '\0';
    
    // create the possible candidate sol'n and init it to all nulls
    char key_cand[6] = "\0\0\0\0\0\0";
    
    // later terms are init to /0 so that algo can go through shorter
    // passwords first
    for (int fifth = 0; fifth < count; fifth++){
        for (int fourth = 0; fourth < count; fourth++){
            for (int third = 0; third < count; third++){
                for (int second = 0; second < count; second++){
                    for (int first = 0; first < count; first++){
                        key_cand[0]=letters[first];
                        key_cand[1]=letters[second];
                        key_cand[2]=letters[third];
                        key_cand[3]=letters[fourth];
                        key_cand[4]=letters[fifth];
                        
                        // if the strings are equal strcmp will return 0
                        if (strcmp(crypt(key_cand, salt), hash) == 0){
                            printf("%s\n", key_cand);
                            return 0;
                        }
                    }
                }
            }
        }
        
    }
        
    
    

}
