#include <stdio.h>

#define MEMORY_SIZE 100

void firstFit(int processSize[], int n, int blockSize[], int m) {
    int allocation[n];
  
    // Initialize allocation array with -1
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
  
    // Iterate over each process
    for (int i = 0; i < n; i++) {
        // Find the first block that can accommodate the current process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate the process to the block
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
  
    // Print the allocation details
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int n, m;
  
    printf("Enter the number of processes: ");
    scanf("%d", &n);
  
    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
  
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
  
    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
  
    // Perform First Fit algorithm
    firstFit(processSize, n, blockSize, m);
  
    return 0;
}
