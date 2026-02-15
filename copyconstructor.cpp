#include <iostream>
#include <cstring>

//Class that illustrate shallow copy
class Person
{
    private:
        char* m_data;
    public:
        Person(size_t size){
            m_data = new char[size];
        }
    
        ~Person(){
            delete[] this->m_data;
        }

        void setName(const char* p_name)
        {
            std::strcpy(this->m_data, p_name);
        }

        void getName()
        {
            std::cout<<"Name is : "<<this->m_data<<std::endl;
        }

};

//Class that illustrate deep copy

class Role
{
    private:
        int m_size;
        char* m_roleName;
    public:
        Role(size_t size) : m_size(size){
            m_roleName = new char[m_size];
        }

        //According to rule of 3 -> should define 
        // Copy constructor
        //destructor
        //Copy assignment constructor


        //Copy constructor

        Role(const Role& other) : m_size(other.m_size){
            m_roleName = new char[this->m_size];
            std::copy(other.m_roleName,other.m_roleName+other.m_size,this->m_roleName);
        }

        //Destructor

        ~Role()
        {
            delete[] m_roleName;
        }

        //Copy assignment constructor

        Role operator=(const Role& other){
            if(this == &other)
                return *this;
            
            //Free old
            delete[] m_roleName;

            //Copy size
            this->m_size = other.m_size;
            //Allocate new
            m_roleName = new char[this->m_size];

            //Allocate data
            std::copy(other.m_roleName,other.m_roleName+other.m_size,this->m_roleName);
        }


        void setRole(const char* p_role)
        {
            std::strcpy(this->m_roleName,p_role);
        }

        void getRole()
        {
            std::cout<<this->m_roleName<<std::endl;
        }
};

int main()
{
    //Block illustrate shallow copy
    /*{
        Person anish(10);
        anish.setName("Anish");
        anish.getName();

        Person badri(anish);
    }*/

    //Block illustrate deep copy along with role of 3
    {
        Role dev(10);
        dev.setRole("Developer");
        dev.getRole();

        //Copy constructor
        Role cloudDev(dev);
        cloudDev.getRole();

        //Copy assignment
        Role devops = dev;
        devops.getRole();

    }

    return 0;
}