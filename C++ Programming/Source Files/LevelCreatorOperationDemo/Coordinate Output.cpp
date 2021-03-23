#include <iostream>
#include <fstream>
#include <string>
#include "Inputs and Outputs.h"
using namespace std;
void main() {
cout << "This is a demonstration of how my scene creator will work." << endl;
cout << "In this program,the coordinates will be recalled and used. " << endl;
cout << "The number " << OtherNum << " will be altered by the change value" << endl;
AssignSpecificLine(0, 2, line_count);
Input_Line_Info();
AssignFromLine(line2READ,OtherNum);
cout << "The Number has now been changed to: " << OtherNum << endl;
system("PAUSE");
}