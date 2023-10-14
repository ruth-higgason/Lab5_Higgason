#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  //float array of sales
  float sales[12] = {23458.01, 40112.00, 56001.85, 37820.88, 37904.67,60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

  //char array of the months
  const char *month[12];
  month[0] = "January";
  month[1] = "February";
  month[2] = "March";
  month[3] = "April";
  month[4] = "May";
  month[5] = "June";
  month[6] = "July";
  month[7] = "August";
  month[8] = "September";
  month[9] = "October";
  month[10] = "November";
  month[11] = "December";

  //print year sales report
  printf("Monthly sales report for 2022: \n");
  printf("%-12s%-12s\n", "Month", "Sales");
  for (int i = 0; i <12; i++) {
    printf("%-12s$%-12.2f\n", month[i], sales[i]);
  }
  printf("\n");

  // find max sales month
  int max = 0;
  for (int i = 0; i < 12; i++) {
    if (sales[i] > sales[max]) {
      max = i;
    }
  }
  // find min sales month
  int min = 0;
  for (int i = 0; i < 12; i++) {
    if (sales[i] < sales[min]) {
      min = i;
    }
  }
  
  // find average sales
  float total = 0.0;
  for (int i = 0; i < 12; i++) {
    total += sales[i];
  }
  float average = total/12.0;

  //print sales summary
  printf("Sales summary:\n");
  printf("%-15s$%-12.2f(%s)\n", "Minimum sales:", sales[min], month[min]);
  printf("%-15s$%-12.2f(%s)\n", "Maximum sales:", sales[max], month[max]);
  printf("%-15s$%-12.2f\n", "Average sales:", average);
  printf("\n");

  //print six-month sales report
  printf("Six-Month Moving Average Report:\n");
  //find six-month average
  for (int k = 0; k < 7; k++) {
    for ( int j = k; j < (k + 6); j++) {
      total += sales[j];
    }
    average = total/6.0;
    printf("%-10s-%-10s$%-12.2f\n", month[k], month[k+5], average);
  }
  printf("\n");

  //print sales highest to lowest
  printf("Sales Report (Highest to Lowest):\n");
  int size = 12;
  //find highest sale
  for (int i = 0; i < 12; i++) {
    max = 0;
    for (int i = 0; i < size; i++) {
      if (sales[i] > sales[max]) {
        max = i;
      }
    }
    //remove highest sale and reduce size by one
    printf("%-12s$%-12.2f\n", month[max], sales[max]);
    if (max < size) {
      for (int j = max; j < (size - 1); j++) {
        sales[j] = sales[j+1];
      }
    }
    size--;
  }
}