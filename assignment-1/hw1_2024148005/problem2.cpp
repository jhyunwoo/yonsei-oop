#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 2******/
/**********************/
/* ID: 2024148005     */
/* NAME: JEON Hyunwoo */
/**********************/

/**
 * Function to move the target
 * @param x Pointer to the target's x-coordinate
 * @param y Pointer to the target's y-coordinate
 * @param dir Direction of movement
 * @param i Loop term
 * @param j Movement term
 */
void move(int &x, int &y, const char dir, const int i, const int j)
{
	// switch-case for distinguishing movement direction.
    switch(dir)
    {
    	// If the target character is 'h', decrease the x-coordinate by 1.
	    case 'h':
	        x--;
	        break;
    	// If the target character is 'l', increase the x-coordinate by 1.
	    case 'l':
	        x++;
	        break;
    	// If the target character is 'j', decrease the y-coordinate by 1.
	    case 'j':
	        y--;
	        break;
    	// If the target character is 'k', increase the y-coordinate by 1.
	    case 'k':
	        y++;
	        break;
    	// If direction is invalid, print error on console.
	    default:
	        cout<<"Wrong movement in iteration "<<i<<", movement "<<j<<endl;
	        break;
    }
}

int main(){
	int loopNum;

	ifstream infile("input2.txt");

	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		int a_x, a_y;
		int b_x, b_y;
		int c_x, c_y;
		infile >> a_x >> a_y;
		infile >> b_x >> b_y;
		infile >> c_x >> c_y;

		int moveNum;
		infile >> moveNum;

		for (int j = 0; j < moveNum; ++j) {
			char target;
			char dir;
			infile >> target >> dir;

			// switch-case for distinguishing moving targets
			switch (target)
            {
				// If the target is A, use the move function to move A.
                case 'a':
                    move(a_x, a_y, dir, i, j);
                    break;
				// If the target is B, use the move function to move B.
                case 'b':
                    move(b_x, b_y, dir, i, j);
					break;
				// If the target is C, use the move function to move C.
                case 'c':
                	move(c_x, c_y, dir, i, j);
					break;
				// If target is invalid, print error on console.
                default:
                    cout<<"Wrong movement in iteration "<<i<<", movement "<<j<<endl;
                    break;
            }
		}

		cout << "Position of A: (" << a_x << ", " << a_y << ")" << endl;
		cout << "Position of B: (" << b_x << ", " << b_y << ")" << endl;
		cout << "Position of C: (" << c_x << ", " << c_y << ")";
		// 마지막 루프일 경우 endl을 출력하지 않음
		if(i!=loopNum-1)
		{
			cout<<endl;
		}
        
	}

	infile.close();

	return 0;
}
