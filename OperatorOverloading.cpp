#include <iostream>

class Complex
{
    private:
        int m_real, m_imag;
    public:
        Complex(int real = 0 , int imag = 0) : m_real(real) , m_imag(imag){}

        Complex operator+(const Complex& c);
        friend std::ostream& operator<<(std::ostream& out,const Complex& c);
};

Complex Complex::operator+(const Complex& c){
    return Complex((this->m_real+c.m_real),(this->m_imag+c.m_imag));
}

std::ostream& operator<<(std::ostream& out,const Complex& c){
    out<<c.m_real<<"+"<<c.m_imag<<"i";
    return out;
}



class Vector2D
{
    private:
        double x_,y_;
    public:
        Vector2D(double x = 0.0 ,double y = 0.0) : x_(x), y_(y){}

        Vector2D operator*(const Vector2D& other);

        friend std::ostream&  operator<<(std::ostream& out,const Vector2D vec);
};

Vector2D Vector2D::operator*(const Vector2D& other){
    return Vector2D((this->x_*other.x_),(this->y_*other.y_));
}

std::ostream& operator<<(std::ostream& out,const Vector2D vec){
    out<<"("<<vec.x_<<","<<vec.y_<<")";
    return out;
}


class Person
{
    private:
        std::string m_name;
    public:
        Person(std::string name) : m_name(name){};
        void greet(){std::cout<<"Welcome "<<m_name<<"\n";};
};

class CustomSmartPointer
{
    private:
        Person* p;

    public:
        CustomSmartPointer(Person* ptr = nullptr) : p(ptr){}

        Person* operator->(){
            return p;
        }

        Person& operator*(){
            return *p;
        }

};

int main()
{
    Complex c1(1,2),c2(3,4);

    Complex c3 = c1+c2;
    std::cout<<c3<<std::endl;

    Vector2D vec1(6,6),vec2(2,4);

    Vector2D vec3 = vec1*vec2;

    std::cout<<vec3<<std::endl;

    Person* hari = new Person("vedan");
    CustomSmartPointer cPtr(hari);
    (*cPtr).greet();




    return 0;
}