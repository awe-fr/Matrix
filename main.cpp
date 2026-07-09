#include <Vector.hpp>
#include <Matrix.hpp>
#include <iostream>

void    ex00() {
    std::cout << "|| ---------- Ex 00 ---------- ||" << std::endl;
    std::cout << "        -> Addition" << std::endl << std::endl;

    pml::vec<int, 3> v1 = {1, 2, 3};
    pml::vec<int, 3> v2 = {4, 5, 6};

    pml::mat<int, 2, 3> m1 = {{1, 2, 3}, {4, 5, 6}};
    pml::mat<int, 2, 3> m2 = {{7, 8, 9}, {10, 11, 12}};

    std::cout << "v1: " << v1 << std::endl << "v2: " << v2 << std::endl << std::endl;

    std::cout << "v1 + v2: " << v1 + v2 << std::endl;
    v1 += v2;
    std::cout << "v1 += v2: " << v1 << std::endl;

    std::cout << std::endl;

    std::cout << "m1: " << std::endl << m1 << std::endl << std::endl;
    std::cout << "m2: " << std::endl << m2 << std::endl << std::endl;

    std::cout << "m1 + m2: " << std::endl << m1 + m2 << std::endl;
    m1 += m2;
    std::cout << "m1 += m2: " << std::endl << m1 << std::endl;

    std::cout << std::endl;

    std::cout << "        -> subtraction" << std::endl << std::endl;

    std::cout << "v1: " << v1 << std::endl << "v2: " << v2 << std::endl << std::endl;

    std::cout << "v1 - v2: " << v1 - v2 << std::endl;
    v1 -= v2;
    std::cout << "v1 -= v2: " << v1 << std::endl;

    std::cout << std::endl;

    std::cout << "m1: " << std::endl << m1 << std::endl << std::endl;
    std::cout << "m2: " << std::endl << m2 << std::endl << std::endl;

    std::cout << "m1 - m2: " << std::endl << m1 - m2 << std::endl;
    m1 -= m2;
    std::cout << "m1 -= m2: " << std::endl << m1 << std::endl;

    std::cout << std::endl;

    std::cout << "        -> scalar multiplication" << std::endl << std::endl;

    int scalar = 2;

    std::cout << "v1: " << v1 << std::endl << "scalar: " << scalar << std::endl << std::endl;

    std::cout << "v1 * scalar: " << v1 * scalar << std::endl;
    v1 *= scalar;
    std::cout << "v1 *= scalar: " << v1 << std::endl;
    
    std::cout << std::endl;

    std::cout << "m1: " << std::endl << m1 << std::endl << std::endl;

    std::cout << "m1 * scalar " << std::endl << m1 * scalar << std::endl;
    m1 *= scalar;
    std::cout << "m1 *= scalar: " << std::endl << m1 << std::endl;
}

void ex01() {
    std::cout << "|| ---------- Ex 01 ---------- ||" << std::endl;
    std::cout << "        -> Linear Combination" << std::endl << std::endl;

    pml::vec<int, 3> v1 = {1, 2, 3};
    pml::vec<int, 3> v2 = {4, 5, 6};
    pml::vec<int, 3> v3 = {7, 8, 9};
    std::vector<pml::vec<int, 3>> vectors = {v1, v2, v3};
    std::cout << "V1: " << v1 << std::endl;
    std::cout << "V2: " << v2 << std::endl;
    std::cout << "V3: " << v3 << std::endl;

    std::vector<int> scalars = {2, -1, 3};
    std::cout << "Scalars: " << scalars[0] << " " << scalars[1] << " " << scalars[2] << std::endl;

    pml::vec<int, 3> result = pml::linear_combination(vectors, scalars);

    std::cout << std::endl << std::endl;

    std::cout << "Result of linear combination: " << result << std::endl;
}

int main() {
    ex00();
    std::cout << std::endl;
    ex01();
    std::cout << std::endl;

    return 0;
}

