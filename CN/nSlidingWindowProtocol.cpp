#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL_FRAMES 10

void go_back_n(int window_size) {
    int base = 0;
    int next_seq = 0;
    int frames[TOTAL_FRAMES];
    int sent_count = 0;
    int ack_count = 0;

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i;
    }

    while (base < TOTAL_FRAMES) {
        while (next_seq < base + window_size && next_seq < TOTAL_FRAMES) {
            printf("Sending frame %d\n", frames[next_seq]);
            next_seq++;
            sent_count++;
        }

        int ack = base + rand() % (next_seq - base);
        sleep(1);
        printf("Received ACK for frame %d\n", ack);
        ack_count++;

        base = ack + 1;
    }
    printf("All frames acknowledged in Go-Back-N.\n");
    printf("Total frames sent: %d\n", sent_count);
    printf("Total ACKs received: %d\n", ack_count);
}

void selective_repeat(int window_size) {
    int base = 0;
    int next_seq = 0;
    int frames[TOTAL_FRAMES];
    int ack_received[TOTAL_FRAMES] = {0};
    int sent_count = 0;
    int ack_count = 0;

    for (int i = 0; i < TOTAL_FRAMES; i++) {
        frames[i] = i;
    }

    while (base < TOTAL_FRAMES) {
        while (next_seq < base + window_size && next_seq < TOTAL_FRAMES) {
            printf("Sending frame %d\n", frames[next_seq]);
            next_seq++;
            sent_count++;
        }

        int ack = base + rand() % window_size;
        sleep(1);
        printf("Received ACK for frame %d\n", ack);
        ack_count++;

        ack_received[ack] = 1;

        while (ack_received[base]) {
            base++;
        }
    }
    printf("All frames acknowledged in Selective Repeat.\n");
    printf("Total frames sent: %d\n", sent_count);
    printf("Total ACKs received: %d\n", ack_count);
}

void menu() {
    int choice, window_size;

    while (true) {
        printf("\n********* Sliding Window Protocols *********\n");
        printf("1. Go-Back-N Protocol\n");
        printf("2. Selective Repeat Protocol\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program...\n");
            break;
        }

        if (choice == 1 || choice == 2) {
            printf("Enter the window size (1-%d): ", TOTAL_FRAMES);
            scanf("%d", &window_size);

            if (window_size <= 0 || window_size > TOTAL_FRAMES) {
                printf("Invalid window size! Please enter a value between 1 and %d.\n", TOTAL_FRAMES);
                continue;
            }

            if (choice == 1) {
                go_back_n(window_size);
            } else if (choice == 2) {
                selective_repeat(window_size);
            }
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    srand(time(0));
    menu();
    return 0;
}
