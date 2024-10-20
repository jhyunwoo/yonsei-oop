#include <iostream>
// String Type를 사용하기 위해 필요
#include <string>

using namespace std; // std namespace를 사용

void printTitle(const string& title);
void square(int& n);
void justPrintIt(int& n);
float average(int n1=1, int n2=1); // Default value -> average(4)로 call 하면 4와 1의 평균 return
float average(int n1, int n2, int n3);
float arrayAverage(int n[], int size);

class User
{
public:
    void output();
    User(string name, int age, int point, float height, string school);
    User();
    static void countryOut();
    static string country;
private:
    string name;
    int age;
    int point;
    float height;
    string school;
};

class Item
{
public:
    Item(string name, int level);
    int getLevel() const;
    string getName() const;
    friend bool operator ==(const Item& item1, const Item& item2)
    {
        return item1.level == item2.level && item1.name == item2.name;
    }
    friend ostream& operator <<(ostream& outputStream, const Item& item)
    {
        return outputStream << item.name << " " << item.level;
    }
    friend istream& operator >>(istream& inputStream, Item& item)
    {
        return inputStream >> item.name >> item.level;
    }

private:
    string name;
    int level;
};

const Item operator +(const Item& item1, const Item& item2)
{
    int totalLevel = item1.getLevel() + item2.getLevel();
    return Item("New", totalLevel);
}


string User::country = "Korea";

int main()
{
    printTitle("변수 정의");
    short veryShortNumber = 2; // 2 Bytes, 음수 양수 표현, 소수점 없음
    int intNumber = 12; // 4 Bytes, 음수 양수 표현, 소수점 없음
    long longNumber = 121241; // 4 Bytes, 음수 양수 표현, 소수점 없음
    float floatNumber = 3.141592; // 4 Bytes, 음수 양수 표현, 7번째 소수점까지 표현
    double doubleNumber = 3.1415926535897932; // 8 Bytes, 음수 양수 표현, 15번째 소수점까지 표현
    long double longDoubleNumber = 3.1415926535897932; // 10 Bytes, 음수 양수 표현, 19번째 소수점까지 표현
    char charVariable = 'A'; // 1 Byte, 모든 ASCII 문자 표현
    bool boolVariable = true; // 1 Byte, 참 또는 거짓 표현

    /* 변수에 값 할당할 때 타입이 일치하지 않는 경우 */
    printTitle("변수에 값 할당할 때 타입이 일치하지 않는 경우");
    intNumber = 3.98; // intNumber에 3만 할당됨
    cout << intNumber << endl;

    /* Escape Sequences */
    printTitle("Escape Sequences");
    cout << '\n' << endl; // 다음 줄
    cout << '\r' << endl; // Return
    cout << '\t' << endl; // 가로 탭
    cout << '\a' << endl; // alt
    cout << '\\' << endl; // \ 백 슬래시
    cout << '\'' << endl; // 따옴표
    cout << '\"' << endl; // 쌍따옴표

    /* Constant 상수 선언 */
    printTitle("Constant 상수 선언");
    const int NUMBER_OF_STUDENTS = 20;
    // NUMBER_OF_STUDENTS = 30; -> const로 선언된 상수는 변경 불가

    /* Arithmetic Precision */
    printTitle("Arithmetic Precision");
    cout << 15 / 5 << endl; // 결과: 3 -> 숫자가 모두 int 타입이기 때문에 나눈 결과도 int 타입
    cout << 17.0 / 5 << endl; // 결과: 3.4 -> 17.0이 float이기 때문에 나눈 결과도 자동으로 float
    cout << 1 / 2 / 3.0 / 4 << endl; // 결과: 0 -> 1/2 = 0 (int 타입이기 때문), 0/3.0 = 0.0, 0.0/4 = 0.0

    /* 타입 변경 (Type Casting) */
    printTitle("타입 변경 (Type Casting)");
    cout << static_cast<float>(1) / 2 / 3.0 / 4 << endl; // 결과: 0.0416667, static_cast<float>으로 1의 타입을 int에서 float로 변경

    /* 축약 연산자 (shorthand operators) */
    printTitle("축약 연산자 (shorthand operators)");
    int point=0;
    int score=0;
    point++; // 더하기 1
    --point; // 빼기 1

    score = point++; // 후행 연산자이므로 score에 point를 할당한 후 point를 1 증가시킴
    cout << score << endl;
    score = ++point; // 선행 연산자이므로 point를 1증가시킨 이후 score에 point 할당
    cout << score << endl;

    /* String Type*/
    printTitle("String Type");
    string firstName = "Hyunwoo";
    string lastName = "Jeon";
    string fullName = firstName + ' ' + lastName;
    cout << fullName << endl;

    /* 입력 받기 */
    printTitle("입력 받기");
    string inputTest;
    cout << "Input Test: ";
    cin >> inputTest;
    cout << "Input Result: "<< inputTest << endl;

    /* 연산 우선 순위 */
    printTitle("연산 우선 순위");
    int x = 0;
    int y = 0;
    x++;
    ++x;
    cout << (x>1 && ++y) << endl;

    /* switch case example */
    printTitle("switch case example");
    int typeVariable;
    cout << "0부터 3까지의 숫자 중 하나를 입력하세요: ";
    cin >> typeVariable;

    switch (typeVariable)
    {
    case 0:
        cout << "0 Case!" << endl;
        break;
    case 1:
        cout << "1 Case!" << endl;
        break;
    case 2:
        cout << "2 Case!" << endl;
    case 3:
        cout << "3 Case!" << endl;
        break;
    default:
        cout << "Invalid Input!" << endl;
    }

    /* Conditional Operator */
    printTitle("Conditional Operator");
    int z;
    cout << "Enter Number: ";
    cin >> z;
    string k = z==1 ? "input is 1" : "input is not 1";
    cout << k << endl;

    /* while loop */
    printTitle("While Loop");
    int count = 0;
    while(count < 3)
    {
        cout << "Count is " << count++ << endl;
    }

    /* do while loop */
    printTitle("Do While loop");
    count = 0;
    do
    {
        cout << "Count is " << count++ << endl;
    }while(count < 0); // do while 은 첫 번째 작동은 무조건 함

    /* Comma Operator */
    int second;
    int first = (first =2, second = first + 1);
    printTitle("Comma Operator");
    cout << first << " " << second << endl;

    /* for loop syntax */
    printTitle("for loop syntax");
    for(int i=0; i< 3; i++)
    {
        cout << i << endl;
    }

    /* break and continue */
    printTitle("break and continue");
    while (true)
    {
        int whileInput;
        cout << "Enter any number: ";
        cin >> whileInput;
        if(whileInput)
        {
            break; // input이 0이 아니라면 while 정지
        } else
        {
            continue; // continue 때문에 아래 cout이 작동하지 않음
        }
        cout << "This sentence is not prompted!" << endl;
    }

    /* Random Number Generator*/
    printTitle("Random Number Generator");
    cout << rand() << endl;
    cout << rand()%6 << endl;
    cout << rand()%6+1 << endl;

    /* Random Number Generator with Seed*/
    srand(time(0));
    cout << rand() << endl;
    cout << rand() << endl;

    cout << "Random Number between 0.0 & 1.0" << endl;
    cout << (RAND_MAX - rand())/static_cast<double>(RAND_MAX) << endl;

    /* Call by Reference */
    printTitle("Call by Reference");
    int data = 2;
    square(data);
    cout << data << endl;

    /* Overloading */
    printTitle("Overloading");
    cout << average(1,2) << endl;
    cout << average(2,3,5) << endl;

    /* Array */
    printTitle("Array");
    int scores[4] = {4,2,10,4};
    int b[] = {1,2,3,4,5,6,7}; // b array 사이즈는 자동으로 7이 됨

    cout <<"scores 배열 주소: "<< scores << endl;
    int totalScore = 0;
    for(int i=0; i < 4; i++)
    {
        cout << scores[i] << endl;
        totalScore += scores[i];
    }
    cout << "Total Score: " << totalScore << endl;

    /* Structure */
    printTitle("Structure");
    struct Person
    {
        string name;
        int age;
        int point;
        float height;
    };

    Person user = {"Hyunwoo", 20, 10, 180.7};
    cout << user.age << endl;

    /* Class */
    printTitle("Class");
    User user1 = User("Hyunwoo", 20, 0, 180.7, "Yonsei Univ.");
    user1.output();
    User anonymous; // argument 없이 class 선언
    anonymous.output();

    /* Static Member and Function */
    printTitle("Static Member and Function");
    user1.countryOut();
    anonymous.countryOut();
    User::countryOut();

    User::country = "UK";
    user1.countryOut();
    anonymous.countryOut();
    User::countryOut();

    /* Operator in class */
    Item item1 = Item("Hello", 1);
    Item item2 = Item("world", 2);
    Item upgrade = item1 + item2;
    cout << upgrade.getLevel() << endl;
    Item newItem = Item("New", 3);
    cout << newItem.getLevel() << endl;
    cout << upgrade.getLevel() << endl;
    cout << newItem.getName() << endl;
    cout << upgrade.getName() << endl;
    cout << (upgrade == newItem) << endl;

    cout << "Update Item: ";
    cin >> newItem;
    cout << newItem << endl;

    return 0; // 함수의 종료를 명시적으로 표현
}

void printTitle(const string& title)
{
    cout << "---------- " << title << " ----------" << endl;
}

void square(int& n)
{
    n = n*n; // 주소 값을 입력 받아 해당 변수의 제곱을 변수에 재할당
}

void justPrintIt(const int& n)
{
    cout << n << endl; // n에 있는 값을 수정하지 않고 읽기만 함 (const를 통해 명시)
}

// 입력 2개인 경우 실행
float average(int n1, int n2)
{
    return (float)(n1+n2)/2;
}
// Overloading 입력 3개인 경우 실행
float average(int n1, int n2, int n3)
{
    return (float)(n1+n2+n3)/3;
}

float arrayAverage(int n[], int size)
{
    int total = 0;
    for(int i=0; i < size; i++)
    {
        total += n[i];
    }
    return static_cast<float>(total)/size;
}

void User::output()
{
    cout << "Name: " << name << endl;
}

User::User(string name, int age, int point, float height, string school):name(name), age(age), point(point), height(height), school(school)
{}

User::User():name("none"), age(0), point(0), height(0), school("none"){}

void User::countryOut()
{
    cout << country << endl;
}

Item::Item(string name, int level):name(name), level(level)
{
}

int Item::getLevel() const
{
    return level;
}

string Item::getName() const
{
    return name;
}


