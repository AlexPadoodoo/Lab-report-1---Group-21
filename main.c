#include <stdio.h>
#define MAX 100

struct cg{// structure to hold x and y coordinates and mass
    float x,y,mass;
}masses[MAX];

int readin( void)
{
    int num, i;                 
    scanf("%d", &num);

    for (i = 0; i < num; i++)
        scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass);
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

    printf("CoG coordinates are: x = %.2f, y = %.2f\n", sum_of_xmass / sum_of_mass, sum_of_ymass / sum_of_mass);

}
int main( void )
{
int number;
if((number = readin()) > 0)
computecg(number);
return 0;
}
