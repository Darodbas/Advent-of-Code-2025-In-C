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

        // Check if the number is made of a sequence repeated at least twice
        int is_invalid = 0;
        
        // Try all possible sequence lengths (1 to digits/2)
        for(int seq_len = 1; seq_len <= digits / 2; seq_len++){
            if(digits % seq_len == 0){  // sequence must divide evenly into total digits
                int repeats = digits / seq_len;
                
                // Extract the sequence
                strncpy(first_half, istr, seq_len);
                first_half[seq_len] = '\0';
                
                // Check if this sequence repeats for all positions
                int is_repeated = 1;
                for(int pos = 0; pos < digits; pos++){
                    if(istr[pos] != first_half[pos % seq_len]){
                        is_repeated = 0;
                        break;
                    }
                }
                
                // If we found a valid repeated sequence
                if(is_repeated && repeats >= 2){
                    is_invalid = 1;
                    counter += i;
                    printf("Found invalid ID: %lld (sequence: %s, repeated %d times)\n", i, first_half, repeats);
                    break;
                }
            }
        }
    }
  }

  fclose(file);
 
  printf("\n\nTotal found: %lld\n", counter);
  return 0;


}