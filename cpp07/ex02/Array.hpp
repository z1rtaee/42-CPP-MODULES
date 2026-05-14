#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstddef>

template <typename T>
class Array {
    private:
        T   *_array;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();

        Array   &operator=(const Array &obj);

        T &operator[](unsigned int idx);
        const T &operator[](unsigned int idx) const;

        unsigned int size() const;
};

# include "Array.tpp"

#endif