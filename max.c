#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Нет аргументов для поиска максимального значения.\n");
        return 1;
    }
    int max_value = atoi(argv[1]);
    for (int i = 2; i < argc; i++) {
        int current_value = atoi(argv[i]);
        if (current_value > max_value) {
            max_value = current_value;
        }
    }
    printf("Max: %d\n", max_value);
    return 0;
}
