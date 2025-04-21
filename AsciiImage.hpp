#ifndef ASCIIIMAGE_HPP
#define ASCIIIMAGE_HPP
#include <fstream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Prototype.hpp"


class AsciiImage final : public Prototype {
    std::vector<std::string> data;
    std::string filename;

public:
    explicit AsciiImage(std::string file) : filename(std::move(file)) {
        loadFromFile();
    }

    void loadFromFile() {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Невозможно открыть файл: " + filename);
        }

        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
    }

    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<AsciiImage>(*this);
    }

    void display() const override {
        for (const auto &line: data) {
            std::cout << line << '\n';
        }
    }
};

#endif //ASCIIIMAGE_HPP
