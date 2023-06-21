#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *p = a;
    unsigned char *q = b;

    for (size_t i = 0; i < size; ++i) {
        unsigned char temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

int main() {
    int num1 = 10;
    int num2 = 20;

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    double d1 = 3.14;
    double d2 = 6.28;

    printf("Before swap: d1 = %lf, d2 = %lf\n", d1, d2);
    swap(&d1, &d2, sizeof(double));
    printf("After swap: d1 = %lf, d2 = %lf\n", d1, d2);

    char ch1 = 'A';
    char ch2 = 'B';

    printf("Before swap: ch1 = %c, ch2 = %c\n", ch1, ch2);
    swap(&ch1, &ch2, sizeof(char));
    printf("After swap: ch1 = %c, ch2 = %c\n", ch1, ch2);

    return 0;
}

