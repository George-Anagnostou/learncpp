#ifndef SIGNED_ARRAY_VIEW_H
#define SIGNED_ARRAY_VIEW_H

#include <cstddef> // for std::size_t and std::ptrdiff_t

template <typename T>
class SignedArrayView {
private:
    T& m_array;

public:
    using Index = std::ptrdiff_t;

    SignedArrayView(T& array)
        : m_array { array } {}

    // Overload operator[] to take a signed index
    constexpr auto& operator[](Index index) { 
        return m_array[static_cast<typename T::size_type>(index)];
    }
    
    constexpr const auto& operator[](Index index) const {
        return m_array[static_cast<typename T::size_type>(index)];
    }
    
    constexpr auto ssize() const { return static_cast<Index>(m_array.size());}
};

#endif