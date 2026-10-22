#include <stdio.h>

void allocateResource(char resource[])
{
    float supply;
    float percentage[4];
    float allocation[4];
    float totalPercentage = 0;
    float totalAllocated = 0;
    float remainingSupply;
    int i;
    int invalid;

    char districts[4][20] = {
        "Healthcare",
        "Commercial",
        "Industrial",
        "Residential"
    };

    printf("\n==================================================\n");
    printf("             %s ALLOCATION\n", resource);
    printf("==================================================\n");

    printf("Enter total available %s supply: ", resource);
    scanf("%f", &supply);

    while (supply <= 0)
    {
        printf("Supply must be greater than zero.\n");
        printf("Enter total available %s supply: ", resource);
        scanf("%f", &supply);
    }

    do
    {
        totalPercentage = 0;
        invalid = 0;

        printf("\nEnter allocation percentage for each district.\n");
        printf("The total percentage cannot exceed 100%%.\n\n");

        for (i = 0; i < 4; i++)
        {
            printf("%s District (%%): ", districts[i]);
            scanf("%f", &percentage[i]);

            if (percentage[i] < 0 || percentage[i] > 100)
            {
                invalid = 1;
            }

            totalPercentage = totalPercentage + percentage[i];
        }

        if (invalid == 1)
        {
            printf("\nInvalid percentage! Enter values from 0 to 100.\n");
        }
        else if (totalPercentage > 100)
        {
            printf("\nError! Your percentages add up to %.2f%%.\n",
                   totalPercentage);
            printf("Please enter the percentages again.\n");
        }

    } while (invalid == 1 || totalPercentage > 100);

    for (i = 0; i < 4; i++)
    {
        allocation[i] = supply * percentage[i] / 100;
        totalAllocated = totalAllocated + allocation[i];
    }

    remainingSupply = supply - totalAllocated;

    printf("\n");
    printf("==================================================\n");
    printf("             SMART CITY ALLOCATION REPORT\n");
    printf("==================================================\n");

    printf("Resource Selected : %s\n", resource);
    printf("Total Supply      : %.2f units\n", supply);

    printf("--------------------------------------------------\n");
    printf("%-18s %-15s %-15s\n",
           "District", "Percentage", "Allocation");
    printf("--------------------------------------------------\n");

    for (i = 0; i < 4; i++)
    {
        printf("%-18s %-14.2f%% %.2f units\n",
               districts[i], percentage[i], allocation[i]);
    }

    printf("--------------------------------------------------\n");
    printf("Total Percentage  : %.2f%%\n", totalPercentage);
    printf("Total Allocated   : %.2f units\n", totalAllocated);
    printf("Remaining Supply  : %.2f units\n", remainingSupply);
    printf("==================================================\n");

    if (remainingSupply == 0)
    {
        printf("Status: All available supply has been allocated.\n");
    }
    else
    {
        printf("Status: Some supply remains unallocated.\n");
    }

    printf("==================================================\n");
}

int main()
{
    int choice;
    int again = 1;

    printf("\n");
    printf("**************************************************\n");
    printf("       SMART CITY RESOURCE ALLOCATION SYSTEM\n");
    printf("**************************************************\n");

    while (again == 1)
    {
        printf("\nSelect the resource to allocate:\n");
        printf("1. Electricity\n");
        printf("2. Gas\n");
        printf("3. Water\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                allocateResource("Electricity");
                break;

            case 2:
                allocateResource("Gas");
                break;

            case 3:
                allocateResource("Water");
                break;

            case 4:
                printf("\nThank you for using the Smart City\n");
                printf("Resource Allocation System!\n");
                again = 0;
                break;

            default:
                printf("\nInvalid choice! Please select 1, 2, 3, or 4.\n");
        }

        if (again == 1)
        {
            printf("\nDo you want to allocate another resource?\n");
            printf("1. Yes, continue\n");
            printf("2. No, exit\n");
            printf("Enter your choice: ");
            scanf("%d", &again);

            while (again != 1 && again != 2)
            {
                printf("Invalid choice! Enter 1 to continue or 2 to exit: ");
                scanf("%d", &again);
            }

            if (again == 2)
            {
                printf("\nThank you for using the Smart City\n");
                printf("Resource Allocation System!\n");
            }
        }
    }

    return 0;
}