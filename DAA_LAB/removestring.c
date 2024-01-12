#include <stdio.h>
#include <string.h>

void removeSubstring(char *str, const char *sub) {
    int len = strlen(sub);
    char *ptr;

    // Repeat until the substring is found in the string
    while ((ptr = strstr(str, sub)) != NULL) {
        // Copy characters before the substring
        strncpy(ptr, ptr + len, strlen(ptr + len) + 1);
    }
}

int main() {
    char mainString[] = "Hello, Hello, World!";
    const char substring[] = "Hello";

    printf("Original string: %s\n", mainString);

    // Remove all occurrences of the substring
    removeSubstring(mainString, substring);

    printf("String after removing '%s': %s\n", substring, mainString);

    return 0;
}
