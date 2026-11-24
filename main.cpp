#include <iostream>
#include "GenericArray.h"

int main()
{
    // int test
    GenericArray<int> int_array;
    for (int i = 0; i <= 12; i++)
        int_array.addElement(i * 2);   // 0,2,4,...,24

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is " << int_array.max()
              << "\t" << int_array.min() << std::endl;
    std::cout << "element at index 3 is " << int_array.at(3) << std::endl;

    int *sliced_array = int_array.slice(5, 10);
    if (sliced_array != nullptr)
    {
        std::cout << "sliced array (5 to 10): ";
        for (int i = 0; i < 10 - 5 + 1; i++)
            std::cout << sliced_array[i] << " ";
        std::cout << std::endl;
        delete[] sliced_array;
    }

    // Bad bounds test
    int *bad = int_array.slice(8, 50);
    if (bad == nullptr)
        std::cout << "slice(8, 50) rejected: out of bounds" << std::endl;

   // double test
    GenericArray<double> d_array;
    d_array.addElement(1.5);
    d_array.addElement(-2.25);
    d_array.addElement(3.75);
    std::cout << "double array size " << d_array.size()
              << ", sum " << d_array.sum()
              << ", max " << d_array.max()
              << ", min " << d_array.min() << std::endl;

    return 0;
}
