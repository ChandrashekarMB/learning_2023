#include <stdio.h>

int count_set_bits(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int num = arr[i];
        while (num > 0) {
            if (num & 1) {
                count++;
            }
            num >>= 1;
        }
    }

    return count;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = count_set_bits(arr, size);
    printf("Total number of set bits: %d\n", result);

    return 0;
}

