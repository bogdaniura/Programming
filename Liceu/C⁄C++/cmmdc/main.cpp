#include <fstream>

using namespace std;

int a, b;

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int cmmdc(int d, int i){
	int r;
	do{
		r = d % i;
		d = i;
		i = r;

	}while(i > 0);
	return d;
}

int main(){
	fin >> a >> b;
	fout << cmmdc(a, b);
}