
#pragma once

#include <iostream>

template <typename T>
void iter(const T *array, size_t size, void (*f)(T const &))
{
    for (size_t i = 0; i < size; i++)
    {
        f(array[i]);
    }
}