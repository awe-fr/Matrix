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

            size_t  size() const noexcept  {
                return vecSize;
            }

            vec& operator=(std::initializer_list<T> content) {
                if (content.size() != vecSize) {
                    throw std::invalid_argument("Number of elements must match the vector size.");
                }
                
                data = std::vector<T>(content.begin(), content.end());
                
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
