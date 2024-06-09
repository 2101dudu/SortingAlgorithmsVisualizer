#include "../include/utils.h"
#include <stdio.h>

void swap(LIST* in, int i, int j) {
    if(in->list == NULL || in->list_size < 0 || i > in->list_size || j > in->list_size) {
        perror("[ERROR 4] swap - NULL list or out-of-bounds");
        return;
    }

    int aux = in->list[i];
    in->list[i] = in->list[j]; 
    in->list[j] = aux;
}

void bubble_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 3] bubble_sort - NULL list");
        return;
    }

    for(int i=0; i<in.list_size; i++) {
        for(int j=i; j<in.list_size; j++) {
            if(in.list[j] < in.list[i]) {
                swap(&in, i, j);
            }
        }
    }
}


void wait_for_action(LIST in, int i, int j, int* num_swaps) {
    int indexes[2] = {i, j}; 
    char message[40];
    sprintf(message, "%d > %d?", in.list[i], in.list[j]);
    highlight_numbers(in, indexes, message);

    if(in.list[j] < in.list[i]) {
        swap(&in, i, j);

        sprintf(message, "swap!");
        highlight_numbers(in, indexes, message);

        (*num_swaps)++;
    }
}

void step_bubble_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 5] step_bubble_sort - NULL list");
        return;
    }

    int num_comparisons = 0, num_swaps = 0;
    for(int i=0; i<in.list_size; i++) {
        for(int j=i+1; j<in.list_size; j++, num_comparisons++) {
            printf("--------Bubble Sort--------\n");
            wait_for_action(in, i, j, &num_swaps);
            printf("---------------------------\n");
            getchar();
        }
    }

    printf("-----------Info-----------\n");
    printf("Number of swaps: %d\n", num_swaps);
    printf("Number of comparisons: %d\n", num_comparisons);
    printf("Length-to-comparisons index: %.3f\n", (double) num_comparisons/in.list_size);
    printf("--------------------------\n");

}
