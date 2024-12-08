#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <random>
#include <chrono>
#include <filesystem>
#include "lib.hpp"

void slk_lib::hello_slkLib()
{
    std::cout << "Hello slkLib\n";
}

std::vector<std::string> slk_lib::split_string(const std::string &txt, const char delimeter = ',')
{
    std::stringstream ss{txt};
    std::string temp;
    std::vector<std::string> out_data;
    while (getline(ss, temp, delimeter))
    {
        out_data.push_back(temp);
    }
    return out_data;
}
std::vector<std::string> slk_lib::get_lines_from_file(const std::string &file_name)
{
    std::ifstream file(file_name);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line))
    {
        // std::cout << line << std::endl;
        lines.push_back(line);
    }

    file.close();
    return lines;
}

void slk_lib::clear_console()
{
    std::system("clear");
}

int slk_lib::random_int(const int min, const int max, bool seed_from_time = true)
{
    std::mt19937 gen;

    if (seed_from_time)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed); // Seed the generator
    }
    else
    {
        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Seed the generator
    }
    std::uniform_int_distribution<> distr(min, max); // Define the range

    int random_number = distr(gen); // Generate a random number between 0 and 99
    // std::cout << "Random number: " << random_number << std::endl;
    return random_number;
}

std::vector<int> slk_lib::random_vector_int(const int min, const int max, int vector_size, bool seed_from_time = true)
{
    std::mt19937 gen;

    if (seed_from_time)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed); // Seed the generator
    }
    else
    {
        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Seed the generator
    }
    std::vector<int> vec;

    std::uniform_int_distribution<> distr(min, max); // Define the range
    while (vector_size--)
        vec.push_back(distr(gen)); // Generate a random number between 0 and 99
    // std::cout << "Random number: " << random_number << std::endl;
    return vec;
}

std::vector<std::string> slk_lib::get_files_from_dir(const std::string &dir_path)
{
    std::vector<std::string> files;
    for (const auto &entry : std::filesystem::directory_iterator(dir_path))
    {
        if (std::filesystem::is_regular_file(entry))
        {
            // std::cout << entry.path() << std::endl;
            files.push_back(entry.path());
        }
    }
    return files;
}

std::string slk_lib::get_random_file(const std::string &dir_path)
{
    // std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    auto files = get_files_from_dir(dir_path);
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

    // Generate a random index within the vector's bounds
    int random_index = std::rand() % files.size();

    // Access the random word
    std::string random_file = files[random_index];

    // std::cout << "Random word: " << random_word << std::endl;
    return random_file;
};
