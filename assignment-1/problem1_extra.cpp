#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 1******/
/**********************/
/* ID: 2024148005     */
/* NAME: JEON Hyunwoo */
/**********************/

double getIntegral(const double a, const double b, const double c, const double x0, const double x1){
	return (a*x1*x1*x1 + b*x1*x1 + c*x1) - (a*x0*x0*x0 + b*x0*x0 + c*x0);
}

int main(){
	int loopNum;

	ofstream outfile;
	outfile.open("output1.txt");

	cout << "Enter the number of interations for the loop: ";
	cin >> loopNum;

	for (int i = 0; i < loopNum; i++) {
		int a, b, c;
		int x0, x1;
		cout << "Enter the coefficients of the equation [y = ax^2 + bx + c]" << endl;
		cout << "a: "; cin >> a;
		cout << "b: "; cin >> b;
		cout << "c: "; cin >> c;
		cout << "Enter the value of x0 and x1" << endl;
		cout << "x0: "; cin >> x0;
		cout << "x1: "; cin >> x1;

        // To fix the precision of floating numbers
        outfile << setprecision(3) << fixed;

		// Convert data of type int to double using static_cast<double> and assign the value of the calculated expression for the integrated coefficient to a new variable.
		const double integratedA=static_cast<double>(a)/3, integratedB = static_cast<double>(b)/2, integratedC = c;
		double sum0;
		double sum1;

		// 일차함수일 경우 근을 구하는 식을 달리 함
		if(a == 0)
		{
			sum0 = -(static_cast<double>(c)/static_cast<double>(b));
			sum1 = -(static_cast<double>(c)/static_cast<double>(b));
		}else
		{
			sum0 = (-b-sqrt(b*b-4*a*c))/(2*a);
			sum1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		}

		if(sum0>sum1)
		{
			const double buffer = sum0;
			sum0 = sum1;
			sum1 = buffer;
		}

		// Assign the result of the definite integral over the given range to a variable.
		double result = 0;

		// Check x0 is lower than x1
		if(x0>x1){
			const int xBuffer = x1;
			x1 = x0 ;
			x0 = xBuffer;
		}

		// 이차식의 두 근이 존재할 경우 구간을 나누어 면적을 구함
		if(!isnan(sum0) && !isnan(sum1)){
			// 이차식의 근이 넓이를 구하는데 영향을 주지 않는 경우 적분 후 절댓값을 답으로 반환
			if(sum0<x0 && x1<sum1 || x1<sum0 && x1<sum1 || sum1<x0 && sum0<x0){
				result = abs(getIntegral(integratedA, integratedB, integratedC, x0, x1));
			} else if(x0<sum0 && x1<sum1){
				// 구간을 나누어 적분 후 절댓값을 모두 더해 답으로 반환
				result  = abs(getIntegral(integratedA, integratedB, integratedC, x0, sum0)) + abs(getIntegral(integratedA, integratedB, integratedC, sum0, x1));
			} else if(x0 < sum0 && sum1 < x1){
				// 구간을 나누어 적분 후 절댓값을 모두 더해 답으로 반환
				result  = abs(getIntegral(integratedA, integratedB, integratedC, x0, sum0)) + abs(getIntegral(integratedA, integratedB, integratedC, sum0, sum1)) + abs(getIntegral(integratedA, integratedB, integratedC, sum1, x1));
			} else if(sum0 < x0 && sum1 < x0){
				// 구간을 나누어 적분 후 절댓값을 모두 더해 답으로 반환
				result  = abs(getIntegral(integratedA, integratedB, integratedC, x0, sum1)) + abs(getIntegral(integratedA, integratedB, integratedC, sum1, x1));
			}
			else {
				// 만약 예상치 못한 케이스가 나올 경우 경고 문구 출력
				cout<<"!!!! Undefined Condition !!!!" << endl;
			}
		} else{
			// 근이 존재하지 않을 경우 적분 후 절댓값 반환
			result = abs(getIntegral(integratedA, integratedB, integratedC, x0, x1));
		}

		// Write the difference between the value at x1 and the value at x0 to a file.
		outfile << result <<endl;
	}

	outfile.close();

	return 0;
}
