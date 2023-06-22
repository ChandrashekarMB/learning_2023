#include <stdio.h>

// Structure definition for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of the box
double calculate_volume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of the box
double calculate_surface_area(struct Box* box) {
    double top_bottom = 2 * (box->length * box->width);
    double front_back = 2 * (box->length * box->height);
    double left_right = 2 * (box->width * box->height);
    return top_bottom + front_back + left_right;
}

int main() {
    // Declare a box structure variable
    struct Box myBox;

    // Initialize the box dimensions
    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 2.0;

    // Access structure members using (*) and (.)
    double volume = calculate_volume(&myBox);
    double surface_area = calculate_surface_area(&myBox);

    printf("Using (*) and (.) operators:\n");
    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surface_area);

    // Access structure members using (->) and (.)
    struct Box* boxPtr = &myBox;
    volume = boxPtr->length * boxPtr->width * boxPtr->height;
    surface_area = calculate_surface_area(boxPtr);

    printf("Using (->) and (.) operators:\n");
    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surface_area);

    return 0;
}

