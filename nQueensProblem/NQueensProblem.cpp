#include <iostream>
#include <cmath>
using namespace std;

void solution(int* q, int i, int n);
bool ok(int q[], int c);
int sol = 0;

int main(){

	int n=0;
	int col = 0;

	while(1){

		cout << "Enter the size of the board: ";
		cin >> n;
		if(n < 0) break;

		int* q = new int[n];

		solution(q, col, n);
		cout << "There are " << sol << " solutions to the " << n << " queens problem.";
		sol = 0;
		delete[] q;
		cout << endl;
	}

return 0;
}

void solution(int* q, int i, int n){
	if(i == n){
		sol++;
	}
	else{
		for(int j = 0; j < n; ++j){
			q[i] = j;
			if(ok(q, i))
				solution(q, i+1, n);
		}//for
	}//else
}

bool ok(int q[], int c){

	for(int i=0; i<c; i++){
		if(q[c]==q[i] || (c-i)==abs(q[c]-q[i]))
			return false;
	}
	return true;
}
