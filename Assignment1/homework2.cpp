#include <iostream>
using namespace std;

bool equivalent (int a[],int b[],int n){

	bool check = true;
	for(int i=0;i<n;i++){
		for (int j=n; j>0;j--){
			if(a[i] != b[(i+j)%n]){
				check = false;
			}
		}	
	}
	return check;
}

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {3, 4, 5, 1, 2};
	string result;
	
	if(equivalent(a, b, 5) == true){
		result = "";
	}
	else
		result = "not ";
		
	cout << "Array a and b are " << result << "equivalent!";
	
return 0;
}
