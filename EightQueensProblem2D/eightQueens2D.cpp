#include <iostream>
using namespace std;

int main(){

	int q[8][8] = {0}, r, c=0, n=0, i;

	q[0][0] = 1;
NC:	c++;
	if(c==8) goto print;
	r = -1;

NR:	r++;
	if(r==8) goto backtrack;

	for(i=0; i<c; i++)			//Row Test
		if(q[r][i] = 1) goto NR;

	for(i=1; (r-1)>=0 && (c-i)>=0; i++)	//UpDiagonal Test
		if(q[r-i][c-i] == 1) goto NR;

	for(i=1; (r+1)<=8 && (c-i)>=0; i++)	//DownDiagonal Test
		if(q[r+i][c-i]==1) goto NR;

	q[r][c] = 1;
	goto NC;

backtrack: c--;
	if(c == -1) return 0;
	r = 0;
	while(q[r][c] != 1) r++; 	
	q[r][c] = 0;
	goto NR;

print:	for(i=0; i<8 ; i++){
		for (int j=0; j<8; j++){
			cout << q[i][j];
		}
		cout << endl;
	}
	n++;
	cout << "Solution " << n << ": " << endl;
	cout << endl;

	goto backtrack;
}

