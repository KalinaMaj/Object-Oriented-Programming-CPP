#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int a[][5], int x[], int col);
void print(int z[]);
bool backtrack(int &c);

int main(){
	int adjs[8][5] = {
		{-1},
		{0,-1},
		{0,1,-1},
		{0,2,-1},
		{1,2,-1},
		{1,2,3,4,-1},
		{2,3,5,-1},
		{4,5,6,-1}};
	int q[8];
	int c = 0;

	for(int i=0; i<5; i++){
       		if(ok(adjs,q,c) &&  adjs[c][i]==-1){
       			c++;
       			if(c==8){
       				print(q);
       				backtrack(c);
			}
		}
	}

	for(int i=1;i<=8;i++){
		q[c]=i;
		if(i>8){
			q[c] = 0;
			backtrack(c);
		}
	}
}

bool ok(int a[][5], int x[], int col){

	for(int i=0; i<col; i++){
		if(x[col]==x[i]) 
			return false;
	}
	for(int j=0; a[col][j] != -1; j++){
		if(1==abs(x[col]-x[a[col][j]]))
			return false;
	}
	return true;
}

bool backtrack(int &c){
	c--;
	if(c == -1){
		return 0;
	}
}

void print(int z[]){

	cout << " ";
	for(int i=0; i<=1; i++)
		cout << z[i];
	cout << " ";
	for(int i=2; i<=5; i++)
		cout << z[i];
	cout << " ";
	for(int i=6; i<=7; i++)
		cout << z[i];
	cout << " " << endl;
	cout << endl;
}
