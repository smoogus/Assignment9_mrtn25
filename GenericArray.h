#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <stdexcept>

template <typename T>
class GenericArray
{
private:
    T *data;       // pointer to the dynamically allocated array
    int length;    // number of elements currently stored

public:
    // Constructor: start empty
    GenericArray() : data(nullptr), length(0) {}

    // Copy constructor (deep copy) so copies don't share memory
    GenericArray(const GenericArray &other) : data(nullptr), length(other.length)
    {
        if (length > 0)
        {
            data = new T[length];
            for (int i = 0; i < length; i++)
                data[i] = other.data[i];
        }
    }

    // Assignment operator (deep copy)
    GenericArray &operator=(const GenericArray &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = nullptr;
            if (length > 0)
            {
                data = new T[length];
                for (int i = 0; i < length; i++)
                    data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Destructor: free the memory
    ~GenericArray()
    {
        delete[] data;
    }

    // Add an element to the end of the array
    void addElement(T value)
    {
        T *newData = new T[length + 1];      // allocate space for new size
        for (int i = 0; i < length; i++)     // copy old elements
            newData[i] = data[i];
        newData[length] = value;             // add the new element
        delete[] data;                       // delete the old array
        data = newData;                      // point to the new array
        length++;
    }

    // Return the value at index (with bounds check)
    T at(int index) const
    {
        if (index < 0 || index >= length)
            throw std::out_of_range("GenericArray::at() index out of range");
        return data[index];
    }

    // Return the number of elements
    int size() const
    {
        return length;
    }

    // Sum of all elements
    T sum() const
    {
        T total = T();
        for (int i = 0; i < length; i++)
            total += data[i];
        return total;
    }

    // Maximum element
    T max() const
    {
        if (length == 0)
            throw std::out_of_range("GenericArray::max() called on empty array");
        T result = data[0];
        for (int i = 1; i < length; i++)
            if (data[i] > result)
                result = data[i];
        return result;
    }

    // Minimum element
    T min() const
    {
        if (length == 0)
            throw std::out_of_range("GenericArray::min() called on empty array");
        T result = data[0];
        for (int i = 1; i < length; i++)
            if (data[i] < result)
                result = data[i];
        return result;
    }

    // Return a NEW array containing elements begin..end (inclusive).
    // Returns nullptr if the bounds are invalid.
    // The caller is responsible for delete[] on the returned pointer.
    // The slice has (end - begin + 1) elements.
    T *slice(int begin, int end) const
    {
        if (begin < 0 || end >= length || begin > end)
            return nullptr;

        int sliceSize = end - begin + 1;
        T *result = new T[sliceSize];
        for (int i = 0; i < sliceSize; i++)
            result[i] = data[begin + i];
        return result;
    }
};

#endif
