// DataFrame.hpp (Header file)

#ifndef DATAFRAME_HPP
#define DATAFRAME_HPP

#include <vector>
#include <string>

class DataFrame {
public:
    DataFrame();

    bool read_csv(const std::string& filepath, char sep = ',');

    void print_data() const;

private:
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> data;

    void process_header(const std::string& line, char sep);
    void process_row(const std::string& line, char sep);
};

#endif // DATAFRAME_HPP
