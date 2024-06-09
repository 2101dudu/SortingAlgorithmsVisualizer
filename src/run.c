//#include <raylib.h>
#include "../include/sort.h"


int main(int argc, char **argv) {

    LIST test;
    int list[6] = {1, 4, 2, 6, 7, 3};
    test.list = list;
    test.list_size = 6;

    int indexes[2] = {1, 2};
    step_bubble_sort(test);


    return 0;
}
