#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void    iter(T *array,const size_t len, F function) {
    if (!array)
        return ;
    for (size_t i = 0; i < len; ++i) 
        function(array[i]);
}

#endif