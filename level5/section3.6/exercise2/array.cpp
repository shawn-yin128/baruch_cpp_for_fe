// source file of array class

#include "array.hpp"
#include "point.hpp"
#include "outofboundsexception.hpp"
#include <iostream>

using namespace std;

// constructor
Array::Array() { // default to create an array with 10 point
    m_data = new Point[10];
    m_size = 10;
}

Array::Array(int size) {
    m_data = new Point[size];
    m_size = size;
}

Array::Array(const Array& arr) {
    m_data = new Point[arr.m_size];
    m_size = arr.m_size;
    for (int i = 0; i < m_size; i++) {
        m_data[i] = arr.m_data[i];
    }
}

// destructor
Array::~Array() {
    delete[] m_data;
}

// operator overloading
Array& Array::operator = (const Array& arr) {
    if (this == &arr) {
        return *this;
    }
    delete[] m_data; // delete original object at first

    m_data = new Point[arr.m_size];
    m_size = arr.m_size;
    for (int i = 0; i < m_size; i++) {
        m_data[i] = arr.m_data[i];
    }
    return *this;
}

Point& Array::operator [] (int idx) {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

const Point& Array::operator [] (int idx) const {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

// accessor
int Array::Size() const {
        return m_size;
}

Point& Array::GetElement(int idx) const {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

// modifier
void Array::SetElement(int idx, const Point& p) {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    m_data[idx] = p;
}