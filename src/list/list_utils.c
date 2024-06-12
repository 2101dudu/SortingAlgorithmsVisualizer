#include "../../include/list/list_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_node(NODE node) {
    switch (node.type) {
        case INT: 
            printf("%d ", *(int*) (node.element));   
            break;
        case STRING: 
            printf("%s ", (char*) (node.element));   
            break;
        default: break;
    }
}

void print_list(LIST in) {
    if(in.list == NULL || in.list_size <= 0) {
        perror("[ERROR 1] print_list - NULL list");
        return;
    }
        
    for(int i=0; i<in.list_size; i++)
        print_node(in.list[i]);
    
    putchar('\n');
}

void print_info(int num_swaps, int num_comparisons, int list_size) {
    printf("------------Info-----------\n");
    printf("Number of swaps: %d\n", num_swaps);
    printf("Number of comparisons: %d\n", num_comparisons);
    printf("Length-to-comparisons index: %.3f\n", (double) num_comparisons/list_size);
    printf("---------------------------\n");
}

void highlight_nodes(LIST in, int* index, char* message) {
    if(in.list == NULL || in.list_size <= 0 || index == NULL) {
        perror("[ERROR 2] highlight_number - NULL list");
        return;
    }
        
    int j=0;
    for(int i=0; i<in.list_size; i++) {
        if(i == index[j]) {
            printf("$");
            print_node(in.list[i]);
            j++;
        } 
        else print_node(in.list[i]);
    }

    if(message != NULL) printf("(%s)", message);
    putchar('\n');
}

int compare_nodes(NODE a, NODE b) {
    if (a.type != b.type) {
        perror("[ERROR 10] compare_nodes - mismatch type");
        return -999; // ERROR code
    }

    switch (a.type) {
        case INT:
            if (*(int*)a.element < *(int*)b.element) return -1;
            if (*(int*)a.element > *(int*)b.element) return 1;
            return 0;
        case STRING:
            return strcmp((char*)a.element, (char*)b.element);
        default:
            perror("[ERROR 11] compare_nodes - unknown type");
            return -999; // ERROR code for unknown type
    }
}


LIST create_node_list(void** elements, int list_size, DATA_TYPE type) {
    LIST new;
    new.list = (NODE*)malloc(list_size * sizeof(NODE));
    new.list_size = list_size;

    for(int i=0; i<list_size; i++) {
        if(type == INT) {
            new.list[i].element = malloc(sizeof(int));
            *(int*)new.list[i].element = *(int*)elements[i];
        }
        else if(type == STRING) {
            new.list[i].element = malloc(strlen((char*)elements[i]) * sizeof(char));
            strcpy((char*)new.list[i].element, (char*)elements[i]);
        }
        new.list[i].type = type;
    }

    return new;
}

void free_node_list(LIST *list) {
    for(int i=0; i<list->list_size; i++) {
        free(list->list[i].element);
    }
    free(list->list);
    list->list_size = 0;
    list->list = NULL;
}
