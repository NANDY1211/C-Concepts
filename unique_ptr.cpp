#include <iostream>
#include <memory>


class Add
{
    private:
        int val1_,val2_;
    public:
        Add(int a = 0, int b = 0) : val1_(a),val2_(b){}
    
    const Add operator+(const Add& other){
        return Add((this->val1_+other.val1_),(this->val2_+other.val2_));
    }

    friend std::ostream& operator<<(std::ostream& out, const Add& obj) 
    { 
        out << "(" << obj.val1_ << "," << obj.val2_ << ")"; 
        return out; 
    }

};

std::unique_ptr<Add> operator+(const std::unique_ptr<Add>& lhs, const std::unique_ptr<Add>& rhs)
{ 
    if (!lhs || !rhs) 
        return nullptr; 
    return std::make_unique<Add>(*lhs + *rhs); 
    
}

int main()
{

    std::unique_ptr<Add> a1 = std::make_unique<Add>(10,20);
    std::unique_ptr<Add> a2 = std::make_unique<Add>(30,20);
    auto a3 = a1+a2;
    std::cout << *a3 << std::endl;


    //creating a new unique pointer

    std::unique_ptr<int> uPtr = std::make_unique<int>(10);

    //Getting the address of the unique_ptr
    std::cout<<"Address of the unique ptr "<<uPtr.get()<<std::endl;
    std::cout<<"Value of the unique ptr "<<*uPtr<<std::endl;

    //Resetting it with a new pointer

    uPtr.reset(new int(30));

    std::cout<<"After resetting with the new value \n";
    std::cout<<"Address : "<<uPtr.get()<<std::endl;
    std::cout<<"Value : "<<*uPtr<<std::endl;


    //Releasing the unique_ptr with the raw ptr

    int* rawIPtr = uPtr.release();

    std::cout<<"After releasing\n";
    std::cout<<"Address : "<<rawIPtr<<std::endl;
    std::cout<<"Value : "<<*rawIPtr<<std::endl;






    return 0;
}