#include <iostream>
using namespace std;

void sol(int manp[][3], int womanp[][3], int man, int woman[]);
bool ok(int q[], int col);
void print(int match[]);

int main(){

	int mp[3][3]={{0,2,1}, {0,2,1}, {1,2,0}};
	int wp[3][3]={{2,1,0}, {0,1,2}, {2,0,1}};
	int w[3];
	int m = 0;

	sol(mp, wp, m, w);

return 0;
}


void sol(int manp[][3], int womanp[][3],  int man, int woman[]){

	if (man >= 3){
		print(woman);
		return;
	}

	for (int i=0; i<3; i++){
		woman[man]=i;
		if (ok(woman, man)){
		sol(manp, womanp, man+1, woman);
		}
	}
return;
}


bool ok(int q[], int col){

	int mp[3][3]={{0,2,1}, {0,2,1}, {1,2,0}};
	int wp[3][3]={{2,1,0}, {0,1,2}, {2,0,1}};
	int nm = col, nw = q[col];

	for (int i = 0; i < col; ++i) {
		int cm = i, cw = q[i];
		if(cw==nw) return false;
		if((mp[cm][nw]<mp[cm][cw])&&(wp[nw][cm]<wp[nw][nm])) return false;
		if((mp[nm][cw]<mp[nm][nw])&&(wp[cw][nm]<wp[cw][cm])) return false;
	}
	return true;
}


void print(int match[]){

	for (int i=0; i<3; i++)
		cout << "man(" << i << ")" << " = " << "woman(" << match[i] << ") " << endl;
		cout << endl;
}

