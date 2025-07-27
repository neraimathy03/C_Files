#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

// Function to input student details
void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Enter 5 marks: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
        }
    }
}

// Function to calculate average marks
void calculateAverage(struct Student *s) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += s->marks[i];

    s->average = sum / 5.0;
}

// Function to display topper details
void displayTopper(struct Student s[], int n) {
    int topperIndex = 0;

    for (int i = 1; i < n; i++) {
        if (s[i].average > s[topperIndex].average) {
            topperIndex = i;
        }
    }

    printf("\nTopper Details:\n");
    printf("ID: %d\n", s[topperIndex].id);
    printf("Name: %s\n", s[topperIndex].name);
    printf("Average Marks: %.2f\n", s[topperIndex].average);
}

int main() {
    int n = 5;  // Number of students
    struct Student students[n];

    inputStudents(students, n);

    // Calculate average for each student
    for (int i = 0; i < n; i++)
        calculateAverage(&students[i]);

    displayTopper(students, n);

    return 0;
}
