#include <stdio.h>

int find_largest_number(int num) {
    char num_str[5];
    sprintf(num_str, "%d", num);
    int max_num = -1;

    for (int i = 0; i < 4; i++) {
        char temp_str[5];
        int index = 0;
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                temp_str[index++] = num_str[j];
            }
        }
        temp_str[index] = '\0';
        int current_num = atoi(temp_str);
        if (current_num > max_num) {
            max_num = current_num;
        }
    }

    return max_num;
}

int main() {
    int number;
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);
    int largest_number = find_largest_number(number);
    printf("Largest number by deleting a single digit from %d is %d\n", number, largest_number);
    return 0;
}

