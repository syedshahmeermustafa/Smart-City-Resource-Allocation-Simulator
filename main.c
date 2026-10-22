#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
void electricity(float amount)
{
    float healthcare, residential, industrial, commercial;

    printf("Enter electricity reserve: ");
    scanf("%f", &amount);

    healthcare = amount * (35.0 / 100);
    residential = amount * (30.0 / 100);
    industrial = amount * (25.0 / 100);
    commercial = amount * (10.0 / 100);

    printf("%.2f is allocated to healthcare\n", healthcare);
    printf("%.2f is allocated to residential\n", residential);
    printf("%.2f is allocated to industrial\n", industrial);
    printf("%.2f is allocated to commercial\n", commercial);
}
    int choice;

    printf("=========== WELCOME TO SMART CITY RESOURCE ALLOCATION SIMULATOR ===========\n");
    printf("Press 1 to Allocate Electricity\n");
    printf("Press 2 to Allocate Gas\n");
    printf("Press 3 to Allocate Water\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Allocating Electricity\n");
            electricity(0);
            break;

        case 2:
            printf("Allocating Gas\n");
            break;

        case 3:
            printf("Allocating Water\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;

}

