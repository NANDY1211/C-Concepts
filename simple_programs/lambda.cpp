#include <iostream>
#include <math.h>

auto addRes = [](int val1, int val2)
{
    return val1 + val2;
};

auto mulRes = [](int val1, int val2)
{
    return val1 * val2;
};

int main()
{
    std::cout << "Addition Result : " << addRes(2, 3) << std::endl;
    std::cout << "Multiplication Result : " << mulRes(2, 3) << std::endl;

    int (*lPtr)(int, int) = addRes;
    std::cout << "Function pointer " << lPtr(3, 3) << std::endl;

    // captures
    int scalarVal = 5;

    // capturebyvalue
    auto scalarMul = [scalarVal](int val)
    {
        return scalarVal * val;
    };

    std::cout << "Scalar Result : " << scalarMul(3) << std::endl;

    // capture by reference
    auto timesMul = [&scalarVal](int times)
    {
        ++scalarVal;
        return std::pow(scalarVal, times);
    };

    std::cout << "Power result : " << timesMul(2) << std::endl;

    // mutable

    int x = 10;
    auto lambda = [x]() mutable -> int
    {
        x++; // OK! Modifies the lambda's copy of x
        return x;
    };

    std::cout << lambda(); // 11
    std::cout << lambda(); // 12 (state is preserved!)
    std::cout << x;        // 10 (original unchanged)

    return 0;
}