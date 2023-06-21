#include <stdio.h>

int sum_alternate_elements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = sum_alternate_elements(arr, size);
    printf("Sum of alternate elements: %d\n", result);

    return 0;
}

