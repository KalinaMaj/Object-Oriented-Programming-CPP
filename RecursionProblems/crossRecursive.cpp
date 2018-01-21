#include <iostream>
#include <cmath>
using namespace std;

bool sol(int adj[][5], int q[], int col);
bool ok(int a[][5], int q[], int m);
void print(int q[]);

int main(){

	int adj[8][5] = {{-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1}};
	int q[8];

	sol(adj, q, 0);
	return 0;
}

bool sol(int adj[][5], int q[], int col){

	if (col >= 8){
       	print(q);
	return false;
	}

	for (int i=1; i<=8; i++){
		q[col]=i;
		if (ok(adj, q, col)){
			if (sol(adj, q, col+1)) 
				return true;
		}
	}
	return false;
}


bool ok(int a[][5], int q[], int m){

	for(int i=0; i<m; i++){
		if(q[m]==q[i])
			return false;
	}
	
	for (int j=0; a[m][j] != -1; j++){
        if (1 == abs(q[m] - q[a[m][j]])) 
			return false;
    }
	return true;
}


void print(int q[]){

	cout << " ";
	for (int i=0; i<=1; i++)
		cout << q[i];
	cout << " " << endl;
	for (int i=2; i<=5; i++)
		cout << q[i] << "\n";
	for (int i=6; i<=7; i++)
		cout << q[i];
	cout << " " << endl;
	cout << endl;
}
