#include <iostream>

using Transformer = int(*)(int);

int double_array(int val)
{
    return val*2;
}

void printArray(int* arr , int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<arr[i]<<",";
    }
}

void apply(int* arr,int size,Transformer transform)
{
    for(int i = 0 ;i<=size;i++)
    {
        arr[i] = transform(arr[i]);
    }
}
int main()
{
    std::cout<<"Before changing \n";
    int arr[] = {1,2,3,4,5};
    int size = 5;
    printArray(arr,size);

    std::cout<<"\nAfter changing\n";

    apply(arr,size,double_array);
    printArray(arr,size);



    return 0;
}