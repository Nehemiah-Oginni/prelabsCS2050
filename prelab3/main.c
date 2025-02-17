#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strlen() returns length of string
//strcpy(A,B) coppies B into A
//strcat(A,B) adds B to the end of A

// Global variables for storing ship information
char name[50];
typedef struct {
    char name[50];
    float speed; // Speed in light-years per hour
} Spaceship;

float speed;

// Function prototypes
// Loads fleet data from a file and returns a 2D array of Spaceships
Spaceship** load_fleet(const char* filename);
// Calculates and returns the class with the highest average speed
char class_with_highest_average_speed(Spaceship** fleet);
// Frees all dynamically allocated memory for the fleet
void free_fleet(Spaceship** fleet);

int main(void)
{
    // Load the fleet data from ships.txt and get the class with highest average speed
    Spaceship** fleet = load_fleet("ships.txt");
    char winningClass = class_with_highest_average_speed(fleet);
    printf("winning class is %c !!!!!!!!\n", winningClass);
    free_fleet(fleet);
}

Spaceship** load_fleet(const char* filename)
{
    FILE *fp;
    fp = NULL;

    // Open a file in read mode
    fp = fopen(filename, "r");

    // Return NULL if file opening fails
    if(fp == NULL)
    {
        return NULL;
    }

    // Arrays to store the number of ships in each class
    int classes[5];    // Stores current count of ships
    int bigLetter[5];  // Stores total capacity for each class

    // Read the first 5 numbers from file (number of ships in each class)
    fscanf(fp,"%d %d %d %d %d",&classes[0], &classes[1], &classes[2], &classes[3], &classes[4]);
    
    // Store the original counts for later use
    for(int i=0; i<5; i++)
    {
        bigLetter[i] = classes[i];
    }

    // Dynamic allocation of 2D array for storing fleet data
    // Format: [metadata][E-class ships][C-class ships][M-class ships][D-class ships][V-class ships]
    Spaceship** array2D = malloc(sizeof(int) + sizeof(Spaceship*) * 5);

    // Store number of rows (5) in the metadata section
    ((int*)array2D)[0] = 5;
    
    // Move pointer past metadata section
    (int*)array2D++;

    // Allocate memory for each class of ships
    for(int i=0; i<5; i++)
    {
        // Allocate space for metadata (count) and ships of this class
        array2D[i] = malloc(sizeof(int) + sizeof(Spaceship) * classes[i]);
        // Store number of ships in this class
        ((int*) array2D[i])[0] = classes[i];
        // Move pointer past metadata
        array2D[i]++;
    }

    // Temporary storage for ship data being read
    Spaceship my_ship;
    char classHold;  // Stores the class of the current ship

    // Read and store all ships from the file
    for(int i=0; !feof(fp); i++)
    {
        // Read ship data: name, class, and speed
        fscanf(fp,"%s %c %f", my_ship.name, &classHold, &my_ship.speed);

        // Store ship in appropriate class array based on its class
        // Decrement counter to fill from end to beginning
        switch(classHold)
        {
            case 'E':
                strcpy(array2D[0][classes[0]-1].name, my_ship.name);
                array2D[0][classes[0]-1].speed = my_ship.speed;
                classes[0] = classes[0] - 1;
                break;
            case 'C':
                strcpy(array2D[1][classes[1]-1].name, my_ship.name);
                array2D[1][classes[1]-1].speed = my_ship.speed;
                classes[1] = classes[1] - 1;
                break;
            case 'M':
                strcpy(array2D[2][classes[2]-1].name, my_ship.name);
                array2D[2][classes[2]-1].speed = my_ship.speed;
                classes[2] = classes[2] - 1;
                break;
            case 'D':
                strcpy(array2D[3][classes[3]-1].name, my_ship.name);
                array2D[3][classes[3]-1].speed = my_ship.speed;
                classes[3] = classes[3] - 1;
                break;
            case 'V':
                strcpy(array2D[4][classes[4]-1].name, my_ship.name);
                array2D[4][classes[4]-1].speed = my_ship.speed;
                classes[4] = classes[4] - 1;
                break;
        }
    }

    // Debug print: Display all ships and their speeds
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<bigLetter[i]; j++)
        {
            printf("%s %f\n", array2D[i][j].name, array2D[i][j].speed);
            printf("bigLetter is %d\n\n", bigLetter[i]);
        }
    }

    return array2D;
}

char class_with_highest_average_speed(Spaceship** fleet)
{
    // Arrays to store speed calculations for each class
    float rowSpeedSum[5];    // Sum of speeds for each class
    float avgRowSpeed[5];    // Average speed for each class
    float maxSpeed = 0;      // Tracks highest average speed found
    int winningRow = 0;      // Index of class with highest average speed

    // Calculate average speed for each class
    for(int i=0; i<5; i++)
    {
        // Sum up speeds for current class
        for(int j=0; j< *(((int*)fleet[i])-1); j++)
        {
            rowSpeedSum[i] += fleet[i][j].speed; printf("\n%d\n", *(((int*)fleet[i])-1));
        }
        // Calculate average speed for current class
        avgRowSpeed[i] = rowSpeedSum[i] / *(((int*)fleet[i])-1);

        // Update maximum speed if current class has higher average
        if(maxSpeed < avgRowSpeed[i])
        {
            maxSpeed = avgRowSpeed[i];
            winningRow = i;
        }

       
    }
    winningRow--;

    // Convert winning row index to class letter
    char winningClass = ' ';
    switch(winningRow)
    {
        case 0:
            winningClass = 'E';
            break;
        case 1:
            winningClass = 'C';
            break;
        case 2:
            winningClass = 'M';
            break;
        case 3:
            winningClass = 'D';
            break;
        case 4:
            winningClass = 'v';
            break;
    }

    return winningClass;
}

void free_fleet(Spaceship** fleet)
{
    // Get pointer to metadata (number of rows)
    int* p = (((int*)fleet)-1);
    
    // Free memory for each class array
    for(int i=0; i < *p; i++)  // Changed from *p-1 to *p
    {
        free(((int*)fleet[i])-1);  // Cast to int* before moving back
    }
    // Free the main array
    free(p);
}