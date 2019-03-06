//½øÖÆ×ª»»
#include <iostream>
#include <string>
using namespace std;

int main() 
{ 
	string s = "", table = "0123456789ABCDEF"; 
	int M = 0, N = 0; 
	cin >> M >> N; 
	if( M == 0) 
	{ 
		s ="0";
	} 
	while( M ) 
	{ 
		if( M < 0 ) 
		{ 
			M = -M; 
			cout << "-"; 
		} 
		s = table[M % N] + s; 
		M /= N; 
	} 
	cout << s << endl; 
	system("pause");
	return 0; 
}