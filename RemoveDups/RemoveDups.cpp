#include <iostream>
#include <cstring>

void RemoveDups(char* str) {
    if (str == NULL || strlen(str) < 2) return;
    int size = strlen(str);
    int i = 1;
    char c = tolower(str[0]);
    while (i < size) {
        if (c == tolower(str[i])) {
            size--;
            memmove(str + i, str + ( i + 1), size);
            continue;
        } else {
            c = tolower(str[i]);
        }
        i++;
    }
}

int main() {
    char data[] = "AAA BBB AAA";
    printf("For \"%s\" result is\n", data);
    RemoveDups(data);
    printf("%s\n", data);

    char data2[] = "AAa BBb AAa";
    printf("For \"%s\" result is\n", data2);
    RemoveDups(data2);
    printf("%s\n", data2);

    char data3[] = "AaA BbB AaA";
    printf("For \"%s\" result is\n", data3);
    RemoveDups(data3);
    printf("%s\n", data3);

    return 0;
}