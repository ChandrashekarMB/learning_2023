#include <stdio.h>

// Structure definition for a point
struct Point {
    int x;
    int y;
};

// Function to swap the fields of two points using pointers
void swap_points(struct Point *p1, struct Point *p2) {
    // Swap the x values
    int temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;

    // Swap the y values
    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}

int main() {
    struct Point point1, point2;

    // Read the values for point1 from the user
    printf("Enter the x coordinate for point 1: ");
    scanf("%d", &point1.x);
    printf("Enter the y coordinate for point 1: ");
    scanf("%d", &point1.y);

    // Read the values for point2 from the user
    printf("Enter the x coordinate for point 2: ");
    scanf("%d", &point2.x);
    printf("Enter the y coordinate for point 2: ");
    scanf("%d", &point2.y);

    // Print the original values
    printf("Before swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    // Swap the fields of the two points
    swap_points(&point1, &point2);

    // Print the swapped values
    printf("After swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    return 0;
}

