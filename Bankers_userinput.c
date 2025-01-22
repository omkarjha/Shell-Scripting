#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int need[][10], int max[][10], int allot[][10], int P, int R) {
    // Calculate the need matrix: need[i][j] = max[i][j] - allot[i][j]
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

bool isSafe(int processes[], int avail[], int max[][10], int allot[][10], int P, int R) {
    int need[10][10];
    calculateNeed(need, max, allot, P, R);

    bool finish[10] = {0}; // Tracks whether a process is finished
    int safeSeq[10];       // To store the safe sequence
    int work[10];          // Work array to store available resources

    // Initialize work with available resources
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0; // Count of processes in the safe sequence

    while (count < P) {
        bool found = false;

        for (int p = 0; p < P; p++) {
            if (!finish[p]) { // If process p is not finished
                bool canAllocate = true;

                // Check if need of process p can be satisfied
                for (int j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                // If resources can be allocated
                if (canAllocate) {
                    // Add allocated resources to work
                    for (int k = 0; k < R; k++) {
                        work[k] += allot[p][k];
                    }

                    // Include this process in the safe sequence
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }

        // If no process could be allocated resources
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    // If we reach here, the system is in a safe state
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return true;
}

int main() {
    int P, R;
    int processes[10], avail[10], max[10][10], allot[10][10];

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &P);
    printf("Enter the number of resources: ");
    scanf("%d", &R);

    // Input the available resources
    printf("Enter the available resources: ");
    for (int i = 0; i < R; i++) {
        scanf("%d", &avail[i]);
    }

    // Input the maximum demand matrix
    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input the allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Check if the system is in a safe state
    isSafe(processes, avail, max, allot, P, R);

    return 0;
}
