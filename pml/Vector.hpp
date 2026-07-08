#pragma once

#include "Config.hpp"

namespace pml {
    template <Limit T, size_t vecSize>
    struct vec {
        private:
            std::vector<T> data;
        
        public:
            vec() = default;
            vec(std::initializer_list<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                data = std::vector<T>(content.begin(), content.end());
            }
            vec(std::vector<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                data = std::move(content);
            }

            size_t  size() const noexcept  {
                return vecSize;
            }

            // -- functions for vector operations

            void add(const vec &other) {
                for (size_t i = 0; i < vecSize; i++) {
                    data[i] += other.data[i];
                }
            }

            void sub(const vec &other) {
                for (size_t i = 0; i < vecSize; i++) {
                    data[i] -= other.data[i];
                }
            }

            void scl(const T scalar) {
                for (size_t i = 0; i < vecSize; i++) {
                    data[i] *= scalar;
                }
            }

            // -- operator overloads

            vec& operator=(std::initializer_list<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                
                data = std::vector<T>(content.begin(), content.end());
                
                return *this;
            }

            vec& operator=(const std::vector<T>& content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                
                data = std::move(content);
                
                return *this;
            }
            
            vec operator+(const vec &other) {
                vec result(*this);
                result.add(other);
                return result;
            }

            vec& operator+=(const vec &other) {
                add(other);
                return *this;
            }

            vec operator-(const vec &other) {
                vec result(*this);
                result.sub(other);
                return result;
            }

            vec& operator-=(const vec &other) {
                sub(other);
                return *this;
            }

            vec operator*(const T scalar) {
                vec result(*this);
                result.scl(scalar);
                return result;
            }

            vec& operator*=(const T scalar) {
                scl(scalar);
                return *this;
            }

            friend std::ostream& operator<<(std::ostream& os, const pml::vec<T, vecSize>& tp) {
                for (size_t i = 0; i < vecSize; i++) {
                    if (i != 0) {
                        os << " ";
                    }
                    os << tp.data[i];
                }
            
                return os;
            }
    };
}
