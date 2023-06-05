#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int findPage(int pages[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (pages[i] == page) {
            return 1; // Page found in the frames
        }
    }
    return 0; // Page not found in the frames
}

void fifo(int pages[], int n, int frames) {
    int frameIndex = 0; // Current frame index
    int pageFaults = 0; // Count of page faults
    int frame[MAX_FRAMES]; // Array to store the frames

    for (int i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames with -1 indicating empty frames
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        if (!findPage(frame, frames, page)) {
            // Page fault: Page not found in the frames
            frame[frameIndex] = page;
            frameIndex = (frameIndex + 1) % frames; // Update frame index circularly
            pageFaults++;
              printf("Frames: ");
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    printf("- ");
                } else {
                    printf("%d ", frame[j]);
                }
            }
            printf("\n");
        
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

    fifo(pages, n, frames);

    return 0;
}
