#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void calculate_area(float side_length) {
    float area = side_length * side_length;
    printf("Side: %.2f, Square: %.2f\n", side_length, area);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Use: %s <side1> <side2> ...n", argv[0]);
        return 1;
    }

    int num_sides = argc - 1 ;
    printf("num_sides: %d \n", num_sides);
    int mid_index = num_sides / 2;
    printf("MID: %d \n", mid_index);
    pid_t pid = fork();

    if (pid < 0) {
        // Ошибка при создании процесса
        perror("Error fork");
        return 1;
    } else if (pid == 0) {
        // Дочерний процесс
        for (int i = mid_index; i < num_sides; i++) {
            float side_length = atof(argv[i + 1]); // +1 из-за argv[0]
            calculate_area(side_length);
            printf("Doughter\n");
        }
        exit(0); // Завершение дочернего процесса
    } else {
        // Родительский процесс
        for (int i = 1; i <= mid_index; i++) {
            float side_length = atof(argv[i]);
            calculate_area(side_length);
            printf("Parent\n");
        }

        // Ожидание завершения дочернего процесса
        //wait(NULL);
    }

    return 0;
}
