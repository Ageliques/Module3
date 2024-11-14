#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 256
#define MAX_ARGS 10

int main() {
    char input[MAX_INPUT];
    
    while (1) {
        printf("Введите команду (sum, max) или 'exit' для выхода: ");
        fgets(input, sizeof(input), stdin);
        
        // Удаляем символ новой строки
        input[strcspn(input, "\n")] = 0;

        char *args[MAX_ARGS];
        int argc = 0;

        // Разделяем ввод на аргументы
        char *token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }

        if (argc > 0) {
            args[argc] = NULL; // Завершаем массив аргументов NULL
            if (strcmp(args[0], "exit") == 0) {
            printf("Выход из программы...\n");
            break; // Завершение цикла
            }
            // Запускаем программу с аргументами
            if (fork() == 0) {
                execvp(args[0], args);
                perror("Ошибка запуска программы");
                exit(1);
            } else {
                wait(NULL); // Ожидание завершения дочернего процесса
            }
        }
    }

    return 0;
}

