#include <iostream>
#include <cstdlib>
using namespace std;


bool NC(int c, int q[8]);
bool NR(int c, int q[8]);
bool backtrack(int c, int q[8]);
bool print(int col, int q[8], int count);

static int n=0;
int main(){

	int q[8], c=0;
        q[0] = 0;

	NC(c,q);
}

bool NC(int c, int q[8]){

	c++;
        if(c==8){
		print(c,q,n);
	}
        q[c] == -1;
	NR(c,q);
}

bool NR(int c, int q[8]){
	int i;

	q[c]++;
        if(q[c]==8) backtrack(c,q);

        //Test
	 for(i=0; i<c; i++)
		 if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])){
			NR(c,q);
		}
	 NC(c,q);
}

bool backtrack(int c, int q[8]){
	c--;
	if(c==-1){
		cout << "Every solution was found." << endl;
 		return 0;
	    }
	NR(c,q);
}

bool print(int col, int q[8], int count){
	for(int i=0; i<8; i++){
		for(int j=0; i<8; i++){
			if(q[j]==i) cout << "1";
			else cout << "0";
		}
		cout << endl;
	}
	count++;
	cout << "Solution# " << count << endl;
	cout << endl;
	
	backtrack(col, q);
}
	
