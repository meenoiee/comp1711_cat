#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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


int main() 
{

    FILE *file = fopen("FitnessData_2023.csv", "r");

    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");

    char option;
    scanf(" %c", &option);

    FITNESS_DATA fitness [10000000];
    int linesize = 200;
    char inputdata[30];
    int count=0;
    int c=0;

    while (fgets(inputdata, linesize, file) != NULL) 
    {
        tokeniseRecord(inputdata, ",", fitness[c].date, fitness[c].time, fitness[c].charsteps);

        if (strlen(fitness[c].date) > 0 && strlen(fitness[c].time) > 0 && strlen(fitness[c].charsteps) > 0) 
        {
            count++;
            fitness[c].steps = atoi(fitness[c].charsteps) ;
        }

        c++;
    }

    switch (option) 
    {
        case 'A':
            printf("Input filename: FitnessData_2023.csv");
            if(fgets(inputdata, linesize, file) == NULL)
            {
                printf("Error: Could not find or open the file.");
                return 1;
            }
            break;

        case 'B':
            printf("Total records: %d",count);
            break;

        case 'C': 

            int minsteps = fitness[0].steps;
            int minindex = 0;

            for (int i = 0; i < count; i++) 
            {
                if (fitness[i].steps < minsteps) 
                {
                    minsteps = fitness[i].steps;
                    minindex = i;
                }
            }

            printf("Fewest steps: %s %s",fitness[minindex].date,fitness[minindex].time);

            break;

        case 'D':
            int maxsteps = fitness[0].steps;
            int maxindex = 0;

            for (int i = 0; i < count; i++) 
            {
                if (fitness[i].steps > maxsteps) 
                {
                    maxsteps = fitness[i].steps;
                    maxindex = i;
                }
            }

            printf("Largest steps: %s %s",fitness[maxindex].date,fitness[maxindex].time);

            break;

        case 'E':
            int meansteps;
            float totalsteps=0;

            for(int i = 0; i < count; i++)
            {
                totalsteps = totalsteps + fitness[i].steps; 
            }

            meansteps = totalsteps/count ;
            
            break;

        case 'F':
            findLongestPeriodAbove500(records, numRecords);
            break;

        case 'Q':
            printf("Program returns 0 & exits\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
    }
}  
    

