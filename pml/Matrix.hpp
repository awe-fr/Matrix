#pragma once

#include "Config.hpp"

namespace pml {

    template <Limit T, std::size_t matRowsSize, std::size_t matColsSize>
    struct mat {
        private:
            std::vector<std::vector<T>> data;

        public:
            mat() : data(matRowsSize, std::vector<T>(matColsSize, static_cast<T>(0))) {};
            mat(std::initializer_list<std::initializer_list<T>> content) {
                if (content.size() != matRowsSize) {
                    throw std::invalid_argument("Number of rows must match the matrix size.");
                }

                data.reserve(matRowsSize);

                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }

                    data.emplace_back(row.begin(), row.end());
                }

            }
            mat(std::vector<std::vector<T>> content) {
                if (content.size() != matRowsSize) {
                    throw std::invalid_argument("Number of rows must match the matrix size.");
                }

                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }
                }

                data = std::move(content);
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

                std::vector<std::vector<T>> newData;
                newData.reserve(matRowsSize);

                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }
                    newData.emplace_back(row.begin(), row.end());
                }

                data = std::move(newData);

                return *this;
            }

            mat& operator=(std::vector<std::vector<T>> content) {
                if (content.size() != matRowsSize) {
                    throw std::invalid_argument("Number of rows must match the matrix size.");
                }

                for (const auto& row : content) {
                    if (row.size() != matColsSize) {
                        throw std::invalid_argument("Number of columns must match the matrix size.");
                    }
                }

                data = std::move(content);

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

    template <Limit T, std::size_t matRowsSize, std::size_t matColsSize>
    mat<T, matRowsSize, matColsSize> linear_combination(const std::vector<mat<T, matRowsSize, matColsSize>>& matrices, const std::vector<T>& scalars) {
        if (matrices.size() != scalars.size()) {
            throw std::invalid_argument("Number of matrices and scalars must match.");
        }

        mat<T, matRowsSize, matColsSize> result;
        for (size_t i = 0; i < matrices.size(); i++) {
            result += matrices[i] * scalars[i];
        }

        return result;
    }

    template <Limit T, std::size_t matRowsSize, std::size_t matColsSize>
    mat<T, matRowsSize, matColsSize> lerp(const mat<T, matRowsSize, matColsSize>& m1, const mat<T, matRowsSize, matColsSize>& m2, T scalar) {
        mat<T, matRowsSize, matColsSize> result;
        result = m1 + (m2 - m1) * scalar;

        return result;
    }
}