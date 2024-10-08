#include <iostream>

using namespace std;

class HotDogStand
{
private:
    int id;
    int sold;

    public:
    static int totalSold;

    HotDogStand(const int id, const int sold)
    {
        this->id = id;
        this->sold = sold;
        totalSold += sold;
    }

    void JustSold()
    {
        sold++;
        totalSold++;
    }

    int getSold()
    {
        return sold;
    }

    static int getTotalSold()
    {
        return totalSold;
    }


};

int HotDogStand::totalSold = 0;

int main()
{
    HotDogStand cart1(1, 0);
    HotDogStand cart2(2, 3);
    HotDogStand cart3(3, 4);
    cout << HotDogStand::getTotalSold() << endl;

    cart1.JustSold();
    cart2.JustSold();
    cart3.JustSold();
    cout << cart1.getSold() << endl;
    cout << HotDogStand::getTotalSold() << endl;

    return 0;
}