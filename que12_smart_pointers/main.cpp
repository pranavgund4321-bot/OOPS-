#include <iostream>
#include <memory>
#include <utility>

class Demo {
public:
    Demo() { std::cout << "  Object created\n"; }
    ~Demo() { std::cout << "  Object destroyed\n"; }

    void display(const char* owner) const {
        std::cout << "  " << owner << " is using the object\n";
    }
};

// Raw-pointer version: the programmer must remember delete.
void rawPointerDemo() {
    std::cout << "\n--- RAW POINTER DEMO ---\n";
    Demo* ptr = new Demo();
    ptr->display("Raw pointer");
    delete ptr; // Required manual cleanup.
    ptr = nullptr;
    std::cout << "  Memory released manually\n";
}

// unique_ptr: one owner; ownership can be transferred with std::move.
void uniquePointerDemo() {
    std::cout << "\n--- UNIQUE_PTR DEMO ---\n";
    {
        std::unique_ptr<Demo> first = std::make_unique<Demo>();
        first->display("first");

        std::unique_ptr<Demo> second = std::move(first);
        std::cout << "  first owns an object: " << std::boolalpha
                  << static_cast<bool>(first) << '\n';
        std::cout << "  second owns an object: "
                  << static_cast<bool>(second) << '\n';
        second->display("second");
    } // Object is destroyed automatically here.

    std::cout << "  unique_ptr scope ended\n";
}

// shared_ptr: multiple owners share one object.
void sharedPointerDemo() {
    std::cout << "\n--- SHARED_PTR DEMO ---\n";
    {
        std::shared_ptr<Demo> first = std::make_shared<Demo>();
        std::cout << "  owners: " << first.use_count() << '\n';

        {
            std::shared_ptr<Demo> second = first;
            std::cout << "  owners after sharing: "
                      << first.use_count() << '\n';
            second->display("second shared owner");
        } // second releases its ownership.

        std::cout << "  owners after second leaves scope: "
                  << first.use_count() << '\n';
    } // Last owner leaves scope; object is destroyed.

    std::cout << "  shared_ptr scope ended\n";
}

// unique_ptr can also manage dynamically allocated arrays.
void uniqueArrayDemo() {
    std::cout << "\n--- UNIQUE_PTR ARRAY DEMO ---\n";
    {
        std::unique_ptr<int[]> values = std::make_unique<int[]>(5);

        for (int i = 0; i < 5; ++i)
            values[i] = (i + 1) * 10;

        std::cout << "  Array elements: ";
        for (int i = 0; i < 5; ++i)
            std::cout << values[i] << ' ';
        std::cout << '\n';
    } // Array is automatically released with delete[] semantics.
}

int main() {
    std::cout << "SMART POINTERS AND RAII\n";

    // Repeat the demonstrations to exercise object creation/destruction.
    for (int iteration = 1; iteration <= 3; ++iteration) {
        std::cout << "\n========== ITERATION " << iteration
                  << " ==========\n";
        rawPointerDemo();
        uniquePointerDemo();
        sharedPointerDemo();
        uniqueArrayDemo();
    }

    std::cout << "\nProgram completed.\n";
    return 0;
}
