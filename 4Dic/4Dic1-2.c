#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    int Nrows = 0;
    int Ncols = 0;
    char line[500];
    char currentChar;
    int numa = 0;
    int numvalids = 1;
    int rowStart = 0;
    int colStart = 0;
    int rowEnd = 0;
    int colEnd = 0;
    int sumNumValids = 0;
    int NumFirstIteration = 0;
    int iteration = 0;


    FILE *file = fopen("4Dic.txt", "r");

    // Check if file opened successfully
    if (file == NULL) { 
        printf("Error opening file\n");
        return 1;
    }   


    //first find Nrows and Ncols
    while (fgets(line, sizeof(line), file) != NULL) {

        Nrows++;
        if(Ncols == 0) {
            Ncols = strlen(line);
            // Remove newline if present
            if(line[Ncols-1] == '\n') Ncols--;
        }
    }

    printf("Nrows: %d, Ncols: %d\n", Nrows, Ncols);

    // Create the MAP (character matrix)
    char **MAP = (char **)malloc(Nrows * sizeof(char *));
    for (int i = 0; i < Nrows; i++) {
        MAP[i] = (char *)malloc(Ncols * sizeof(char));
    }

    // Create the MAP with modifications (character matrix)
    char **MAPmod = (char **)malloc(Nrows * sizeof(char *));
    for (int i = 0; i < Nrows; i++) {
        MAPmod[i] = (char *)malloc(Ncols * sizeof(char));
    }

    // Copy MAP data to file to read the map data again
    rewind(file);
    int row = 0;
    while (fgets(line, sizeof(line), file) != NULL && row < Nrows) {
        int len = strlen(line);
        // Remove newline if present
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        // Copy characters to MAP
        for (int col = 0; col < Ncols && col < len; col++) {
            MAP[row][col] = line[col];
        }
        row++;
    }


    // Print the MAP to verify it was created correctly
    printf("\nMAP created:\n");
    for (int i = 0; i < Nrows; i++) {
        for (int j = 0; j < Ncols; j++) {
            printf("%c", MAP[i][j]);
        }
        printf("\n");
    }

    // Copy MAP to MAPmod for modifications
    for (int i = 0; i < Nrows; i++) {
        for (int j = 0; j < Ncols; j++) {
            MAPmod[i][j] = MAP[i][j];
        }
    }






    while(numvalids >0){

        numvalids = 0;

        // Now process the MAP as needed
        for (int i = 0; i < Nrows; i++) {
            for (int j = 0; j < Ncols; j++) {
                
                // Access each character using MAP[i][j]
                currentChar = MAP[i][j];
                numa = 0;
                // Perform desired operations with currentChar
            
                // check the number of adjacents characters that are '@'
                if(currentChar == '@') {

                    //check boundaries
                    if(i>0){
                        rowStart = i-1;
                    }else{
                        rowStart = i;
                    }
                    if(i<Nrows-1){
                        rowEnd = i+1;
                    }else{
                        rowEnd = i;
                    }
                    if(j>0){
                        colStart = j-1;
                    }else{
                        colStart = j;
                    }
                    if(j<Ncols-1){
                        colEnd = j+1;
                    }else{
                        colEnd = j;
                    }


                    //count '@' adjacents
                    for(int r = rowStart; r <= rowEnd; r++){
                        for(int c = colStart; c <= colEnd; c++){
                            if(r == i && c == j){
                                //skip itself
                            }else{
                                if(MAP[r][c] == '@'){
                                    numa++;
                                }
                            }
                        }
                    }

                    if(numa < 4){
                        MAPmod[i][j] = '.';
                        numvalids++;
                    }


                }

            }
        }


        //when Map modifications are done copy back to MAP
        for (int i = 0; i < Nrows; i++) {
            for (int j = 0; j < Ncols; j++) {
                MAP[i][j] = MAPmod[i][j];
            }
        }   

        if (iteration==0)
        {
            NumFirstIteration = numvalids;
        }
        
        iteration++;
        // Print the New MAP
        printf("\n\n\nMAP iteration: %d, rolls taken in iteration: %d\n", iteration, numvalids);
            for (int i = 0; i < Nrows; i++) {
                for (int j = 0; j < Ncols; j++) {
                    printf("%c", MAP[i][j]);
                }   
            printf("\n");
            }

        sumNumValids += numvalids;


    }


    printf("\nNumber of total rolls taken: %d\n", sumNumValids);
    printf("\nNumber of rolls taken in first iteration: %d\n", NumFirstIteration);
    // Free allocated memory
    for (int i = 0; i < Nrows; i++) {
        free(MAP[i]);
    }
    free(MAP);
    for (int i = 0; i < Nrows; i++) {
        free(MAPmod[i]);
    }
    free(MAPmod);
    fclose(file);
    system("pause");
    return 0;

}