#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct data{
	char date[11];
	char time[6];
	int steps;
    char charsteps[10];
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

    FILE *file = fopen("FitnessData_2023.csv", "r");

    FITNESS_DATA fitness [100000];
    int linesize = 200;
    char inputdata[30];
    int i=0;
    int count=0;

    

    while (fgets(inputdata, linesize, file) != NULL) 
    {
        tokeniseRecord(inputdata, ",", fitness[i].date, fitness[i].time, fitness[i].charsteps);

        if (strlen(fitness[i].date) > 0 && strlen(fitness[i].time) > 0 && strlen(fitness[i].charsteps) > 0) 
        {
            count++;
            fitness[i].steps = atoi(fitness[i].charsteps) ;
        }

        i++;
    }


    printf("Number of records in file: %d\n",count);
    
    int validCount = 0;
    for (int j = 0; j < count && validCount < 3; j++) 
    {
        if (strlen(fitness[j].date) > 0 && strlen(fitness[j].time) > 0 && strlen(fitness[j].charsteps) > 0) 
        {
            printf("%s/%s/%d\n", fitness[j].date, fitness[j].time, fitness[j].steps);
            validCount++;
        }
    }

    fclose(file);
    
    return 0;
}