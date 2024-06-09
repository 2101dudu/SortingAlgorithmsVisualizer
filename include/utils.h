#define MAX_ITER 100

typedef struct list {
    int *list;
    int list_size;
} LIST;

void print_list(LIST list);

void highlight_numbers(LIST in, int* index, char* message);
