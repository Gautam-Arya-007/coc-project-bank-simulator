#include <stdio.h>

// Function declarations
void readScores(float scores[], int count);
float findMean(float scores[], int count);
float findMax(float scores[], int count);
float findMin(float scores[], int count);
void printSummary(float scores[], int count);

int main() {
    int totalStudents;

    printf("=== Student Score Analyzer ===\n");
    printf("Enter total number of students: ");
    scanf("%d", &totalStudents);

    if (totalStudents <= 0) {
        printf("Invalid number of students!\n");
        return 0;
    }

    float marks[totalStudents];

    // Step 1: Input
    readScores(marks, totalStudents);

    // Step 2: Report
    printSummary(marks, totalStudents);

    return 0;
}

// Function to read all student scores
void readScores(float scores[], int count) {
    printf("\nEnter the quiz scores for %d students:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &scores[i]);
    }
}

// Function to calculate mean
float findMean(float scores[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum / count;
}

// Function to find the highest score
float findMax(float scores[], int count) {
    float max = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

// Function to find the lowest score
float findMin(float scores[], int count) {
    float min = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] < min) {
            min = scores[i];
        }
    }
    return min;
}

// Function to print full summary
void printSummary(float scores[], int count) {
    float avg = findMean(scores, count);
    float highest = findMax(scores, count);
    float lowest = findMin(scores, count);

    printf("\n--- Quiz Report ---\n");
    printf("Total Students : %d\n", count);
    printf("Average Score  : %.2f\n", avg);
    printf("Highest Score  : %.2f\n", highest);
    printf("Lowest Score   : %.2f\n", lowest);

    // Optional grade classification
    printf("\nPerformance Classification:\n");
    for (int i = 0; i < count; i++) {
        if (scores[i] >= 90)
            printf("Student %d: Excellent\n", i + 1);
        else if (scores[i] >= 75)
            printf("Student %d: Good\n", i + 1);
        else if (scores[i] >= 50)
            printf("Student %d: Average\n", i + 1);
        else
            printf("Student %d: Needs Improvement\n", i + 1);
    }
}
