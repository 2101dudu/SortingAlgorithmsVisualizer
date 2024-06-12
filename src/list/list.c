#include <stdio.h>
#include "../../include/list/list_utils.h"

void swap(LIST* in, int a, int b) {
    if(in->list == NULL || in->list_size < 0 || a > in->list_size || b > in->list_size) {
        perror("[ERROR 4] swap - NULL list or out-of-bounds");
        return;
    }

    NODE aux = in->list[a];
    in->list[a] = in->list[b]; 
    in->list[b] = aux;
}

void swap_and_highlight(LIST in, int i, int j, int* num_swaps) {
    int indexes[2] = {i, j}; 
    swap(&in, i, j);

    highlight_nodes(in, indexes, "Swap!");

    (*num_swaps)++;
}

void selection_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 7] bubble_sort - NULL list");
        return;
    }

    for(int i=0; i<in.list_size-1; i++) {

        int min_index = i;
        for(int j=i+1; j<in.list_size; j++) {
            if(compare_nodes(in.list[j], in.list[min_index]) < 0) {
                min_index = j;

                if(min_index != i)
                    swap(&in, i, min_index);
            }
        }
    }
}

void bubble_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 3] bubble_sort - NULL list");
        return;
    }

    for(int i=0; i<in.list_size-1; i++) 
        for(int j=0; j<in.list_size-i-1; j++) 
            if(compare_nodes(in.list[j], in.list[j+1]) > 0) 
                swap(&in, j, j+1);
}




void step_bubble_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 5] step_bubble_sort - NULL list");
        return;
    }

    int num_comparisons = 0, num_swaps = 0;
    for(int i=0; i<in.list_size-1; i++) {
        for(int j=0; j<in.list_size-i-1; j++, num_comparisons++) {
            int indexes[2] = {j, j+1}; 

            printf("--------Bubble Sort--------\n");
            highlight_nodes(in, indexes, NULL);

            if(compare_nodes(in.list[j], in.list[j+1]) > 0) swap_and_highlight(in, j, j+1, &num_swaps);
            
            printf("---------------------------\n");
            getchar();
        }
    }
    
    print_info(num_swaps, num_comparisons, in.list_size);
}

void step_selection_sort(LIST in) {
    if(in.list == NULL || in.list_size < 0) {
        perror("[ERROR 6] bubble_sort - NULL list");
        return;
    }

    int num_comparisons = 0, num_swaps = 0;
    for(int i=0; i<in.list_size-1; i++) {

        int min_index = i;
        for(int j=i+1; j<in.list_size; j++, num_comparisons++) {
            int indexes[2] = {i, j}; 

            printf("--------Selection Sort--------\n");
            highlight_nodes(in, indexes, NULL);

            if(compare_nodes(in.list[j], in.list[min_index]) < 0) {
                min_index = j;

                int indexes[1] = {min_index}; 
                char message[40];
                sprintf(message, "New lower element");
                highlight_nodes(in, indexes, message);
            }
            printf("------------------------------\n");
            getchar();
        }

        if(min_index != i) {
            int indexes[2] = {i, min_index}; 

            printf("--------Selection Sort--------\n");
            highlight_nodes(in, indexes, "Because of new lower element");

            swap_and_highlight(in, i, min_index, &num_swaps);
            printf("------------------------------\n");
            getchar();
        }
    }

    print_info(num_swaps, num_comparisons, in.list_size);
}
