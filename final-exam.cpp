#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
 // c-string part
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
 string s1, s2, s3;
 s3 = s1 + s2; //Concatenation
 s3 = "Hello Mom!"; //Assignment
 cout << s1 <<endl<< s2<<endl<< s3 << endl;

 cin.ignore();
 string line;
 cout << "Enter a line of input: ";
 getline(cin, line); // 인풋 받는 것, 저장할 변수를 넣어서 한 줄을 받음
 cout << line<<endl << "END OF OUTPUT"<<endl;

 return 0;
}