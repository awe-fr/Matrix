#pragma once

#include "Config.hpp"

namespace pml {

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    struct mat {
            T data[matRowsSize][matColsSize];

            mat() {
                for (size_t i = 0; i < matRowsSize; i++) {
                    for (size_t j = 0; j < matColsSize; j++) {
                        data[i][j] = static_cast<T>(0);
                    }
                }
            }
            mat(std::initializer_list<std::initializer_list<T>> content) {
                if (content.size() != matRowsSize) {
                    throw std::invalid_argument("Number of rows must match the matrix size.");
                }

                size_t i = 0;
                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }

                    size_t j = 0;
                    for (const auto& value : row) {
                        data[i][j] = value;
                        j++;
                    }
                    i++;
                }

            }

            size_t  RowsSize() const noexcept  {
                return matRowsSize;
            }

            size_t  ColsSize() const noexcept  {
                return matColsSize;
            }

            size_t  size() const noexcept  {
                return matRowsSize * matColsSize;
            }

            // -- functions for matrix operations

            void add(const mat &other) {
                for (size_t i = 0; i < matRowsSize; i++) {
                    for (size_t j = 0; j < matColsSize; j++) {
                        data[i][j] += other.data[i][j];
                    }
                }
            }

            void sub(const mat &other) {
                for (size_t i = 0; i < matRowsSize; i++) {
                    for (size_t j = 0; j < matColsSize; j++) {
                        data[i][j] -= other.data[i][j];
                    }
                }
            }

            void scl(const T scalar) {
                for (size_t i = 0; i < matRowsSize; i++) {
                    for (size_t j = 0; j < matColsSize; j++) {
                        data[i][j] *= scalar;
                    }
                }
            }

            // -- operator overloads
            mat& operator=(std::initializer_list<std::initializer_list<T>> content) {
                if (content.size() != matRowsSize) {
                    throw std::invalid_argument("Number of rows must match the matrix size.");
                }

                T newData[matRowsSize][matColsSize];

                size_t i = 0;
                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }

                    size_t j = 0;
                    for (const auto& value : row){
                        newData[i][j] = value;
                        j++;
                    }
                    i++;
                }

                for (size_t o = 0; o < matRowsSize; o++) {
                    for (size_t p = 0; p < matColsSize; p++) {
                        data[o][p] = newData[o][p];
                    }
                }

                return *this;
            }

            mat operator+(const mat &other) const {
                mat result(*this);
                result.add(other);
                return result;
            }

            mat& operator+=(const mat &other) {
                add(other);
                return *this;
            }

            mat operator-(const mat &other) const {
                mat result(*this);
                result.sub(other);
                return result;
            }

            mat& operator-=(const mat &other) {
                sub(other);
                return *this;
            }

            mat operator*(const T scalar) const {
                mat result(*this);
                result.scl(scalar);
                return result;
            }

            mat& operator*=(const T scalar) {
                scl(scalar);
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& os, const pml::mat<T, matRowsSize, matColsSize>& tp) {
                for (size_t j = 0; j < matColsSize; j++) {
                    if (j != 0) {
                        os << std::endl;
                    }
                    for (size_t i = 0; i < matRowsSize; i++) {
                        if (i != 0) {
                            os << " ";
                        }
                        os << tp.data[i][j];
                    }
                }
            
                return os;
            }
    };

    // -- operator overloads

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    mat<T, matRowsSize, matColsSize> operator+(T scalar, const mat<T, matRowsSize, matColsSize>& m) {
        return m + scalar;
    }

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    mat<T, matRowsSize, matColsSize> operator-(T scalar, const mat<T, matRowsSize, matColsSize>& m) {
        return m - scalar;
    }

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    mat<T, matRowsSize, matColsSize> operator*(T scalar, const mat<T, matRowsSize, matColsSize>& m) {
        return m * scalar;
    }

    // -- functions for matrix operations

    template <Limit T, size_t matRowsSize, size_t matColsSize, size_t length>
    mat<T, matRowsSize, matColsSize> linear_combination(const mat<T, matRowsSize, matColsSize> (&matrices)[length], const T (&scalars)[length]) {
        mat<T, matRowsSize, matColsSize> result;
        for (size_t i = 0; i < length; i++) {
            result += matrices[i] * scalars[i];
        }

        return result;
    }

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    mat<T, matRowsSize, matColsSize> lerp(const mat<T, matRowsSize, matColsSize>& m1, const mat<T, matRowsSize, matColsSize>& m2, T scalar) {
        mat<T, matRowsSize, matColsSize> result;
        result = m1 + scalar * (m2 - m1);

        return result;
    }

    template <Limit T, size_t matRowsSize, size_t matColsSize>
    T dot(const mat<T, matRowsSize, matColsSize>& m1, const mat<T, matRowsSize, matColsSize>& m2) {
        T result = static_cast<T>(0);
        for (size_t i = 0; i < matRowsSize; i++) {
            for (size_t j = 0; j < matColsSize; j++) {
                result += m1.data[i][j] * m2.data[i][j];
            }
        }
        return result;
    }
}