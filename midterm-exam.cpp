#include <iostream>
// String Type를 사용하기 위해 필요
#include <string>

using namespace std; // std namespace를 사용

void printTitle(const string& title);

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

    return 0; // 함수의 종료를 명시적으로 표현
}

void printTitle(const string& title)
{
    cout << "---------- " << title << " ----------" << endl;
}