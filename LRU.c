#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int findPage(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return i; // Page found in the frames, return its index
        }
    }
    return -1; // Page not found in the frames
}

void updateLRU(int lru[], int n, int index) {
    for (int i = 0; i < n; i++) {
        if (lru[i] < lru[index]) {
            lru[i]++;
        }
    }
    lru[index] = 0;
}

void lru(int pages[], int n, int frames) {
    int pageFaults = 0; // Count of page faults
    int frame[MAX_FRAMES]; // Array to store the frames
    int lru[MAX_FRAMES]; // Array to store the LRU counters

    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating empty frames
        lru[i] = 0; // Initialize LRU counters with 0
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int index = findPage(frame, frames, page);

        if (index == -1) {
            // Page fault: Page not found in the frames
            int lruIndex = 0; // Index of the least recently used page
            for (int j = 1; j < frames; j++) {
                if (lru[j] > lru[lruIndex]) {
                    lruIndex = j;
                } 
            }

            frame[lruIndex] = page;
            updateLRU(lru, frames, lruIndex);
            pageFaults++;
           
        } else {
            // Page found in the frames, update the LRU counters
            updateLRU(lru, frames, index);
        }
        
    }


    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n; // Number of pages
    int pages[MAX_PAGES]; // Array to store the pages
    int frames; // Number of frames

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    lru(pages, n, frames);

    return 0;
}
