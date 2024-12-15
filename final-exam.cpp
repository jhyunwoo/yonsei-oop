#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void printTitle(const string& title)
{
 cout << "---------- " << title << " ----------" << endl;
}

int main(){
 // c-string part
 printTitle("C-string");
 char hello[12] = "Hello World"; // 11개 문자 저장
 char shortString[] = "abc"; // 크기를 지정하지 않아도 문자에 맞는 크기 자동 설정
 cout << hello << endl;
 cout << shortString << endl;
 cout << shortString[3] << endl;
 char aString[4] = "ab";
 char anotherString[3] = "ab";

 if (strcmp(aString, anotherString)) // strcmp는 같으면 0, 앞 변수가 작으면 음수, 앞 변수가 더 크면 양수를 반환
  cout << "Strings NOT same." << endl;
 else
  cout << "Strings are same." << endl;

 cout << strcmp(aString, anotherString) << endl;

 char myString[10] = "dobedo";
 cout << strlen(myString) << endl; // 글자의 길이를 반환 (\0은 제외)

 char stringVar[20] = "The rain";
 strcat(stringVar, "in Spain"); // stringVar에 "in Spain"을 더함
 cout << stringVar << endl;

 char a[80], b[80];
 cout << "Enter input: ";
 cin >> a >> b;  // 띄어쓰기나 엔터로 문자를 구분해서 받음
 cout << a << b <<endl<< "END OF OUTPUT\n";

 char c[80];
 cout << "Enter input: ";
 cin.ignore(); // 엔터로 입력했을 때 남아있는 개행문자 무시
 cin.getline(c, 80); // 한 줄 전체를 받음 (띄어쓰기 구분 X), 두 번째 숫자를 통해 얼마나 긴 문자를 받을 건지 명시
 cout << c << endl << "END OF OUTPUT\n";

 char nextSymbol;
 cin.get(nextSymbol); // 한 문자만 받음
 cout.put(nextSymbol) << endl;

 // string part
 printTitle("string");
 string s1, s2, s3;
 s3 = s1 + s2; //Concatenation
 s3 = "Hello Mom!"; //Assignment
 cout << s1 << s2<< s3 << endl;

 cin.ignore();
 string line;
 cout << "Enter a line of input: ";
 getline(cin, line); // 인풋 받는 것, 저장할 변수를 넣어서 한 줄을 받음
 cout << line<<endl << "END OF OUTPUT"<<endl;

 // pointer part
 printTitle("Pointer");
 double *p; // double 타입의 포인터
 int *p1, *p2, v1, v2; // p1과 p2는 int타입의 변수 주소를 저장하는 포인터, v1과 v2는 int 타입을 저장하는 변수
 p1 = &v1; // v1의 주소를 p1에 할당 (&를 통해 변수의 주소를 가져올 수 있음)
 cout << v1 << endl;
 cout << *p1 << endl; // 위에 것과 현재 줄의 코드는 같은 동작을 함 (모두 v1을 출력) (포인터가 가르키고 있는 변수의 값을 활용할 때는 *을 사용)

 v1 = 0;
 p1 = &v1;
 *p1 = 42;
 cout << v1 << endl;
 cout << *p1 << endl;

 int *p11; // 포인터 선언
 p11 = new int; // 이름 없는 변수 선언, *p11으로 값에 접근 가능
 *p11 = 23; // 이름 없는 변수에 23 할당
 cout << p11 << endl; // 이름 없는 변수의 주소 출력
 cout << *p11 << endl; // 이름 없는 변수의 값 출력
 delete p11; // 메모리 할당 제거
 p11 = NULL; // 메모리를 포인팅 하는 것을 제거

 typedef int* IntPtr; // 커스텀 타입 선언 (int 타입 변수를 가리키는 포인터 타입)
 IntPtr pp;
 // int *pp; // 위 줄과 같은 작용

 return 0;
}