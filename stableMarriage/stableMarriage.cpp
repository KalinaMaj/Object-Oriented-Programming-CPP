#include <iostream>
using namespace std;

bool soln(int manp[][3], int womanp[][3], int man, int woman[]);
bool ok(int manp[][3], int womanp[][3], int man, int woman[]);
void print(int stable[]);

int main(){

	int mp[3][3]={{0,2,1},
		      {0,2,1},
		      {1,2,0}};
	int wp[3][3]={{2,1,0},
		      {0,1,2},
		      {2,0,1}};
	int w[3];
	int m = 0;
	soln(mp, wp, m, w);
	
return 0;
}


bool soln(int manp[][3], int womanp[][3], int man, int woman[]){

	if(man >= 3){
		print(woman);
		return false;
	}

	for(int i=0; i<3; i++){
		woman[man] = i;
		if(ok(manp, womanp, man, woman)){
			if(soln(manp, womanp, man+1, woman)) return true;
		}
	}
	return false;
}


bool ok(int manp[][3], int womanp[][3], int man, int woman[]){

	if(man == 0) return true;
	for(int i=0; i<man; i++){
		if(woman[man] == woman[i])
			return false;

		 if(manp[man][woman[man]] > manp[man][woman[i]])
                        if(womanp[woman[i]][i] > womanp[woman[i]][man])
                        return false;

		if(womanp[woman[man]][man] > womanp[woman[man]][i])
                        if(manp[i][woman[i]] > manp[i][woman[man]])
                        return false;

	}
	return true;
}

void print(int stable[]){

	for(int i=0; i<3; i++)
		cout << "man(" << i << ")" << "=" << "woman(" << stable[i] << ")" << endl;
	cout << endl << endl;
}
