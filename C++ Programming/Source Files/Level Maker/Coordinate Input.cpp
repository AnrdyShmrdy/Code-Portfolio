#include <iostream>
#include <fstream>
#include <string>
#include "Inputs and Outputs.h"
using namespace std;
void main(){
	cout << "This is a demonstration of how my scene creator will work." << endl;
	cout << "In this program,the coordinates will be stored. " << endl;
	cout << "Each odd-numbered line will be an x coordinate, and each even a y coordinate." << endl;
	cout << "Each group of coordinates would lie in pairs of lines. Each pair will correspond to a particular block." << endl;
	cout << "The pairs would be two line numbers that can be subtracted to get either 1 or -1, such as the first pair, lines 1 and 2" << endl;
	Input_Coordinates();
	cout << "All Done!" << endl;
	system("PAUSE");
}