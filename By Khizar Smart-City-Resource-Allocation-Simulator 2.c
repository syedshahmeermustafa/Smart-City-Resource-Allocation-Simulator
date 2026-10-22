#include <stdio.h>
#include <stdlib.h>

void allocate_resource(const char *resource_name, const char *unit) {
    float amount;
    float residential, industrial, commercial, healthcare;

    printf("\nEnter total city %s reserve (in %s): ", resource_name, unit);
    scanf("%f", &amount);

    
    residential = amount * 0.45; 
    industrial  = amount * 0.25; 
    commercial  = amount * 0.15; 
    healthcare  = amount * 0.15; 

    printf("\n--- City Allocation Summary for %s ---\n", resource_name);
    printf("%.2f %s is allocated to Residential (45%%)\n", residential, unit);
    printf("%.2f %s is allocated to Industrial (25%%)\n", industrial, unit);
    printf("%.2f %s is allocated to Commercial (15%%)\n", commercial, unit);
    printf("%.2f %s is allocated to Healthcare & Municipal (15%% - Protected)\n", healthcare, unit);
}

int main(int argc, char *argv[]) {
    int choice;

    printf("=========== WELCOME TO SMART CITY RESOURCE ALLOCATION SIMULATOR ===========\n");


    do {
        printf("\n-------------------------------------------------------------------------\n");
        printf("Main Menu:\n");
        printf("Press 1 to Allocate Electricity\n");
        printf("Press 2 to Allocate Gas\n");
        printf("Press 3 to Allocate Water\n");
        printf("Press 4 to Exit Simulator\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n[Allocating Electricity]\n");
                allocate_resource("Electricity", "GWh (Gigawatt-hours)");
                break;

            case 2:
                printf("\n[Allocating Gas]\n");
                allocate_resource("Gas", "Thousand m3");
                break;

            case 3:
                printf("\n[Allocating Water]\n");
                allocate_resource("Water", "Million Gallons");
                break;

            case 4:
                printf("\nExiting Smart City Resource Allocation Simulator. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}