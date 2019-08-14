#include <cs50.h>
#include <stdio.h>

int main(void){
    
    int height;
    
    // Prompt user for pyramid height
    do {           
        height = get_int("Enter the height of the pyramid: ");    
        
    } while (height < 0 || height > 23); // end do while
    
    printf("Height: %i\n", height);
    
    // Loop through the heights
    for (int i = 0; i < height; i++){
           
        // print left side spaces
        for (int j = 0, n = height - i + 1; j < n; j++){
            printf(" ");
        }
        // print left side blocks
        for (int j = 0; j < i + 1; j++){
            printf("#");
        }
        
        // print spaces
        printf("  ");
       
        // print right side blocks
        for (int j = 0; j < i + 1; j++){
            printf("#");
        }
        // print right side spaces
        for (int j = 0; j < height - 1; j++){
            printf(" ");
        }        
        
        printf("\n");
            
    }// end for
    
}// end main
