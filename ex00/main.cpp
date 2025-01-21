
#include "whatever.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

int main( void )
{
    {
        std::cout << CYAN << "Test with int and string" << RESET << std::endl;
        int a = 2;
        int b = 3;

        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    {
        std::cout << CYAN << "\nTest with const values" << RESET << std::endl;
        const int a = 2;
        const int b = 3;

        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        const std::string c = "chaine1";
        const std::string d = "chaine2";
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return 0;
}