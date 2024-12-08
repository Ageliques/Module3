#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];
     socklen_t client_addr_size = sizeof(client_addr);

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(sock, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Сервер запущен. Ожидание сообщений...\n");

    while (1) {
        int recv_len = recvfrom(sock, buffer, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_size);
if (recv_len == -1) {
    perror("Ошибка получения данных");
    break;
}
buffer[recv_len] = '\0';  // Завершение строки
printf("Сообщение от клиента: %s\n", buffer);
if (strcmp(buffer, "exit") == 0) {
    printf("Клиент завершил сеанс.\n");
    break;
}
// Ответ сервером
printf("Ваш ответ: ");
fgets(buffer, BUF_SIZE, stdin);
buffer[strcspn(buffer, "\n")] = '\0';  // Удаление символа новой строки
sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, client_addr_size);
if (strcmp(buffer, "exit") == 0) {
    printf("Завершение работы сервера.\n");
    break;
}
    }

    close(sock);
    return 0;
}
