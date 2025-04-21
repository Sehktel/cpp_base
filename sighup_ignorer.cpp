#include <iostream>
#include <csignal>
#include <unistd.h>

// Обработчик сигнала SIGHUP
void sighup_handler(int signum) {
    // Вывод сообщения при получении сигнала SIGHUP
    std::cout << "Ha-ha-ha I will ignore {SIGHUP} signal" << std::endl;
}

int main() {
    // Установка пользовательского обработчика для сигнала SIGHUP
    if (signal(SIGHUP, sighup_handler) == SIG_ERR) {
        // Обработка ошибки установки обработчика сигнала
        std::cerr << "Error setting up SIGHUP signal handler" << std::endl;
        return 1;
    }

    // Бесконечный цикл для поддержания работы программы
    std::cout << "Program is running. Send SIGHUP signal to test." << std::endl;
    while(true) {
        // Приостановка выполнения программы для имитации длительной работы
        sleep(1);
    }

    return 0;
} 