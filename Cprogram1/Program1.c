/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: Manoj Turaga
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_MONTHS (12)

static char* months[] = {"January", "February", "March",
                            "April", "May", "June",
                            "July", "August", "September",
                            "October", "November", "December"};

void min_max_average(const double* arr)
{
    int min_index = 0;
    int max_index = 0;
    double sum = 0;

    printf("Sales summary:\n\n");

    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        if(arr[i] > arr[max_index])
        {
            max_index = i;
        }
        if(arr[i] < arr[min_index])
        {
            min_index = arr[i];
        }
        sum += arr[i];
    }

    printf("Minimum Sales:\t$%.2f\t(%s)\n", arr[min_index], months[min_index]);
    printf("Maximum Sales:\t$%.2f\t(%s)\n", arr[max_index], months[max_index]);
    printf("Average Sales:\t$%.2f\n", sum/NUM_OF_MONTHS);
}

void six_month_average(const double* arr)
{
    printf("Six-Month moving average report:\n\n");
    for(int lower_month = 0, upper_month = lower_month + 5; upper_month <= (NUM_OF_MONTHS - 1); lower_month++, upper_month++)
    {
        double total = 0;
        char tempString[15];

        for(int i = lower_month; i <= upper_month; i++)
        {
            total += arr[i];
        }
        if ((int) (total * 1000) % 10 >= 5)
        {
            total += 0.01;
        }
        sprintf(tempString, "%s-%s", months[lower_month], months[upper_month]);
        printf("%-15s\t$%.2f\n", tempString, total/6);
    }
}

void highest_to_lowest(const double* arr)
{
    int is_index_used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("Sales report: (highest to lowest)\n\n");
    printf("%-9s\tSales\n\n", "Months");

    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        int largest_val_index = 0;
        for(int j = 0; j < NUM_OF_MONTHS; j++)
        {
            if (arr[j] > arr[largest_val_index] && !is_index_used[j])
            {
                largest_val_index = j;
            }
        }
        is_index_used[largest_val_index] = 1;
        printf("%-9s\t$%.2f\n", months[largest_val_index], arr[largest_val_index]);
    }
}
void sales_report(const double* arr)
{
	printf("Monthly sales report for 2022:\n\n");
	printf("%-9s\t%s\n\n", "Months", "Sales");
	for(int i = 0; i < NUM_OF_MONTHS; i++)
	{
		printf("%-9s\t$%.2f\n", months[i], arr[i]);
	}
}
int main()
{
	char buffer[15];
	double values[12];

	FILE *fp;
	fp = fopen("input.txt", "r");

	if(fp != NULL)
	{
		for(int i = 0; i < NUM_OF_MONTHS; i++)
		{
			fgets(buffer, 15, fp);
			values[i] = atof(buffer);;
		}
		fclose(fp);
		sales_report(values);
		printf("\n");
		min_max_average(values);
		printf("\n");
		six_month_average(values);
		printf("\n");
		highest_to_lowest(values);
	}
	else
	{
		printf("Could not find file 'input.txt'\n");
	}
	return 0;
}

