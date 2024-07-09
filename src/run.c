//#include <raylib.h>
#include "../include/list/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show(char **opcoes, int size) {
    printf("-------------Menu------------\n");
    for(int i=0; i < size; i++) {
        printf("%d - %s\n", i+1, opcoes[i]);
    }
    printf("-----------------------------\n\n");
}

int read_option(int size) {
    int op;

    printf("Option: \n");

    char in[MAX_MESSAGE_SIZE];
    read(STDIN_FILENO, &in, MAX_MESSAGE_SIZE);

    op = atoi(in);
    if(op < 1 || op > size) {
        op = -1;
        printf("[ERROR] Invalid option, try again!\n");
    }

    return op;
}

int run(char** opcoes, int size) {
    int op;
    do {
        show(opcoes, size);
        op = read_option(size);
    } while(op == -1);

    return op;
}


int main(int argc, char **argv) {
    //int int_elements[] = {1, 4, 2, 6, 7, 3};
    char *str_elements[] = {"cherry", "banana", "date", "fig", "apple", "grape"};
    void *str_ptrs[6];
    for (size_t i = 0; i < 6; ++i) {
        str_ptrs[i] = str_elements[i];
    }
    LIST new = create_node_list(str_ptrs, 6, STRING);


    char* opcoes[3] = {"Bubble sort", "Selection sort", "Insertion sort"};
    int op = run(opcoes, 3);

    switch(op) {
        case 1:
            step_bubble_sort(new);
            break;
        case 2:
            step_selection_sort(new);
            break;
        case 3:
            step_insertion_sort(new);
            break;
        default: break;
    }

    free_node_list(&new);

    return 0;
}
