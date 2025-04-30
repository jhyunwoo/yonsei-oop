//
// Created by 전현우 on 24. 12. 15.
//

#include <iostream>
using std::cout;
using std::endl;
#include "hello_world.h"

namespace Special
{

    void hello_world()
    {
        cout << "Hello World???" << endl;
    }

    template<class T>
    void swapValues(T& var1, T& var2)
    {
        T temp;
        temp = var1;
        var1 = var2;
        var2 = temp;
    }

}


int main()
{
    hello_world a;
    a.sayHello();
    return 0;
}
