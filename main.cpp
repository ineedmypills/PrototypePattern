#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <Windows.h>

#include "AsciiImage.hpp"
#include "PrototypeRegistry.hpp"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        PrototypeRegistry registry;

        registry.registerPrototype("1", std::make_unique<AsciiImage>("image1.txt"));
        registry.registerPrototype("2", std::make_unique<AsciiImage>("image2.txt"));
        registry.registerPrototype("3", std::make_unique<AsciiImage>("image3.txt"));

        std::cout << "Изображения:\n"
                << "1 - Котик\n"
                << "2 - Анимешка\n"
                << "3 - Сердешко\n"
                << "Выберите: ";

        std::string choice;
        std::cin >> choice;

        const auto image = registry.clonePrototype(choice);
        if (!image) {
            std::cerr << "Неверный выбор!\n";
            return 1;
        }

        std::cout << "\nИзображение:\n";
        image->display();
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
