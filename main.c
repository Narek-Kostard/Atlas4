#include "dyn_array.h"
#include <stdio.h>
int main()
{
    int size = 0;
    int* arr = create_buffer();

    arr = push_back(arr, &size, 5);
    arr = push_back(arr, &size, 6);
    arr = push_back(arr, &size, 7);
    arr = push_back(arr, &size, 8);

    arr = push_front(arr, &size, 4);
    arr = push_front(arr, &size, 3);
    arr = push_front(arr, &size, 2);
    arr = push_front(arr, &size, 1);

    printf("Current_state: ");
    current_state(arr, size);
    putchar(10);


    arr = remove_element(arr, &size, 7);
    arr = remove_element(arr, &size, 5);
    arr = remove_element(arr, &size, 3);
    arr = remove_element(arr, &size, 1);

    printf("Current_state after removing: ");
    current_state(arr, size);
    putchar(10);

    return 0;
}

