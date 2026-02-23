#include <iostream>

#define LOG(x) std::cout<<"Resultant value : "<<x<<std::endl;

int add(int a,int b)
{
    return a+b;
}

int sub(int val1,int val2)
{
    return val2-val1;
}

int mul(int a , int b)
{
    return a*b;
}

int divide(int val1,int val2)
{
    return val1/val2;
}

struct Values
{
    int option;
    int val1;
    int val2;
};


Values displayMenuAndGetInput()
{
    int option{};
    std::cout<<"Select operations below :\n 1)Add\n 2)Sub \n 3)mul \n 4)div \n";
    std::cin>>option;
    Values fillVal;
    fillVal.option = option;
    std::cout<<"Provide two values : val1 and val2\n";
    std::cin>>fillVal.val1;
    std::cin>>fillVal.val2;


    return fillVal;
}

int main()
{
    using operations = int (*)(int,int);
    operations ops[4] = {add,sub,mul,divide};

    Values data;
    //Displaying menu
    data =  displayMenuAndGetInput();
    

    //Executing the operation

    std::cout << "Gonna execute the operation \n";
    LOG(ops[data.option-1](data.val1,data.val2));
    return 0;

}