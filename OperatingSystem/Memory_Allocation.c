#include <stdio.h>
#define MAX 10
// ---------- FIRST FIT FUNCTION ----------
void firstFit(int nb, int np, int blockSize[], int processSize[]) {
    int tempBlock[MAX], allocation[MAX];
    int i, j;

    for (i = 0; i < nb; i++)
        tempBlock[i] = blockSize[i];

    for (i = 0; i < np; i++)
        allocation[i] = -1;

    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (processSize[i] <= tempBlock[j]) {
                allocation[i] = j;
                tempBlock[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\n--- First Fit Allocation ---\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}
// ---------- BEST FIT FUNCTION ----------
void bestFit(int nb, int np, int blockSize[], int processSize[]) {
    int tempBlock[MAX], allocation[MAX];
    int i, j;
    for (i = 0; i < nb; i++)
        tempBlock[i] = blockSize[i];
    for (i = 0; i < np; i++)
        allocation[i] = -1;
    for (i = 0; i < np; i++) {
        int bestIdx = -1;
        for (j = 0; j < nb; j++) {
            if (processSize[i] <= tempBlock[j]) {
                if (bestIdx == -1 || tempBlock[j] < tempBlock[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            tempBlock[bestIdx] -= processSize[i];
        }
    }
    printf("\n--- Best Fit Allocation ---\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}
// ---------- WORST FIT FUNCTION ----------
void worstFit(int nb, int np, int blockSize[], int processSize[]) {
    int tempBlock[MAX], allocation[MAX];
    int i, j;

    for (i = 0; i < nb; i++){
        tempBlock[i] = blockSize[i];
    }
    for (i = 0; i < np; i++){
        allocation[i] = -1;
    }
    for (i = 0; i < np; i++) {
        int worstIdx = -1;
        for (j = 0; j < nb; j++) {
            if (processSize[i] <= tempBlock[j]) {
                if (worstIdx == -1 || tempBlock[j] > tempBlock[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            tempBlock[worstIdx] -= processSize[i];
        }
    }
    printf("\n--- Worst Fit Allocation ---\n");
    for (i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

// ---------- MAIN FUNCTION ----------
int main() {
    int nb, np;
    int blockSize[MAX], processSize[MAX];
    int i;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &np);
    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call each allocation method
    firstFit(nb, np, blockSize, processSize);
    bestFit(nb, np, blockSize, processSize);
    worstFit(nb, np, blockSize, processSize);

    return 0;
}

