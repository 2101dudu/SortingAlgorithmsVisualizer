#ifndef LIST_UTILS_H
#define LIST_UTILS_H


#define MAX_ITER 100
#define MAX_MESSAGE_SIZE 200


typedef enum data_type {
    INT,
    STRING
} DATA_TYPE;

typedef struct node {
    void* element;
    DATA_TYPE type;
} NODE;

typedef struct list {
    NODE* list;
    int list_size;
} LIST;

void print_list(LIST list);

void highlight_nodes(LIST in, int* index, char* message, int print_nodes);

void print_info(int num_swaps, int num_comparisons, int list_size);

int compare_nodes(NODE a, NODE b);

LIST create_node_list(void** elements, int list_size, DATA_TYPE type);

void free_node_list(LIST *list);

#endif
