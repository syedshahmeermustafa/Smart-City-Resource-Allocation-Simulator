#include <stdio.h>
#include <stdlib.h>

void electricity(float electricity_allocation[], int *saved)
{

	float amount;
	int i, update;
	   if (*saved == 1)
    {
        printf("\nPrevious Electricity Allocation:\n");
        printf("Healthcare: %.2f KW\n", electricity_allocation[0]);
        printf("Residential: %.2f KW\n", electricity_allocation[1]);
        printf("Industrial: %.2f KW\n", electricity_allocation[2]);
        printf("Commercial: %.2f KW\n", electricity_allocation[3]);

        printf("\nDo you want to update it? (1 = Yes, 0 = No): ");
        scanf("%d", &update);

        if (update == 0)
            return;

        if (update != 1)
        {
            printf("Invalid choice.\n");
            return;
        }
    }

    printf("Enter electricity reserve in KW: ");
    scanf("%f", &amount);

    electricity_allocation[0] = amount * 0.35;
    electricity_allocation[1] = amount * 0.30;
    electricity_allocation[2] = amount * 0.25;
    electricity_allocation[3] = amount * 0.10;

    printf("%.2f KW is allocated to healthcare\n", electricity_allocation[0]);
    printf("%.2f KW is allocated to residential\n", electricity_allocation[1]);
    printf("%.2f KW is allocated to industrial\n",  electricity_allocation[2]);
    printf("%.2f KW is allocated to commercial\n",    electricity_allocation[3]);
    
    *saved = 1;
}
int main(int argc, char *argv[]) {
    int choice;
	int another_sector = 1;
	int saved = 0;
	float electricity_allocation[4] = {0};
do{
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
            electricity(electricity_allocation, &saved);
            break;

        case 2:
            printf("Allocating Gas\n");
            break;

        case 3:
            printf("Allocating Water\n");
            break;
            
        case 4:
            printf("Exiting simulator...\n");
            another_sector = 0;
            break;    

        default:
            printf("Invalid choice\n");
    }
       if (choice != 4)
        {
           printf("\nDo you want to return to the menu? (1 = Yes, 0 = No): ");
           scanf("%d", &another_sector);
            if (another_sector != 0 && another_sector != 1)
            {
            printf("Invalid choice. Exiting simulator.\n");
        	another_sector = 0;
            }
        }
	}	
while(another_sector == 1);
    return 0;

}

