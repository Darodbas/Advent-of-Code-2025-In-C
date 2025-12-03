#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 12

int main() {

    char line[500];
    int maxv[N];
    int pv[N];
    int n = 0;
    int length = 0;
    long long int combined_number = 0;
    long long int sum = 0;
    int j = 0;

    FILE *file = fopen("3Dic.txt", "r");


    // Check if file opened successfully
    if (file == NULL) {
    printf("Error opening file\n");
    return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {


        for (int i = 0; i < N; i++) {
            maxv[i] = 0;  // Reset all N maxs for each line
            pv[i] = 0; // Reset all N positions for each line
        }
        
        length = strlen(line);
        // Remove newline if present
        if(line[length-1] == '\n') length--;


        printf("Line: %s", line);


        while (j<N)
        {
            if(j>0) {
                for(int i = pv[j-1]+1; i < length-N+j+1; i++) {
                
                n = line[i] - '0';  // Convert char to digit

                if(n > maxv[j]){
                    maxv[j] = n;
                    pv[j] = i;
                }
                }
            }
            else
            {
                for(int i = 0; i < length-N; i++) {
                
                n = line[i] - '0';  // Convert char to digit

                if(n > maxv[j]){
                    maxv[j] = n;
                    pv[j] = i;
                }
                }
            }

            printf("iteration %d: max: %d at position %d\n", j+1, maxv[j], pv[j]);
            j++;
        }
        

        //Creates the number formed by the maximum digits and prints it
        for (int i = 0; i < N; i++)
        {
            combined_number = combined_number + pow(10, N-1-i) * maxv[i];
        }
        
        sum += combined_number;

        printf("\nCombined number: %lld\n\n", combined_number);

        j = 0;
        combined_number = 0;

    }

    printf("\nFinal Sum: %lld\n", sum);

    return 0;

}
