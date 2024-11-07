#include <iostream>

using namespace std;

class Robot
{
public:
void Set_Robot(int x, int y, int direction);
void move(int distance);
void left_face();
void right_face();
int get_x_position();
int get_y_position();
int get_orientation();
private:
int x_pos;
int y_pos;
int orientation;
};

int main()
{
Robot user;
user.Set_Robot(10, 10, 1);
user.move(10);
user.right_face();
user.move(10);
user.left_face();
user.left_face();
cout << user.get_x_position() << endl;
cout << user.get_y_position() << endl;
cout << user.get_orientation() << endl;
return 0;
	
}

void Robot::Set_Robot(int x, int y, int direction)
{
	x_pos = x;
	y_pos = y;
	orientation = direction;
}

void Robot::move(int distance)
{
	 switch(orientation)
{
case 0:
y_pos+=distance;
break;
case 1:
y_pos-=distance;
break;
case 2:
x_pos+=distance;
break;
case 3:
x_pos-=distance;
break;
default:
cout << "Wrong orientation" << endl;
}
}

void Robot::left_face()
{
switch(orientation)
{
case 0:
orientation = 3;
break;
case 1:
orientation = 2;
break;
case 2:
orientation = 0;
break;
case 3:
orientation = 1;
break;
}
}

void Robot::right_face()
{
switch(orientation)
{
case 0:
orientation = 2;
break;
case 1:
orientation = 3;
break;
case 2:
orientation = 1;
break;
case 3:
orientation = 0;
break;
}
}

int Robot::get_x_position()
{
return x_pos;
}

int Robot::get_y_position()
{
return y_pos;
}

int Robot::get_orientation()
{
return orientation;
}


