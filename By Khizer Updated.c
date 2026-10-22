#include <stdio.h>
#include <stdlib.h>

// Function to handle allocation with saving and updating/adding
void allocate_resource(const char *resource_name, const char *unit, float *stored_amount) {
    float amount;
    int choice;

    // Check if a previous reserve has already been saved
    if (*stored_amount > 0) {
        printf("\nPrevious reserve found for %s: %.2f %s\n", resource_name, *stored_amount, unit);
        printf("1. Use existing reserve as is\n");
        printf("2. Add more to existing reserve (Accumulate)\n");
        printf("3. Enter a brand new reserve (Overwrite)\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            amount = *stored_amount; 
        } 
        else if (choice == 2) {
            float add_amount;
            printf("Enter amount to ADD to %s reserve (in %s): ", resource_name, unit);
            scanf("%f", &add_amount);
            *stored_amount += add_amount; // Adds to the previous value
            amount = *stored_amount;
        } 
        else {
            printf("Enter new total city %s reserve (in %s): ", resource_name, unit);
            scanf("%f", &amount);
            *stored_amount = amount; // Overwrites with new value
        }
    } else {
        // First time entering a reserve for this resource
        printf("\nEnter total city %s reserve (in %s): ", resource_name, unit);
        scanf("%f", &amount);
        *stored_amount = amount; // Save it to the array
    }

    // Realistic municipal distribution percentages
    float residential = amount * 0.45; 
    float industrial  = amount * 0.25; 
    float commercial  = amount * 0.15; 
    float healthcare  = amount * 0.15; 

    printf("\n--- City Allocation Summary for %s ---\n", resource_name);
    printf("%.2f %s is allocated to Residential (45%%)\n", residential, unit);
    printf("%.2f %s is allocated to Industrial (25%%)\n", industrial, unit);
    printf("%.2f %s is allocated to Commercial (15%%)\n", commercial, unit);
    printf("%.2f %s is allocated to Healthcare & Municipal (15%% - Protected)\n", healthcare, unit);
}

int main(int argc, char *argv[]) {
    int choice;

    // Array to store previous reserves: [0] Electricity, [1] Gas, [2] Water
    float stored_reserves[3] = {0.0, 0.0, 0.0};

    printf("=========== WELCOME TO SMART CITY RESOURCE ALLOCATION SIMULATOR ===========\n");

    do {
        printf("\n-------------------------------------------------------------------------\n");
        printf("Main Menu:\n");
        printf("Press 1 to Allocate Electricity\n");
        printf("Press 2 to Allocate Gas\n");
        printf("Press 3 to Allocate Water\n");
        printf("Press 4 to Exit Simulator\n");

        printf("Enter your choice: ");
        
        // If scanf fails to read an integer, clear input to prevent infinite loop
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the bad input from buffer
            continue;
        }

        switch(choice) {
            case 1:
                printf("\n[Allocating Electricity]\n");
                allocate_resource("Electricity", "GWh (Gigawatt-hours)", &stored_reserves[0]);
                break;

            case 2:
                printf("\n[Allocating Gas]\n");
                allocate_resource("Gas", "Thousand m3", &stored_reserves[1]);
                break;

            case 3:
                printf("\n[Allocating Water]\n");
                allocate_resource("Water", "Million Gallons", &stored_reserves[2]);
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