#include <iostream>

int add(int val1,int val2)
{
    return val1+val2;
}

int sub(int val1,int val2)
{
    return val2-val1;
}

int mul(int val1,int val2)
{
    return val1*val2;
}

int defaultf(int a,int b)
{
    return 0;
}

using OperationRes = int(*)(int,int);

auto get_operation(char op) -> OperationRes
{
    switch(op)
    {
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return mul;
    }
    return defaultf;
}

auto display_and_get_funptr() -> OperationRes
{
    char oper;
    std::cout<<"Enter operations like + , - , * \n";
    std::cin>>oper;
    return get_operation(oper);
    
}



int main()
{
    int val1,val2;

    auto operation = display_and_get_funptr();

    std::cout<<"Enter val1 and val2\n";
    std::cin>>val1;
    std::cin>>val2;
    auto res = operation(val1,val2);
    std::cout<<"Resultant is : "<<res<<std::endl;

    return 0;
}