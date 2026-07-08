#include <Vector.hpp>
#include <Matrix.hpp>
#include <iostream>

int main() {
    pml::vec<int, 5> v = {1, 2, 3, 4, 5};
    std::cout << "Vector: " << v << " size : " << v.size() << std::endl;
    
    v = {4, 4, 4, 4, 4};
    std::cout << "Vector: " << v << " size : " << v.size() << std::endl;


    pml::mat<int, 2, 3> m = {{1, 2, 3}, {4, 5, 6}};
    std::cout << "Matrix: " << std::endl << m << std::endl << "rows : " << m.RowsSize() << " cols : " << m.ColsSize() << std::endl;

    m = {{7, 8, '9'}, {10, 11, 12}};
    std::cout << "Matrix: " << std::endl << m << std::endl << "rows : " << m.RowsSize() << " cols : " << m.ColsSize() << std::endl;

    return 0;
}