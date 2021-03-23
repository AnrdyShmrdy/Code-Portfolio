#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <SFML\My Additions\sfml.h>
using namespace std;
using namespace sf;
int line2READ;
int lineMax;
string value;
string num = "55";
int OtherNum = 33;
string response;
string NumInput;
int line_count;
template <typename T>
string toString(T arg)
{
	stringstream ss;
	ss << arg;
	return ss.str();
}
int StringToNum(string input) {
	string::size_type sz;   // alias of size_t
	int i_dec = stoi(input, &sz);
	return i_dec;
}
void Input_Coordinates() {
	ofstream myfile("level.txt");
	cout << "First off, how many lines do you want?" << endl;
	cout << "Note: the first line is excluded for use in storing the line amount, meaning line 1 is really line 2." << endl;
	cin >> line_count;
	if (myfile.is_open())
	{
		myfile << line_count << endl;
		for (int i = 0; i < line_count; i++) {
			cout << "input for line " << i + 1 << endl;
			cin >> NumInput;
			myfile << NumInput << endl;
		}
	}
	else cout << "Unable to open file";
}
void ReadingFile() {
	string line;
	ifstream myfile("level.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}
void SpecificLine(int input_line, int input_max) {
	string line;
	ifstream myfile("level.txt");
	if (myfile.is_open())
	{
		for (int lineno = 0; getline(myfile, line) && lineno < input_max; lineno++) {
			if (lineno == input_line) {
				cout << "the line you selected contains: " << line << endl;
				myfile.close();
			}
		}
	}
}
void AssignFromLine(int input_line, int &input_changeValue) {
	string line;
	ifstream myfile("level.txt");
	if (myfile.is_open())
	{
		for (int lineno = 0; getline(myfile, line) && lineno < line_count + 1; lineno++) {
			if (lineno == input_line) {
				value = line;
				input_changeValue = StringToNum(value);
				cout << "The line selected contained " << line << ". The change value is now " << value << endl;
				myfile.close();
			}
		}
	}
}
void Input_Line_Info() {
	cout << "There are " << line_count << " total." << endl;
	cout << "type which line you want to use" << endl;
	cin >> line2READ;
}
void Input_Answer() {
	cin >> response;
}
void AssignSpecificLine(int input_line, int input_max, int& assigned_value) {
	string line;
	ifstream myfile("level.txt");
	if (myfile.is_open())
	{
		for (int lineno = 0; getline(myfile, line) && lineno < input_max; lineno++) {
			if (lineno == input_line) {
				assigned_value = StringToNum(line);
				myfile.close();
			}
		}
	}
}
void Input_Single_Line(int input_value) {
ofstream myfile("level.txt");
if (myfile.is_open())
{
	myfile << toString(input_value) << endl;

}
else cout << "Unable to open file";
}
void Input_Coordinates_2_Lines(int input_value, int input_value2) {
	ofstream myfile("level.txt");
	if (myfile.is_open())
	{
		myfile << toString(input_value) << endl;
		myfile << toString(input_value2) << endl;

	}
	else cout << "Unable to open file";
}
void Input_ALL_Coordinates(vector<Vector2i>Input_Vector){
ofstream myfile("level.txt");
if (myfile.is_open())
{
	myfile << toString(Input_Vector.size() * 2) << endl;
	for (std::size_t i = 0; i < Input_Vector.size(); i++) {
		myfile << toString(Input_Vector[i].x) << endl;
		myfile << toString(Input_Vector[i].y) << endl;
	}
}
else cout << "Unable to open file";
}
int ReturnLineValue(int input_line, int input_max) {
	string line;
	int num;
	ifstream myfile("level.txt");
	if (myfile.is_open())
	{
		for (int lineno = 0; getline(myfile, line) && lineno < input_max; lineno++) {
			if (lineno == input_line) {
				num = StringToNum(line);
				myfile.close();
			}
		}
	}
return num;
}