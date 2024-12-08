#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <random>
#include <chrono>
#include <fstream>

namespace slk_lib
{
    void hello_slkLib();

    std::vector<std::string> split_string(const std::string &txt, const char delimeter);

    std::vector<std::string> get_lines_from_file(const std::string &file_name);

    // template <typename T>
    // void print_vector_info(const std::vector<T> &var)
    // {
    //     std::cout << "type: " << typeid(var[0]).name() << ", size:" << var.size() << " elements\n";
    // }

    // template <typename T>
    // void print_vector(const std::vector<T> &vec)
    // {
    //     int i{0};
    //     for (const auto e : vec)
    //     {
    //         std::cout << i++ << ": " << e << std::endl;
    //     }
    //     print_vector_info(vec);
    // }

    void clear_console();

    int random_int(const int min, const int max, bool seed_from_time);

    std::vector<int> random_vector_int(const int min, const int max, int vector_size, bool seed_from_time);
    std::vector<std::string> get_files_from_dir(const std::string &dir_path);
    std::string get_random_file(const std::string &dir_path);
};
