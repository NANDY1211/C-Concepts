#include "math.h"

namespace math{
    int add(int a,int b){
        return (a+b);
    }

    int sub(int a,int b){
        return (a-b <0)?(b-a):(a-b);
    }

    int mul(int a,int b){
        return (a*b);
    }
}