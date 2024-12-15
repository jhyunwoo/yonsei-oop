#include <iostream>

using namespace std;

int main(){
 int a[10] = {1,2,3,4,5,6,7,8,9,10};
 typedef int* IntPtr;
 IntPtr p;
 p = a;
 // a = p; // ILLEGAL! 배열을 나타내는 포인터는 const이기 때문에 불가능
 cout << p[9] << endl;

 // 동적 길이 배열 생성
 typedef double * DoublePtr;
 DoublePtr d;
 d = new double[10]; //Size in brackets
 d[0] = 1.2;
 cout << d[0] << d[9] << endl;

 // int length;
 // cin >> length;
 // int intArray[length];
 // intArray[0] = 123;
 // cout << intArray[0] << endl;

 // int* someFunction(); // LEGAL! // int 배열을 반환하는 함수는 반환 타입이 pointer임.

 for (int i = 0; i < 10; i++)
  cout << *(d + i) << " " ; // 포인터 값에 더하기와 뺴기를 통해 배열의 전이나 다음 값에 접근 가능
 // 아래 코드는 위 코드와 같음
 // for (int i = 0; i < 10; i++)
 //  cout << d[i] << " " ;
 cout << endl;

 delete [] d; // 메모리 제거
 d = NULL;

 int e=10, b=20, c=24;
 e = b = c;

 cout << e << b << c<<endl;


 return 0;
}