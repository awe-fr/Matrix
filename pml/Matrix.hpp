#pragma once

#include "Config.hpp"

# include <concepts>
# include <vector>

namespace pml {

    template <Limit T, std::size_t matRowsSize, std::size_t matColsSize>
    struct mat {
        friend std::ostream& operator<<(std::ostream& os, const pml::mat<T, matRowsSize, matColsSize>& tp);

        private:
            std::vector<std::vector<T>> data;

        public:
            mat() = default;
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

            size_t  RowsSize() const noexcept  {
                return matRowsSize;
            }

            size_t  ColsSize() const noexcept  {
                return matColsSize;
            }

            size_t  size() const noexcept  {
                return matRowsSize * matColsSize;
            }

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

            friend std::ostream& operator<<(std::ostream& os, const pml::mat<T, matRowsSize, matColsSize>& tp) {
                for (size_t i = 0; i < matRowsSize; i++) {
                    if (i != 0) {
                        os << " ";
                    }
                    for (size_t j = 0; j < matColsSize; j++) {
                        if (i != 0 && j == 0) {
                            os << std::endl;
                        } else if (j != 0) {
                            os << " ";
                        }
                        os << tp.data[i][j];
                    }
                }
            
                return os;
            }
    };
}