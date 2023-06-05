#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int findOptimalPage(int pages[], int pageFrames[], int n, int current) {
    int index = -1, farthest = current;
    
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = current; j < n; j++) {
            if (pageFrames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        
        // If a page is not referenced in the future, return its index
        if (j == n)
            return i;
    }
    
    return (index == -1) ? 0 : index;
}

int optimalPageReplacement(int pages[], int n, int capacity) {
    int pageFrames[MAX_FRAMES];
    int pageFaults = 0;
    
    for (int i = 0; i < MAX_FRAMES; i++) {
        pageFrames[i] = -1; // Initialize page frames with -1 (empty)
    }
    
    for (int i = 0; i < n; i++) {
        bool pageExists = false;
        
        // Check if page already exists in page frames
        for (int j = 0; j < capacity; j++) {
            if (pageFrames[j] == pages[i]) {
                pageExists = true;
                break;
            }
        }
        
        // If page doesn't exist, perform page replacement
        if (!pageExists) {
            int pageToReplace = findOptimalPage(pages, pageFrames, n, i + 1);
            pageFrames[pageToReplace] = pages[i];
            pageFaults++;
        }
    }
    
    return pageFaults;
}

int main() {
    int pages[MAX_FRAMES];
    int n, capacity;
    
    printf("Enter the number of page references: ");
    scanf("%d", &n);
    
    printf("Enter the page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter the number of page frames: ");
    scanf("%d", &capacity);
    
    int pageFaults = optimalPageReplacement(pages, n, capacity);
    
    printf("Number of page faults: %d\n", pageFaults);
    
    return 0;
}
