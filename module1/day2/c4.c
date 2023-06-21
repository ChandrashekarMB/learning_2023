#include <stdio.h>
#include <ctype.h>

int find_char_type(char ch) {
    if (isalpha(ch)) {
        if (isupper(ch)) {
            return 1;  // 'A' to 'Z'
        } else {
            return 2;  // 'a' to 'z'
        }
    } else if (isdigit(ch)) {
        return 3;  // '0' to '9'
    } else if (isprint(ch)) {
        return 4;  // Any other printable symbol
    } else {
        return 5;  // Non-printable symbol
    }
}

int main() {
    char ch;
    
    printf("Enter a character: ");
    scanf(" %c", &ch);
    
    int type = find_char_type(ch);
    
    switch (type) {
        case 1:
            printf("Type: 'A' to 'Z'\n");
            break;
        case 2:
            printf("Type: 'a' to 'z'\n");
            break;
        case 3:
            printf("Type: '0' to '9'\n");
            break;
        case 4:
            printf("Type: Any other printable symbol\n");
            break;
        case 5:
            printf("Type: Non-printable symbol\n");
            break;
        default:
            printf("Invalid character type\n");
            break;
    }
    
    return 0;
}

