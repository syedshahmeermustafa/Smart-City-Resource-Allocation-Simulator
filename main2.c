#include <stdio.h>
#include <stdlib.h>


int electricity(float amount,float *remaining, float allocate[]){
	int utility, hospitals, housing_schemes, industry, commercial, update;
	float calculation, allocation_percentage, perhospital, perscheme, perindustry, perstore, oldsum, sum, difference;
	printf("Remaining electricity: %.2f\n", *remaining);
printf("You have 4 sectors.\n");
printf("Press 1 for Healthcare\n");
printf("Press 2 for Residential\n");
printf("Press 3 for Industrial\n");
printf("Press 4 for Commercial\n");
printf("Press 5 to Return to Main Menu\n");
scanf("%d", &utility);
if(utility < 1 || utility > 5){
    printf("Invalid sector selected.\n");
    return 1;
	}
switch(utility){
	case 1:
		printf("You chose Healthcare!\n");
		if(allocate[0] > 0){
    	printf("Previous Healthcare Allocation: %.2f%%\n", allocate[0]);
    	printf("Do you want to update it? (1 = Yes , 0 = No)\n");
    	scanf("%d", &update);
    	if(update == 1){
    		oldsum = allocate[0] * amount / 100;	
		}
		else if(update == 0){
			break;
		}
		else{
			printf("Invalid option chosen\n");
			break;
		}
		}
		printf("Enter no. of Hospitals\n");
		scanf("%d", &hospitals);
		 if(hospitals <= 0)
   			{
       	    printf("Invalid number of hospitals.\n");
            break;
			}
		printf("Enter allocation percentage\n");
		scanf("%f", &allocation_percentage);
		if(allocation_percentage <= 0 || allocation_percentage > 100){
    printf("Invalid allocation percentage.\n");
    break;
		}
	if(allocate[0] > 0){
    sum = allocation_percentage * amount / 100;
    difference = sum - oldsum;
    if(difference > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }
    *remaining = *remaining - difference;
    calculation = sum;
	}
	else{
    calculation = allocation_percentage * amount / 100;
    if(calculation > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }
    *remaining = *remaining - calculation;
	}
	allocate[0] = allocation_percentage;
		perhospital = calculation / hospitals;
		printf("%.2f GWH has been allocated to Healthcare sector\n", calculation);
		printf("Each hospital gets %.2f GWH electricity\n", perhospital);
		break;
		case 2:
				printf("You chose Residential!\n");
				if(allocate[1] > 0){
    			printf("Previous Residential Allocation: %.2f%%\n", allocate[1]);
    			printf("Do you want to update it? (1 = Yes , 0 = No)\n");
    			scanf("%d", &update);
    	if(update == 1){
    		oldsum = allocate[1] * amount / 100;	
		}
		else if(update == 0){
			break;
		}
		else{
			printf("Invalid option chosen\n");
			break;
		}
				}
			printf("Enter no. of Housing schemes\n");
			scanf("%d", &housing_schemes);
		 if(housing_schemes <= 0)
   			{
       	    printf("Invalid number of housing schemes.\n");
            break;
			}
				printf("Enter allocation percentage\n");
		scanf("%f", &allocation_percentage);
		if(allocation_percentage <= 0 || allocation_percentage > 100){
    printf("Invalid allocation percentage.\n");
    break;
		}
	if(allocate[1]>0){
		sum = allocation_percentage * amount / 100;
		difference = sum - oldsum;
		   if(difference > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }
    *remaining = *remaining - difference;
    calculation = sum;
	}
	else{
		calculation = allocation_percentage * amount / 100;
		if(calculation > *remaining){
			printf("Insufficient electricity remaining\n");
			break;
		}
		*remaining = *remaining - calculation;
	}
		allocate[1] = allocation_percentage;
		perscheme = calculation / housing_schemes;
		printf("%.2f GWH has been allocated to Residential sector\n", calculation);
		printf("Each housing scheme gets %.2f GWH electricity\n", perscheme);
		break;		
case 3:
		printf("You chose Industrial Sector!\n");
		if(allocate[2] > 0){
    printf("Previous Industrial Allocation: %.2f%%\n", allocate[2]);
    printf("Do you want to update it? (1 = Yes , 0 = No)\n");
    	scanf("%d", &update);
    	if(update == 1){
    		oldsum = allocate[2] * amount / 100;	
		}
		else if(update == 0){
			break;
		}
		else{
			printf("Invalid option chosen\n");
			break;
		}
	}
			printf("Enter no. of industries\n");
			scanf("%d", &industry);
		 if(industry <= 0)
   			{
       	    printf("Invalid number of industries.\n");
            break;
			}
				printf("Enter allocation percentage\n");
		scanf("%f", &allocation_percentage);
		if(allocation_percentage <= 0 || allocation_percentage > 100){
    printf("Invalid allocation percentage.\n");
    break;
		}	
		if(allocate[2] > 0){
    sum = allocation_percentage * amount / 100;
    difference = sum - oldsum;

    if(difference > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }

    *remaining = *remaining - difference;
    calculation = sum;
}
else{
    calculation = allocation_percentage * amount / 100;

    if(calculation > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }

    *remaining = *remaining - calculation;
}

allocate[2] = allocation_percentage;
		perindustry = calculation / industry;
		printf("%.2f GWH has been allocated to Industrial sector\n", calculation);
		printf("Each industry gets %.2f GWH electricity\n", perindustry);
		break;
			
case 4:
		printf("You chose Commercial!\n");
		if(allocate[3] > 0){
    printf("Previous Commercial Allocation: %.2f%%\n", allocate[3]);
    printf("Do you want to update it? (1 = Yes , 0 = No)\n");
    	scanf("%d", &update);
    	if(update == 1){
    		oldsum = allocate[3] * amount / 100;	
		}
		else if(update == 0){
			break;
		}
		else{
			printf("Invalid option chosen\n");
			break;
		}
		}
			printf("Enter no. of stores\n");
			scanf("%d", &commercial);
		 if(commercial <= 0)
   			{
       	    printf("Invalid number of stores.\n");
            break;
			}
				printf("Enter allocation percentage\n");
		scanf("%f", &allocation_percentage);
		if(allocation_percentage <= 0 || allocation_percentage > 100){
    printf("Invalid allocation percentage.\n");
    break;
		}
	if(allocate[3] > 0){
    sum = allocation_percentage * amount / 100;
    difference = sum - oldsum;

    if(difference > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    }
    *remaining = *remaining - difference;
    calculation = sum;
	}
		else{
    	calculation = allocation_percentage * amount / 100;
    	if(calculation > *remaining){
        printf("Insufficient electricity remaining.\n");
        break;
    	}
    	*remaining = *remaining - calculation;
		}
		allocate[3] = allocation_percentage;
		perstore = calculation / commercial;
		printf("%.2f GWH has been allocated to Commercial sector\n", calculation);
		printf("Each store gets %.2f GWH electricity\n", perstore);
		break;
			
case 5:
	printf("You chose to return to Main Menu\n");
	return 0;
default:
	printf("Invalid option chosen");
	break;
}

	
return 1;	
}

int main(int argc, char *argv[]) {
	int choice, allocation, continue_allocation, i;
	float amount, remaining, allocate[4]={0};
	do{
	printf("\n==================== WELCOME TO THE SMART CITY RESOURCE ALLOCATION SIMULATOR ====================\n");
	printf("Choose your desired utility\n");
	printf("Choose 1 for Electricity\n");
	printf("Choose 2 for Gas\n");
	printf("Choose 3 for Water\n");
	printf("Choose 4 to Exit\n");
	scanf("%d", &choice);
    system("cls");
	switch(choice){
		case 1:
		printf("You chose Electricity!\n");
		   for(i = 0; i < 4; i++){
        allocate[i] = 0;
		}
		printf("Enter the reserved Electricity amount in GKWH (Giga Kilowatt Hour)\n");
		scanf("%f", &amount);
		if(amount <= 0){
    printf("Invalid electricity amount.\n");
    break;
		}
		remaining = amount;
		printf("You reserved %.2f GWH Electricity\n", amount);
		continue_allocation = 1;
		allocation = 0;
	do{
    continue_allocation = electricity(amount,&remaining, allocate);
    if(continue_allocation == 1){
        printf("Do you want to allocate to more sectors (1 = Yes, 0 = No)\n");
        scanf("%d", &allocation);
    }
	}while(allocation == 1 && continue_allocation == 1);
	}
}while(choice != 4);
if(choice == 4 ){
	printf("\n===================== THANK YOU FOR USING OUR SMART CITY RESOURCE ALLOCATION SIMULATOR =====================\n");
}
return 0;
}


