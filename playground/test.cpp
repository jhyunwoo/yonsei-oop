#include <iostream>

using namespace std;

class DayOfYear
{
public:


    void print()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }

private:
    int year;
    int month;
    int day;
};


int main()
{
    DayOfYear day2;
    day2.print();
    return 0;
}