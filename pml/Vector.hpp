#pragma once

#include "Config.hpp"

namespace pml {

    template <Limit T, size_t vecSize>
    struct vec {
            T data[vecSize];
        
            vec() {
                for (size_t i = 0; i < vecSize; i++) {
                    data[i] = static_cast<T>(0);
                }
            }
            vec(std::initializer_list<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }

                size_t i = 0;
                for (const T& value : content) {
                    data[i++] = value;
                }
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

            T dot(const vec<T, vecSize>& other) const {
                T result = static_cast<T>(0);
                for (size_t i = 0; i < vecSize; i++) {
                    result += data[i] * other.data[i];
                }
                return result;
            }
            
            T norm_1() const {
                T result = static_cast<T>(0);
                for (size_t i = 0; i < vecSize; i++) {
                    result += std::max(data[i], -data[i]);
                }
                return result;
            }

            T norm() const {
                T result = static_cast<T>(0);
                for (size_t i = 0; i < vecSize; i++) {
                    result += data[i] * data[i];
                }
                result = std::pow(result, static_cast<T>(0.5));
                return result;
            }

            T norm_inf() const {
                T result = static_cast<T>(0);
                for (size_t i = 0; i < vecSize; i++) {
                    T tmp = data[i];
                    tmp = std::max(tmp, -tmp);
                    result = std::max(result, tmp);
                }
                return result;
            }

            // -- operator overloads

            bool operator==(const vec &other) const {
                for (size_t i = 0; i < vecSize; i++) {
                    if (data[i] != other.data[i]) {
                        return false;
                    }
                }
                return true;
            }

            vec& operator=(std::initializer_list<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                
                size_t i = 0;
                for (const T& value : content) {
                    data[i++] = value;
                }
                
                return *this;
            }
         
            vec operator+(const vec &other) const {
                vec result(*this);
                result.add(other);
                return result;
            }

            vec& operator+=(const vec &other) {
                add(other);
                return *this;
            }

            vec operator-(const vec &other) const {
                vec result(*this);
                result.sub(other);
                return result;
            }

            vec& operator-=(const vec &other) {
                sub(other);
                return *this;
            }

            vec operator*(const T scalar) const {
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

    // -- operator overloads

    template <Limit T, size_t vecSize>
    vec<T, vecSize> operator+(T scalar, const vec<T, vecSize>& v) {
        return v + scalar;
    }

    template <Limit T, size_t vecSize>
    vec<T, vecSize> operator-(T scalar, const vec<T, vecSize>& v) {
        return v - scalar;
    }

    template <Limit T, size_t vecSize>
    vec<T, vecSize> operator*(T scalar, const vec<T, vecSize>& v) {
        return v * scalar;
    }

    // -- functions for vector operations

    template <Limit T, size_t vecSize, size_t length>
    vec<T, vecSize> linear_combination(const vec<T, vecSize> (&vectors)[length], const T (&scalars)[length]) {
        vec<T, vecSize> result;
        for (size_t i = 0; i < length; i++) {
            result += vectors[i] * scalars[i];
        }

        return result;
    }

    template <Limit T, size_t vecSize>
    vec<T, vecSize> lerp(const vec<T, vecSize>& v1, const vec<T, vecSize>& v2, T scalar) {
        vec<T, vecSize> result;
        result = v1 + scalar * (v2 - v1);

        return result;
    }

    template <Limit T, size_t vecSize>
    T dot(const vec<T, vecSize>& v1, const vec<T, vecSize>& v2) {
        return v1.dot(v2);
    }

    template <Limit T, size_t vecSize>
    T norm_1(const vec<T, vecSize>& v) {
        return v.norm_1();
    }

    template <Limit T, size_t vecSize>
    T norm(const vec<T, vecSize>& v) {
        return v.norm();
    }

    template <Limit T, size_t vecSize>
    T norm_inf(const vec<T, vecSize>& v) {
        return v.norm_inf();
    }
}
