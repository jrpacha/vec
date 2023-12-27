#ifndef AUX_H
#define AUX_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

template <typename T>
void print_vector(const std::vector<T> &, const size_t &);

template <typename T>
void print_matrix(const std::vector<std::vector<T>> &, const size_t &);

// print vector
template <typename T>
void print_vector(const std::vector<T> &ptr,
                  const size_t &prec)
{
    size_t width;
    width = prec + 8;
    std::cout << std::scientific << std::setprecision(prec);

    for (size_t i = 0; i < ptr.size(); i++)
        std::cout << std::setw(width) << ptr[i];
    std::cout << std::endl;
}

// print matrix
template <typename T>
void print_matrix(const std::vector<std::vector<T>> &ptr,
                  const size_t &prec)
{
    size_t width;
    width = prec + 8;
    std::cout << std::scientific << std::setprecision(prec);

    for (size_t i = 0; i < ptr.size(); i++)
    {
        /* code */
        for (size_t j = 0; j < ptr[i].size(); j++)
        {
            /* code */
            std::cout << std::setw(width) << ptr[i][j];
        }
        std::cout << std::endl;
    }
}

#endif
