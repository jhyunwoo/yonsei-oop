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
		const double integratedA=(double)a/3, integratedB = (double)b/2, integratedC = (double)c;

		// Assign the result of the definite integral over the given range to a variable.
		const double resultOfX0 = integratedA*x0*x0*x0 + integratedB*x0*x0 + integratedC*x0;
		const double resultOfX1 = integratedA*x1*x1*x1 + integratedB*x1*x1 + integratedC*x1;

		// Write the difference between the value at x1 and the value at x0 to a file.
		outfile << resultOfX1-resultOfX0 <<endl;
	}

	outfile.close();

	return 0;
}
