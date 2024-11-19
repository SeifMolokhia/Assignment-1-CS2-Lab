//
//  main.cpp
//  Seif Molokhia assignment 2.cpp
//
//  Created by Seif on 10/11/2024.
//

#include <iostream>
using namespace std;

template <class T>
class CustomVector {
private:
    T* data;
    int capacity;

public:
    // Initializes a vector with a fixed size of 20
    CustomVector() {
        capacity = 20;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = T();
        }
    }

    // Initializes a vector of given size
    CustomVector(int size) {
        capacity = size;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = T();
        }
    }

    // Initializes all elements to 'value'
    CustomVector(int size, T value) {
        capacity = size;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = value;
        }
    }

    // Deallocates the dynamic array to free memory
    ~CustomVector() {
        delete[] data;
    }

    // Returns the current size (capacity) of the vector
    int size() {
        return capacity;
    }

    
    void push_back(T value) {
        T* temp = new T[capacity + 1]; // Create a new array with increased capacity
        for (int i = 0; i < capacity; i++) {
            temp[i] = data[i];
        }
        temp[capacity] = value; // Add new element
        capacity++; // Increase capacity
        data = temp; // Update data to new array
    }

    T pop_back() {
        T* temp = new T[capacity - 1]; // Create a new array with decreased capacity
        for (int i = 0; i < capacity - 1; i++) {
            temp[i] = data[i];
        }
        capacity--; // Decrease capacity
        T removedValue = data[capacity]; // Store last element before deleting
        data = temp;
        return removedValue; // Return removed element
    }

    // Resizes the vector to 'newSize' and fills new elements with 'value' if expanded
    void resize(int newSize, T value) {
        if (newSize > capacity) {
            for (int i = 0; i < capacity; i++) {
                push_back(value);
            }
        } else if (newSize < capacity) {
            for (int i = 0; i < capacity - newSize; i++) {
                pop_back();
            }
        }
    }

    
    void insert(int position, T value) {
        T* temp = new T[capacity + 1]; // Create new array with increased capacity
        for (int i = 0; i < position; i++) {
            temp[i] = data[i];
        }
        temp[position] = value;
        for (int i = position; i < capacity; i++) {
            temp[i + 1] = data[i];
        }
        capacity++;
        data = temp;
    }

    
    void erase(int position) {
        T* temp = new T[capacity - 1];
        for (int i = 0; i < position; i++) {
            temp[i] = data[i];
        }
        for (int i = position + 1; i < capacity; i++) {
            temp[i - 1] = data[i];
        }
        capacity--; // Decrease capacity
        data = temp; // Update data to new array
    }

    
    void erase(int start, int end) {
        if (end - start < capacity) {
            cout << "Error";
        } else {
            for (int i = start; i < end; i++) {
                erase(start);
            }
        }
    }

    // Overloaded index operator to access elements by index
    T& operator[](int index) {
        return data[index];
    }

    
    CustomVector<T> operator+(CustomVector<T>& other) {
        CustomVector<T> result(other.capacity);
        for (int i = 0; i < capacity; i++) {
            result.data[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    
    CustomVector<T> operator-(CustomVector<T>& other) {
        CustomVector<T> result(other.capacity);
        for (int i = 0; i < capacity; i++) {
            result.data[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    // Overloaded == operator to check if two vectors are equal
    bool operator==(CustomVector<T>& other) {
        if (this->capacity != other.capacity) {
            return false;
        }
        for (int i = 0; i < capacity; i++) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Overloaded != operator to check if two vectors are not equal
    bool operator!=(CustomVector<T>& other) {
        return !(*this == other);
    }

    // Overloaded prefix ++ operator to increment all elements
    CustomVector& operator++() {
        for (int i = 0; i < capacity; i++) {
            data[i]++;
        }
        return *this;
    }

    // Overloaded postfix ++ operator to increment all elements and return old vector
    CustomVector operator++(int) {
        CustomVector<T> temp(capacity);
        for (int i = 0; i < capacity; i++) {
            temp.data[i] = this->data[i];
        }
        for (int i = 0; i < capacity; i++) {
            data[i]++;
        }
        return temp;
    }

    // Overloaded prefix -- operator to decrement all elements
    CustomVector& operator--() {
        for (int i = 0; i < capacity; i++) {
            --data[i];
        }
        return *this;
    }

    // Overloaded postfix -- operator to decrement all elements and return old vector
    CustomVector operator--(int) {
        CustomVector<T> temp(capacity); // Create temp vector to hold current values
        for (int i = 0; i < capacity; i++) {
            temp.data[i] = this->data[i];
        }
        for (int i = 0; i < capacity; i++) {
            data[i]--;
        }
        return temp;
    }

    template <typename U>
    friend ostream& operator<<(ostream& out, const CustomVector<U>& vec);

    template <typename U>
    friend istream& operator>>(istream& in, CustomVector<U>& vec);
};

template <typename U>
ostream& operator<<(ostream& out, const CustomVector<U>& vec) {
    for (int i = 0; i < vec.capacity; i++) {
        out << vec.data[i] << " ";
    }
    out << endl;
    return out;
}

template <typename U>
istream& operator>>(istream& in, CustomVector<U>& vec) {
    for (int i = 0; i < vec.capacity; i++) {
        cout << "Enter a new value: ";
        in >> vec.data[i];
    }
    return in;
}

int main() {
    CustomVector<string> strVec(4);
    strVec[0] = "1";
    strVec[1] = "2";
    strVec[2] = "3";
    strVec[3] = "4";
    
    CustomVector<string> strVec2(4);
    strVec2[0] = "5";
    strVec2[1] = "6";
    strVec2[2] = "7";
    strVec2[3] = "8";
    
    bool isEqual = strVec != strVec2;
    bool isNotEqual = strVec == strVec2;
}
