//
// Created by 전현우 on 24. 12. 15.
//

#include <iostream>
using std::cout;
using std::endl;

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

using namespace  Special;

int main()
{
    hello_world();
    swapValues("char", "dddd");
    return 0;
}
