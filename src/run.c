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

    int int_elements[] = {1, 4, 2, 6, 7, 3};
    void *int_ptrs[6];
    for (size_t i = 0; i < 6; ++i) {
        int_ptrs[i] = &int_elements[i];
    }

    LIST new = create_node_list(int_ptrs, 6, INT);


    char* opcoes[2] = {"Bubble sort", "Selection sort"};
    int op = run(opcoes, 2);

    switch(op) {
        case 1:
            step_bubble_sort(new);
            break;
        case 2:
            step_selection_sort(new);
            break;
        default: break;
    }

    return 0;
}
