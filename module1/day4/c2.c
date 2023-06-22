#include <stdio.h>

// Structure definition for a complex number
struct Complex {
    double real;
    double imag;
};

// Function to read a complex number from the user
struct Complex read_complex() {
    struct Complex num;
    printf("Enter the real part: ");
    scanf("%lf", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%lf", &num.imag);
    return num;
}

// Function to write a complex number
void write_complex(struct Complex num) {
    printf("Complex number: %.2lf + %.2lfi\n", num.real, num.imag);
}

// Function to add two complex numbers
struct Complex add_complex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply_complex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Read the complex numbers from the user
    printf("Enter the first complex number:\n");
    num1 = read_complex();

    printf("Enter the second complex number:\n");
    num2 = read_complex();

    // Write the complex numbers
    printf("First complex number:\n");
    write_complex(num1);

    printf("Second complex number:\n");
    write_complex(num2);

    // Perform addition of complex numbers
    sum = add_complex(num1, num2);
    printf("Sum of complex numbers:\n");
    write_complex(sum);

    // Perform multiplication of complex numbers
    product = multiply_complex(num1, num2);
    printf("Product of complex numbers:\n");
    write_complex(product);

    return 0;
}

