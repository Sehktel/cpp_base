#include <iostream>
#include <cassert>
#include <stdexcept>
#include <vector>

// Функция для демонстрации простых математических утверждений
int divide(int numerator, int denominator) {
    // Проверка недопустимости деления на ноль
    assert(denominator != 0 && "Знаменатель не может быть равен нулю");
    return numerator / denominator;
}

// Функция для проверки инвариантов контейнера
void process_vector(std::vector<int>& vec) {
    // Утверждение о непустоте вектора перед обработкой
    assert(!vec.empty() && "Вектор не должен быть пустым");
    
    // Симуляция обработки вектора
    for (auto& elem : vec) {
        elem *= 2;
    }
}

// Функция для демонстрации проверки предусловий
class TemperatureConverter {
private:
    double celsius;

public:
    void setCelsius(double temp) {
        // Проверка допустимого диапазона температуры
        assert(temp >= -273.15 && "Температура не может быть ниже абсолютного нуля");
        celsius = temp;
    }

    double toFahrenheit() {
        // Проверка инициализации температуры
        assert(celsius != 0.0 && "Температура не была установлена");
        return (celsius * 9.0/5.0) + 32.0;
    }
};

int main() {
    try {
        // Демонстрация assert с делением
        std::cout << "Деление: " << divide(10, 2) << std::endl;
        
        // Этот вызов вызовет ошибку assert
        // divide(10, 0);  // Раскомментируйте для проверки

        // Демонстрация assert с вектором
        std::vector<int> numbers = {1, 2, 3, 4, 5};
        process_vector(numbers);
        
        // Вывод обработанного вектора
        std::cout << "Обработанный вектор: ";
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Демонстрация assert с преобразованием температуры
        TemperatureConverter converter;
        converter.setCelsius(25.0);
        std::cout << "Температура в Фаренгейтах: " << converter.toFahrenheit() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Перехвачено исключение: " << e.what() << std::endl;
    }

    return 0;
} 