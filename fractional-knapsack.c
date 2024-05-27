#include <stdio.h>
#include <stdlib.h>

// A utility function to swap two elements
void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

// Function to sort items based on value/weight ratio in descending order
void sortItems(double valuePerWeight[], int values[], int weights[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valuePerWeight[j] < valuePerWeight[j + 1]) {
                swap(&valuePerWeight[j], &valuePerWeight[j + 1]);
                swap((double*)&values[j], (double*)&values[j + 1]);
                swap((double*)&weights[j], (double*)&weights[j + 1]);
            }
        }
    }
}

// Function to calculate the maximum value that can be put in a knapsack of capacity W
double fractionalKnapsack(int W, int values[], int weights[], int n) {
    double valuePerWeight[n];

    // Calculate value/weight ratio for each item
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)values[i] / weights[i];
    }

    // Sort items by value/weight ratio
    sortItems(valuePerWeight, values, weights, n);

    int curWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding Item[i] doesn't overflow, add it completely
        if (curWeight + weights[i] <= W) {
            curWeight += weights[i];
            finalValue += values[i];
        }
        // If we can't add the whole item, add the fractional part
        else {
            int remain = W - curWeight;
            finalValue += values[i] * ((double) remain / weights[i]);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50;  // Knapsack capacity
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value we can obtain = %f\n", fractionalKnapsack(W, values, weights, n));
    return 0;
}
