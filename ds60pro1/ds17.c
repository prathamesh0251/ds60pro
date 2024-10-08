#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Structure to hold employee data
typedef struct {
    int empno;
    char empname[50];
} Employee;

// Function to compare two employees by name
int compare(const void* a, const void* b) {
    Employee* emp1 = (Employee*)a;
    Employee* emp2 = (Employee*)b;
    return strcmp(emp1->empname, emp2->empname);
}

// Function to sort employees using Bubble Sort
void bubbleSort(Employee* employees, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(&employees[j], &employees[j + 1]) > 0) {
                // Swap employees
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    FILE* file = fopen("employee.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    // Read data from the file
    while (fscanf(file, "%d %49s", &employees[count].empno, employees[count].empname) != EOF) {
        count++;
    }
    fclose(file);

    // Sort the employees
    bubbleSort(employees, count);

    // Display sorted employee data
    printf("Sorted Employee Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Emp No: %d, Name: %s\n", employees[i].empno, employees[i].empname);
    }

    return 0;
}