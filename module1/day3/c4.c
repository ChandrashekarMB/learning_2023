#include <stdio.h>
#include <limits.h>

void find_smallest_and_largest_digits(int *numbers, int count, int *smallest, int *largest) {
    *smallest = INT_MAX;
    *largest = INT_MIN;

    for (int i = 0; i < count; i++) {
        int num = numbers[i];
        while (num != 0) {
            int digit = num % 10;
            if (digit < *smallest) {
                *smallest = digit;
            }
            if (digit > *largest) {
                *largest = digit;
            }
            num /= 10;
        }
    }
}

int main() {
    int n = 3;
    int numbers[] = {8, 156, 123450};
    int smallest, largest;

    find_smallest_and_largest_digits(numbers, n, &smallest, &largest);

    if (smallest == INT_MAX || largest == INT_MIN) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    }

    return 0;
}

