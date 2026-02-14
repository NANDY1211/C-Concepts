#include <iostream>
#include <memory>

class Person {
public:
    std::string name;
    std::weak_ptr<Person> partner; // weak ownership

    Person(const std::string& n) : name(n) {
        std::cout << name << " created\n";
    }
    ~Person() {
        std::cout << name << " destroyed\n";
    }
};

int main() {
    auto p1 = std::make_shared<Person>("Alice");
    auto p2 = std::make_shared<Person>("Bob");

    p1->partner = p2; // weak_ptr does not increase ref count
    p2->partner = p1;


    // When main ends, both shared_ptrs go out of scope
    // => ref count drops to 0, objects destroyed properly
}
