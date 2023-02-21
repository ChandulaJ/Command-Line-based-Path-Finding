#pragma once

#include <iostream>

template <typename T>
class myVector {
public:
    myVector() : m_size(0), m_capacity(10), m_data(new T[m_capacity]) {}

    myVector(int size) : m_size(size), m_capacity(size * 2), m_data(new T[m_capacity]) {}

    myVector(const myVector<T>& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }

    ~myVector() {
        delete[] m_data;
    }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            resize();
        }
        m_data[m_size++] = value;
    }

    T& operator[](int index) {
        return m_data[index];
    }

    int size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }
    void resize(int new_size) {
        T* new_data = new T[new_size];
        int copy_size = new_size < m_size ? new_size : m_size;
        for (int i = 0; i < copy_size; i++) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_size = new_size;
        m_capacity = new_size * 2;
    }


private:
    int m_size;
    int m_capacity;
    T* m_data;

    void resize() {
        m_capacity *= 2;
        T* new_data = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
    }
};
