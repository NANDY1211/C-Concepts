#include <iostream>
#include <memory>


class Add {
    int a, b;
public:
    Add(int x, int y) : a(x), b(y) {}
    void show() { std::cout << "Sum = " << a + b << "\n"; }

    ~Add()
    {
        std::cout<<"Object Going to destroy\n";
    }
};

int main() {

    std::shared_ptr<Add> obj1 = std::make_shared<Add>(1, 2);
    {
        std::shared_ptr<Add> obj2 = obj1; // shared ownership

        obj1->show();
        obj2->show();

        std::cout << "Use count Inside block Obj1: " << obj1.use_count() << "\n"; // 2 owners
        std::cout << "Use count Inside block Obj2: " << obj2.use_count() << "\n"; 

        std::cout<<"Address for obj1 "<<obj1.get()<<std::endl;
        std::cout<<"Address for obj2 "<<obj2.get()<<std::endl;
    }
    std::cout << "Use count Outside block: " << obj1.use_count() << "\n"; // 2 owners


    return 0;
}
