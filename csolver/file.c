#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void open_file(char* filename)
{
    FILE* fptr;
    fptr = fopen(filename,"r");
    char ch;

    if (NULL == fptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are \n");
    char line[256];
    while (fgets(line, sizeof(line), fptr)) 
    {
        if (strcmp(line, "#puzzle\n") == 0)
        {
            // printf("Hi");
            for(int i=0; i<10; i++)
            {
                fgets(line, sizeof(line), fptr);
                printf("%s", line);
            }
        }
        // Print each line to the standard output.
        
    }
    
    fclose(fptr);
}