#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int n, vec[1001], s, vec2[1001], m, aux;
bool  amschimbat;

ifstream fin("paresort.in");
ofstream fout("paresort.out");

int main(){

    fin >> n;
    for(int i = 1;i <= n;i++){
        fin >> vec[i];
        if(vec[i] % 2 == 0){
            m++;
            vec2[m] = vec[i];
        }
    }
    do{
        amschimbat = false;
        for(int i = 1; i<=m-1; i++){
            if(vec2[i] > vec2[i+1]){
                swap(vec2[i], vec2[i+1]);
                amschimbat = true;
            }
        }
    }while(amschimbat);    
    if(m > 0){
    	fout << m << endl;
    	for(int i = 1;i <= m;i++){
        	fout << vec2[i] << ' ';
    	}
    }
    else
        fout << "nu exista";

    return 0;
}