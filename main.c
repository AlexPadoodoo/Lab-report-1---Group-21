#include <stdio.h>
#define MAX 100

struct cg{// structure to hold x and y coordinates and mass
    float x,y,mass;
}masses[MAX]; // array for up to 100 weights


// readin will ask the user for the data and store it in the masses array.
// It will then return the number of weights read, or 0 if input is invalid.
int readin( void)
{
    int num, i;    // num = number of weights and i = loop counter

    printf("Enter the number of weights: ");      // Asks for the number of weights
    if (scanf("%d", &num) != 1) {      // scanf returns how many values it reads. 1 is expected so anything else will be an error
        printf("Error: please enter a whole number! \n");
        return 0;   // tells main nothing was read and ends the program
    }

    // The array will only hold weights between 1 and maximum (100) so all other numbers will be rejected.
    if (num < 1 || num > MAX) {
        printf("Error: number of weights must be between 1 and %d! \n", MAX);
        return 0;
    }

    for (i = 0; i < num; i++) {
        printf("Enter x coordinate, y coordinate, and mass for weight %d: ", i + 1);   // repeat once for each weight entered 
        //reads x,y and mass into the structure at position i
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3){
            printf("Error: please enter only three numbers! \n");
            return 0;
        }

    }
        
    return num;  // if everything is fine then return how many weights were stored

}

// computecg works out the centre of gravity and prints it and n_masses is the number of weights stored in the array
void computecg( int n_masses)
{
    float sum_of_xmass = 0, sum_of_ymass = 0, sum_of_mass = 0;   //running totals, starting at 0
    int i;   // loop counter

    // goes through the weights and adds them to the totals
    for (i = 0; i < n_masses; i++) {
        sum_of_xmass += masses[i].x * masses[i].mass;
        sum_of_ymass += masses[i].y * masses[i].mass;
        sum_of_mass += masses[i].mass;
    }

    if (sum_of_mass == 0){
        printf("Error: total mass is zero! \n");
        return;
    }

    // divide each total by the total mass to get the centre of gravity and then prints it
    printf("CoG coordinates are: x = %.2f y = %.2f\n", sum_of_xmass / sum_of_mass, sum_of_ymass / sum_of_mass);

}
int main( void )
{
int number;   // how many weights were read
if((number = readin()) > 0)
computecg(number);
return 0;
}
