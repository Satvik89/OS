#include <stdio.h>

// Number of processes and resources
int n, m;

// Available resources
int available[10];

// Allocation matrix
int allocation[10][10];

// Need matrix
int need[10][10];

// Function to check if the system is in safe state
int isSafe() {
  // Mark all processes as unexecuted
  int finished[10] = {0};

  // Initialize work vector
  int work[10];
  for (int i = 0; i < m; i++) {
    work[i] = available[i];
  }

  // Iterate until all processes are finished
  int count = 0;
  while (count < n) {
    // Find a process that is not finished and has no need for any resources
    int found = 0, i;
    for (i = 0; i < n; i++) {
      if (!finished[i]) {
        int j;
        for (j = 0; j < m; j++) {
          if (need[i][j] > work[j]) {
            break;
          }
        }
        if (j == m) {
          found = 1;
          break;
        }
      }
    }

    // If no such process exists, the system is not in a safe state
    if (!found) {
      return 0;
    }

    // Mark the found process as finished
    finished[i] = 1;
    count++;

    // Update the work vector
    for (int j = 0; j < m; j++) {
      work[j] += allocation[i][j];
    }
  }

  return 1;
}

int main() {
  printf("Read the number of processes and resources: ");
  scanf("%d %d", &n, &m);

  printf("Read the available resources: ");
  for (int i = 0; i < m; i++) {
    scanf("%d", &available[i]);
  }

  printf("Read the allocation matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &allocation[i][j]);
    }
  }

  printf("Read the need matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &need[i][j]);
    }
  }

  // Check if the system is in a safe state
  if (isSafe()) {
    printf("The system is in a safe state.\n");
  } else {
    printf("The system is not in a safe state.\n");
  }

  return 0;
}
