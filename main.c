#include <stdio.h>
#define MAX 100

struct cg{// structure to hold x and y coordinates and mass
    float x,y,mass;
}masses[MAX];

int readin( void)
{
    int num, i;    

    printf("Enter the number of weights: ");    
    if (scanf("%d", &num) != 1) {
        printf("Error: please enter a whole number! \n");
        return 0;
    }

    if (num < 1 || num > MAX) {
        printf("Error: number of weights must be between 1 and %d! \n", MAX);
        return 0;
    }

    for (i = 0; i < num; i++) {
        printf("Enter x coordinate, y coordinate, and mass for weight %d: ", i + 1);
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3){
            printf("Error: please enter only three numbers! \n");
            return 0;
        }

    }
        
    return num;

}
void computecg( int n_masses)
{
    float sum_of_xmass = 0, sum_of_ymass = 0, sum_of_mass = 0;
    int i;

    for (i = 0; i < n_masses; i++) {
        sum_of_xmass += masses[i].x * masses[i].mass;
        sum_of_ymass += masses[i].y * masses[i].mass;
        sum_of_mass += masses[i].mass;
    }

    if (sum_of_mass == 0){
        printf("Error: total mass is zero! \n");
        return 0;
    }

    printf("CoG coordinates are: x = %.2f y = %.2f\n", sum_of_xmass / sum_of_mass, sum_of_ymass / sum_of_mass);

}
int main( void )
{
int number;
if((number = readin()) > 0)
computecg(number);
return 0;
}
