/**********************/
/*******Problem 1******/
/**********************/
/* ID: 2024148005     */
/* NAME: Jeon Hyunwoo */
/**********************/

/*!
 *
 * \file problem1.cpp
 * \brief Implement Collatz Conjecture
 * 
 * Collatz Conjecture
 * 
 * Calculate the Collatz algorithm,
 * and print the calculation process.
 * 
 * In the input file, the first row is the number of iterations.
 * Starting from the second row, each line represents the number N to be calculated.
 * 
 * The output file must contain the numbers from the calculation process.
 * 
 * It is recommended that you write your own code on the lines provided,
 * but you are free to do so by modifying the skeleton code.
 */

#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
const string InputFilePath  = "input1.txt";
const string OutputFilePath = "answer1.txt";
//---------------------------------------------------------------------------
int main(void)
{
  ifstream Ifs{InputFilePath};
  if (Ifs.fail()) {
    cerr << "Failed to open input file\n";
    return 0;
  }
  ofstream Ofs{OutputFilePath};

  // TODO: Implement Collatz Conjecture Algorithm.
  // 반복 횟수를 받을 변수 선언
  int loop;
  // 파일에서 첫 번째 줄에 있는 반복 횟수를 변수에 저장
  Ifs >> loop;

  // 반복 횟수 만큼 아래 코드 반복
  for(int i=0; i<loop; i++)
  {
    // 처음 시작하는 숫자를 저장할 변수 선언
    int start;
    // 파일에서 첫 번째 숫자 받아와서 변수에 저장
    Ifs >> start;
    // 시작하는 숫자 파일에 작성
    Ofs << start << "\n";
    // 숫자가 1이 될 때 까지 반복
    while(start!=1)
     {
      // 숫자가 짝수일 경우
      if(start % 2 == 0)
      {
        // 숫자를 2로 나눔
        start /= 2;
      }
      // 숫자가 홀수일 경우
      else
      {
        // 숫자에 3을 곱하고 1을 더해줌
        start = 3*start + 1;
      }
      // 결과를 파일에 작성
      Ofs << start << "\n";
     }
  }

  Ifs.close();
  Ofs.close();

  return 0;
}
//---------------------------------------------------------------------------