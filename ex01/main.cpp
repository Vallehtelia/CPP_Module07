
#include "iter.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T>
struct Test
{
    int value;
    Test(int v) : value(v) {}
};

template <typename T>
void    printTest(Test<T> const &x)
{
    std::cout << x.value << std::endl;
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const char *stringArray[] = {"Hello", "World", "42"};
    const int constIntArray[] = {1, 2, 3, 4, 5};
    Test<int> testArray[] = {Test<int>(11), Test<int>(12), Test<int>(13), Test<int>(14), Test<int>(15)};

    std::cout << CYAN << "Int array: " << RESET << std::endl;
    iter(intArray, 5, print);
    std::cout << CYAN << "Char array: " << RESET << std::endl;
    iter(charArray, 5, print);
    std::cout << CYAN << "Float array: " << RESET << std::endl;
    iter(floatArray, 5, print);
    std::cout << CYAN << "const String array: " << RESET << std::endl;
    iter(stringArray, 3, print);
    std::cout << CYAN << "const Int array: " << RESET << std::endl;
    iter(constIntArray, 5, print);
    std::cout << CYAN << "String array: " << RESET << std::endl;
    iter(testArray, 5, printTest);

    return 0;
}