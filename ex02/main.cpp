
#include "Array.hpp"

#define MAX_VAL 750
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
    {
        std::cout << CYAN << "----My tests----" << RESET << std::endl;
        Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        std::cout << GREEN << "Testing normal behavior" << RESET << std::endl;
        std::cout << "Int Array:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl << std::endl;

        std::cout << GREEN << "Testing out of bounds" << RESET << std::endl;
        try {
            std::cout << intArray[10] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl << std::endl;
        }

        std::cout << GREEN << "Testing copy constructor and = operator" << RESET << std::endl;
        Array<int> copyArray(intArray);
        copyArray[0] = 42;

        std::cout << "Copy Array:" << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl << std::endl;

        std::cout << "Original Array after copy:" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }
    {
        std::cout << CYAN << "----Provided tests----" << RESET << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        std::cout << GREEN << "Copy constructor [OK]" << RESET << std::endl;
        std::cout << GREEN << "Testing out of bounds" << RESET << std::endl;
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }

    return 0;
}