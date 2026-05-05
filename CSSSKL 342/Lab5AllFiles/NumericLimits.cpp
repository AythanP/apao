#include <iostream>
#include <limits>

int main() {
    std::cout << "Min value of int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Max value of int: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "Min value of unsigned int: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "Max value of unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout << "Min value of long: " << std::numeric_limits<long>::min() << std::endl;
    std::cout << "Max value of long: " << std::numeric_limits<long>::max() << std::endl;

    std::cout << "Min value of double: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Max value of double: " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "Min value of float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Max value of float: " << std::numeric_limits<float>::max() << std::endl;

    std::cout << "Min value of char32_t: " << std::numeric_limits<char32_t>::min() << std::endl;
    std::cout << "Max value of char32_t: " << std::numeric_limits<char32_t>::max() << std::endl;

    std::cout << "Min value of size_t: " << std::numeric_limits<size_t>::min() << std::endl;
    std::cout << "Max value of size_t: " << std::numeric_limits<size_t>::max() << std::endl;
}