#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   

char line[500];
long long int n1 = 0;
long long int n2 = 0;
int digits = 0;
int half = 0;
char istr[500];
char first_half[500] = "\0";
char second_half[500] = "\0";
long long int counter = 0;

FILE *file = fopen("2Dic.txt", "r");
  
  // Check if file opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read each line from the file
  while (fgets(line, sizeof(line), file) != NULL) {

    // Store the two numbers separated by a hyphen
    sscanf(line, "%lld-%lld", &n1, &n2);

    printf("\nLine: %s   n1: %lld, n2: %lld\n", line, n1, n2);

    // loop from n1 to n2
    for(long long int i = n1; i <= n2; i++){

       sprintf(istr, "%lld", i);
       digits = strlen(istr);

        //only if even number of digits
        if(digits % 2 == 0){
            half = digits / 2;
            
            // Extract first half
            strncpy(first_half, istr, half);
            first_half[half] = '\0';
            
            // Extract second half
            strncpy(second_half, istr + half, half);
            second_half[half] = '\0';

            // Compare the two halves
            if(strcmp(first_half, second_half) == 0){

                counter += i;
                printf("Found: %lld (first: %s, second: %s)    Counter: %lld\n", i, first_half, second_half, counter);
                
            }
        }
    }
  }

  fclose(file);
 
  printf("\n\nTotal found: %lld\n", counter);
  return 0;


}