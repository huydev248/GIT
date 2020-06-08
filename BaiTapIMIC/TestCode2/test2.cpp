#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream file("test.txt");
	char name[100];
	cin.getline(name, 100);

	file << name << endl;

	file.close();

	return 0;
}