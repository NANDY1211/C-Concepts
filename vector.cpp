#include <iostream>
#include <vector>


int main()
{
    std::vector<int> iVec{};
    iVec.push_back(10);
    iVec.push_back(10);
    iVec.push_back(10);
    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;

    iVec.push_back(10);

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;

    iVec.push_back(10);

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;

    std::cout<<"Popping the elements\n";
    iVec.pop_back();

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;

    iVec.pop_back();

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;
    
    iVec.pop_back();

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;


    std::cout<<"Fitting the capacity\n";
    iVec.shrink_to_fit();

    std::cout<<"Size and capacity \n";
    std::cout<<"Size : "<<iVec.size()<<std::endl;
    std::cout<<"Capacity : "<<iVec.capacity()<<std::endl;

    return 0;
}