// DataFrame.cpp (Implementation file)

#include "./DataFrame.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

DataFrame::DataFrame() {}

bool DataFrame::read_csv(const std::string& filepath, char sep) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    if (std::getline(file, line)) {
        process_header(line, sep);
    }

    while (std::getline(file, line)) {
        process_row(line, sep);
    }

    return true;
}

void DataFrame::process_header(const std::string& line, char sep) {
    std::istringstream ss(line);
    std::string token;
    while (std::getline(ss, token, sep)) {
        columns.push_back(token);
        data.push_back({});
    }
}

void DataFrame::process_row(const std::string& line, char sep) {
    std::istringstream ss(line);
    std::string token;
    size_t colIdx = 0;
    while (std::getline(ss, token, sep)) {
        if (colIdx < columns.size()) {
            data[colIdx].push_back(token);
            colIdx++;
        }
    }
}

void DataFrame::print_data() const {
    for (size_t i = 0; i < columns.size(); ++i) {
        std::cout << columns[i] << ": ";
        for (const std::string& value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
