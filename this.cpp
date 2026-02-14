#include <iostream>

class Add
{
    private:
        int m_a,m_b;
    public:
        Add(int a = 0,int b = 0) : m_a(a) , m_b(b){}

        Add& operator+=(const Add& other){
            this->m_a = this->m_a+other.m_a;
            this->m_b = this->m_b+other.m_b;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& out,const Add& data){
            out<<"Result : ("<<data.m_a<<","<<data.m_b<<")"<<"\n";
            return out;
        }
};

int main()
{

    Add a1(2,3) ,a2(3,4);
    a1+=a2;

    std::cout<<a1<<std::endl;
    return 0;
}