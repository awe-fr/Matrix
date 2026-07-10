#pragma once

# include <concepts>
// # include <vector>
# include <iostream>

# include <array>

namespace pml {
    template <typename T>    
    concept Limit = (std::integral<T> 
                        && std::signed_integral<T> 
                        && !std::same_as<T, bool> 
                        && !std::same_as<T, char> 
                        && !std::same_as<T, unsigned char> 
                        && !std::same_as<T, wchar_t>) 
                    || std::is_floating_point_v<T>;
}