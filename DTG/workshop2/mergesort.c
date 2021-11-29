//Implementing merge and mergesort

#include <stdio.h>
#include <stdlib.h>

void merge(int list[], int start, int end, int mid);
void mergesort(int list[], int start, int end);
void printList(int list[], int size);

int main(void) {
    int list[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
    int list_size = sizeof(list) / sizeof(list[0]);

    printf("Given list \n");
    printList(list, list_size);

    mergesort(list, 0, list_size - 1);

    printf("The sorted list \n");
    printList(list, list_size);
    return 0;
}

void merge(int list[], int start, int mid, int end) {
     
    int array1_size = mid - start + 1; 
    int array2_size = end - mid;

    //Lower and upper temp arrays
    int lower_list[array1_size];
    int upper_list[array2_size];
    
    //Puts the data list into the new arrays
    for (int lower_list_loc = 0; lower_list_loc < array1_size; lower_list_loc++) {
        lower_list[lower_list_loc] = list[start + lower_list_loc];
    }
    for (int upper_list_log = 0; upper_list_log < array2_size; upper_list_log++) {
        upper_list[upper_list_log] = list[mid + 1 + upper_list_log];
    }
    
    int lower_list_loc = 0;
    int upper_list_loc = 0;
    int k = start;

    //Looks at the first two values of the arrays and stores the smallest one in the list
    while (lower_list_loc < array1_size && upper_list_loc < array2_size) {
        if (lower_list[lower_list_loc] <= upper_list[upper_list_loc]) {
            list[k] = lower_list[lower_list_loc];
            lower_list_loc++;
        }
        else {
            list[k] = upper_list[upper_list_loc];
            upper_list_loc++;
        }  
    k++;
    }
    
    while (lower_list_loc < array1_size) {
        list[k] = lower_list[lower_list_loc];
        lower_list_loc++;
        k++;
    }
    
    while (upper_list_loc < array2_size) {
        list[k] = upper_list[upper_list_loc];
        upper_list_loc++;
        k++;
    }
}

void mergesort(int list[], int start, int end) {
    if(start < end) {
        int temp_mid = (end + start) / 2;
        mergesort(list, start, temp_mid);
        mergesort(list, temp_mid + 1, end);
        merge(list, start, temp_mid, end);
    }
}

void printList(int list[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}