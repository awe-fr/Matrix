#include <Vector.hpp>
#include <Matrix.hpp>
#include <iostream>

void    ex00() {
    std::cout << "|| ---------- Ex 00 ---------- ||" << std::endl;
    std::cout << "        -> Addition" << std::endl << std::endl;

    pml::vec<int, 3> v1 = {1, 2, 3};
    pml::vec<int, 3> v2 = {4, 5, 6};

    std::cout << "v1: " << v1 << std::endl << "v2: " << v2 << std::endl << std::endl;

    std::cout << "v1 + v2: " << v1 + v2 << std::endl;
    v1 += v2;
    std::cout << "v1 += v2: " << v1 << std::endl;

    std::cout << std::endl;

    std::cout << "        -> subtraction" << std::endl << std::endl;

    std::cout << "v1: " << v1 << std::endl << "v2: " << v2 << std::endl << std::endl;

    std::cout << "v1 - v2: " << v1 - v2 << std::endl;
    v1 -= v2;
    std::cout << "v1 -= v2: " << v1 << std::endl;

    std::cout << std::endl;

    std::cout << "        -> scalar multiplication" << std::endl << std::endl;

    int scalar = 2;

    std::cout << "v1: " << v1 << std::endl << "scalar: " << scalar << std::endl << std::endl;

    std::cout << "v1 * scalar: " << v1 * scalar << std::endl;
    v1 *= scalar;
    std::cout << "v1 *= scalar: " << v1 << std::endl;
}

int main() {
    ex00();

    return 0;
}

