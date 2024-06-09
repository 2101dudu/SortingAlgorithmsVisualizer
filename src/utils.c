#include "../include/utils.h"
#include <stdio.h>


void print_list(LIST in) {
    if(in.list == NULL || in.list_size <= 0) {
        perror("[ERROR 1] print_list - NULL list");
        return;
    }
        
    for(int i=0; i<in.list_size; i++) {
        printf("%d ", in.list[i]);
    }
    putchar('\n');
}


void highlight_numbers(LIST in, int* index, char* message) {
    if(in.list == NULL || in.list_size <= 0 || index == NULL){
        perror("[ERROR 2] highlight_number - NULL list");
        return;
    }
        
    int j=0;
    for(int i=0; i<in.list_size; i++) {
        if(i == index[j]) {
            printf("[%d] ", in.list[i]);
            j++;
        } 
        else printf("%d ", in.list[i]);
    }
    if(message != NULL) printf("(%s)", message);
    putchar('\n');
}
