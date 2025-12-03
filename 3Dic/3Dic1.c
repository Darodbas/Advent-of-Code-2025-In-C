#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char line[500];
    int max1 = 0;
    int max2 = 0;
    int p1 = 0;
    int n = 0;
    int length = 0;
    int combined_number = 0;
    int sum = 0;

    FILE *file = fopen("3Dic.txt", "r");


    // Check if file opened successfully
    if (file == NULL) {
    printf("Error opening file\n");
    return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {

        max1 = 0;  // Reset max for each line
        max2 = 0;  // Reset second max for each line
        p1 = 0; // Reset position for each line
        
        length = strlen(line);
        // Remove newline if present
        if(line[length-1] == '\n') length--;

        // Finds the maximum digit and its position in the line except the last digit
        for(int i = 0; i < length-1; i++) {
            
            n = line[i] - '0';  // Convert char to digit

            if(n > max1){
                max1 = n;
                p1 = i;
            }
        }

        // finds the maximum digit after the position of the first maximum digit
        for(int i = p1+1; i< length; i++){
            
            n = line[i] - '0';  // Convert char to digit

            if(n > max2){
                max2 = n;
            }

        }

        //Creates the number formed by the two maximum digits and prints it
        combined_number = max1 * 10 + max2;
        sum += combined_number;

        printf("Line: %s, combined number: %d, Sum: %d\n", line, combined_number, sum);
    }

    printf("\nFinal Sum: %d\n", sum);


    return 0;
}