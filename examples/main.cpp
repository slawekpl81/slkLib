#include <iostream>
#include <string>
#include "lib.hpp"

int main()
{
    slk_lib::clear_console();
    std::cout << "Hello C++\n";
    uint8_t x{slk_lib::random_int(3, 15, true)};
    for (; x > 0; x--)
    {
        std::string s(x, '*');
        s.resize(20);
        std::cout << s << std::endl;
    }
    return 0;
}
