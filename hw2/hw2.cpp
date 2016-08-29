/*Name:	Branden Messer
*filename: hw2.cpp
*Compiler: g++ -o hw2 hw2.cpp
*Sample usage: ./hw2
*/

#include <iostream>

using namespace std;

const double RATE = 0.001; // the constant rate between soda can and sugar
double mouseWeight, humanWeight, killMouse, killHuman; // the varibles you need.

int main() {
	cout << "What is the amout of artifical sweetner needed to kill a mouse: " << endl;

	cin >>  killMouse; // The amount to kill the mouse.
	cout << endl;
	
	cout << "What is the weight of the mouse: "; //The weight of the mouse.
	cin >>  mouseWeight;

	cout << endl;

	cout <<  "What is the weight of the dieter: "; //The weight of the dieter
	cin  >> humanWeight;
	
	double killHuman = (killMouse*humanWeight)/ mouseWeight;

	cout << endl;

	cout <<"You can drink " << killHuman/RATE <<"  diet soda without dying as a  result." << endl; 	
	
	
}
