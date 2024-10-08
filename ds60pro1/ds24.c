#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONS 100

// Structure to hold person data
typedef struct {
    int personNo;
    int age;
} Person;

// Function to read data from the file
int readData(const char* filename, Person* persons) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %d", &persons[count].personNo, &persons[count].age) != EOF && count < MAX_PERSONS) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to perform insertion sort on the array of persons based on age
void insertionSort(Person* persons, int n) {
    for (int i = 1; i < n; i++) {
        Person key = persons[i];
        int j = i - 1;
        while (j >= 0 && persons[j].age > key.age) {
            persons[j + 1] = persons[j];
            j--;
        }
        persons[j + 1] = key;
    }
}

// Function to display the sorted persons
void displayPersons(Person* persons, int n) {
    printf("Sorted Persons by Age:\n");
    for (int i = 0; i < n; i++) {
        printf("Person No: %d, Age: %d\n", persons[i].personNo, persons[i].age);
    }
}

// Main function
int main() {
    Person persons[MAX_PERSONS];
    int count = readData("person.txt", persons);
    if (count > 0) {
        insertionSort(persons, count);
        displayPersons(persons, count);
    }
    return 0;
}
