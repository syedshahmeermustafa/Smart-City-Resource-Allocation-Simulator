#include <stdio.h>
#include <stdlib.h>

// Reusable function updated with large-scale municipal units
void allocate_resource(const char *resource_name, const char *unit) {
    float amount;
    float healthcare, residential, industrial, commercial;

    printf("Enter total city %s reserve (in %s): ", resource_name, unit);
    scanf("%f", &amount);

    // Percentage breakdown based on your priority logic
    healthcare = amount * 0.35;
    residential = amount * 0.30;
    industrial = amount * 0.25;
    commercial = amount * 0.10;

    printf("\n--- City Allocation Summary for %s ---\n", resource_name);
    printf("%.2f %s is allocated to healthcare (35%%)\n", healthcare, unit);
    printf("%.2f %s is allocated to residential (30%%)\n", residential, unit);
    printf("%.2f %s is allocated to industrial (25%%)\n", industrial, unit);
    printf("%.2f %s is allocated to commercial (10%%)\n", commercial, unit);
}

int main(int argc, char *argv[]) {
    int choice;

    printf("=========== WELCOME TO SMART CITY RESOURCE ALLOCATION SIMULATOR ===========\n");
    printf("Press 1 to Allocate Electricity\n");
    printf("Press 2 to Allocate Gas\n");
    printf("Press 3 to Allocate Water\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            allocate_resource("Electricity", "GWh (Gigawatt-hours)");
            break;

        case 2:
            allocate_resource("Gas", "Thousand m3");
            break;

        case 3:
            allocate_resource("Water", "Million Gallons");
            break;

        default:
            printf("Invalid choice. Please restart the simulator.\n");
    }

    return 0;
}