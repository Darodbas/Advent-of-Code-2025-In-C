#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

int n = 50;
int cont = 0;
char line[256];
char direction = 'M';
int num = 0;
int i = 0;

  FILE *file = fopen("1Dic.txt", "r");
  
  // Check if file opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }



  // Read each line from the file
  while (fgets(line, sizeof(line), file) != NULL) {
    // Remove newline character if present
    line[strcspn(line, "\n")] = 0;
    
    // Extract first character and the following number
    char direction = line[0];
    int num = atoi(&line[1]);

    if(direction == 'L'){

      for( i=0; i<num; i++ ){
        n -= 1;

        if(n<0){
          n = 100 + n;
        }

        if(n==0){
          cont++;
        }

      }

    }

    else{

      for( i=0; i<num; i++ ){
        n += 1;

        if(n>99){
          n = n % 100;
        }

        if(n==0){
          cont++;
        }

      }
      
    }

    printf("Line: %s \t| Direction: %c \t| N: %d \t| Cont: %d\n", line, direction, n, cont);

  }
  
  fclose(file);
  printf("\n\nTotal: %d\n", cont);
  return 0;
}
