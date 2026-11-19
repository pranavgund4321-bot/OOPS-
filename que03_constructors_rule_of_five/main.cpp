#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>

class IntArray {
private:
    std::size_t size;
    int* data;

public:
    // 1. Default constructor: creates an empty array.
    IntArray() : size(0), data(nullptr) {
        std::cout << "Default constructor called.\n";
    }

    // 2. Parameterized constructor: allocates and initializes an array.
    explicit IntArray(std::size_t count) : size(count), data(nullptr) {
        if (size > 0) {
            data = new int[size]{};
        }
        std::cout << "Parameterized constructor called for "
                  << size << " elements.\n";
    }

    // 3. Copy constructor: performs a deep copy into separate memory.
    IntArray(const IntArray& other) : size(other.size), data(nullptr) {
        if (size > 0) {
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        std::cout << "Copy constructor called.\n";
    }

    // 4. Copy assignment operator: deep-copies while handling self-assignment.
    IntArray& operator=(const IntArray& other) {
        std::cout << "Copy assignment operator called.\n";

        if (this == &other) {
            return *this;
        }

        int* newData = nullptr;
        if (other.size > 0) {
            newData = new int[other.size];
            std::copy(other.data, other.data + other.size, newData);
        }

        delete[] data;
        data = newData;
        size = other.size;
        return *this;
    }

    // 5. Move constructor: transfers ownership and empties the source.
    IntArray(IntArray&& other) noexcept
        : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
        std::cout << "Move constructor called.\n";
    }

    // 6. Move assignment operator: releases old memory, then takes ownership.
    IntArray& operator=(IntArray&& other) noexcept {
        std::cout << "Move assignment operator called.\n";

        if (this == &other) {
            return *this;
        }

        delete[] data;
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
        return *this;
    }

    // 7. Destructor (Rule of Five): releases the owned dynamic array.
    ~IntArray() {
        delete[] data;
        std::cout << "Destructor called.\n";
    }

    void fill(int startValue) {
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = startValue + static_cast<int>(i);
        }
    }

    void display(const char* label) const {
        std::cout << label << " [size=" << size << "]: ";
        if (size == 0) {
            std::cout << "(empty)";
        } else {
            for (std::size_t i = 0; i < size; ++i) {
                std::cout << data[i] << ' ';
            }
        }
        std::cout << '\n';
    }
};

int main() {
    std::cout << "===== CONSTRUCTORS AND RULE OF FIVE =====\n\n";

    // Default constructor.
    IntArray empty;
    empty.display("empty");

    // Parameterized constructor.
    IntArray original(5);
    original.fill(10);
    original.display("original");

    // Copy constructor: copied has its own independent allocation.
    IntArray copied(original);
    copied.display("copied");

    // Copy assignment operator.
    IntArray copyAssigned;
    copyAssigned = original;
    copyAssigned.display("copyAssigned");

    // Change the copy to demonstrate that original remains unchanged.
    copied.fill(100);
    copied.display("copied after modification");
    original.display("original remains unchanged");

    // Move constructor: movedFrom relinquishes its allocation.
    IntArray moved(std::move(original));
    moved.display("moved");
    original.display("original after move");

    // Move assignment operator.
    IntArray moveAssigned;
    moveAssigned = std::move(copyAssigned);
    moveAssigned.display("moveAssigned");
    copyAssigned.display("copyAssigned after move");

    std::cout << "\nAll objects will now leave scope and release their memory.\n";
    return 0;
}
