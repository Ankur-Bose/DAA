#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct {
    int id;     // Job ID
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
} Job;

// Function to compare jobs based on their profit in descending order
int compare(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum profit sequence of jobs
void jobSequencing(Job jobs[], int n) {
    // Sort jobs according to their profit
    qsort(jobs, n, sizeof(Job), compare);

    // To keep track of free time slots
    int result[n]; // To store result (sequence of jobs)
    int slot[n];   // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == 0) {
                result[j] = i;  // Add this job to result
                slot[j] = 1;    // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    printf("Following is the maximum profit sequence of jobs:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("Job %d\n", jobs[result[i]].id);
        }
    }
}

int main() {
    Job jobs[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}
