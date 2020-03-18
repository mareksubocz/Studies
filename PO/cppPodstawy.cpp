#include <iostream>
using namespace std;

int liczba = 10;

void napisz(int &a){
	cout<<a<<endl;
}

int & aliasik(){
	int & a = liczba;
	return a;
}

int main(){
	aliasik() = 5;
	cout<<liczba<<endl;
	return 0;
}