#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

class DemoResource {
private:
    string name;

public:
    explicit DemoResource(string resourceName) : name(std::move(resourceName)) {
        cout << "[Construct] " << name << '\n';
    }

    ~DemoResource() {
        cout << "[Destroy] " << name << '\n';
    }

    void use() const {
        cout << "Using resource: " << name << '\n';
    }
};

// A raw-pointer example for comparison.
// The caller is responsible for matching new with delete.
void rawPointerDemo() {
    cout << "\n--- 1. Raw pointer (manual ownership) ---\n";
    DemoResource* raw = new DemoResource("Raw resource");
    raw->use();
    delete raw;
    raw = nullptr;
    cout << "Raw resource deleted manually.\n";
}

// unique_ptr demonstrates exclusive ownership.
void uniquePointerDemo() {
    cout << "\n--- 2. unique_ptr (exclusive ownership) ---\n";
    {
        unique_ptr<DemoResource> owner =
            make_unique<DemoResource>("Unique resource");
        owner->use();

        // Ownership can be transferred, not copied.
        unique_ptr<DemoResource> newOwner = std::move(owner);
        cout << "Original owner is "
             << (owner ? "not empty" : "empty") << ".\n";
        newOwner->use();
    } // The resource is destroyed automatically here.

    cout << "unique_ptr scope ended.\n";

    // unique_ptr can also manage arrays.
    unique_ptr<int[]> numbers = make_unique<int[]>(3);
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    cout << "Managed array: " << numbers[0] << ", "
         << numbers[1] << ", " << numbers[2] << '\n';
} // Array is automatically released.

// Two independent components genuinely share one resource.
class ResourceUser {
private:
    string userName;
    shared_ptr<DemoResource> resource;

public:
    ResourceUser(string name, shared_ptr<DemoResource> sharedResource)
        : userName(std::move(name)), resource(std::move(sharedResource)) {}

    void useResource() const {
        cout << userName << " accesses the shared resource.\n";
        resource->use();
    }
};

void sharedPointerDemo() {
    cout << "\n--- 3. shared_ptr (shared ownership) ---\n";
    auto sharedResource = make_shared<DemoResource>("Shared resource");

    {
        ResourceUser reportModule("Report module", sharedResource);
        ResourceUser backupModule("Backup module", sharedResource);

        cout << "Owners after creating two modules: "
             << sharedResource.use_count() << '\n';
        reportModule.useResource();
        backupModule.useResource();
    } // Both modules release their ownership here.

    cout << "Owners after modules leave scope: "
         << sharedResource.use_count() << '\n';
} // Last shared_ptr releases the resource automatically.

// Repeated allocation/release to exercise object lifetimes.
void repeatedIterations() {
    cout << "\n--- 4. Repeated RAII iterations ---\n";
    constexpr int iterations = 1000;

    for (int i = 0; i < iterations; ++i) {
        auto item = make_unique<int>(i);
        auto sharedItem = make_shared<int>(*item);
        // Both allocations are released automatically per iteration.
    }

    cout << "Completed " << iterations
         << " unique_ptr/shared_ptr iterations.\n";
}

int main() {
    cout << "RAII AND SMART POINTERS DEMONSTRATION\n";

    rawPointerDemo();
    uniquePointerDemo();
    sharedPointerDemo();
    repeatedIterations();

    cout << "\nProgram completed.\n";
    return 0;
}
