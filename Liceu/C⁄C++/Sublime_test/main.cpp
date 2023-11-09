#include <iostream>
#include <fstream>

using namespace std;

string text[6], text1;

ifstream fin("input.in");
ofstream fout("output.out");
ofstream fout2("output2.out");

int main(){

	for(int i = 1;i <= 5;i++){
		fin >> text[i];
	}
	for(int i = 1;i <= 5;i++){
		text1 = text1 + text[i];
	}
	fout << text1;
	fout2 << text1;
	
	
	return 0;
}