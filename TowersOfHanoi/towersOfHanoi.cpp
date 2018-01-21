#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> t[3];
	int n, candidate, to, from, move = 0;
	cout << "Please enter the number of rings to move: ";
	cin >> n;
	cout << endl;
 
 	for(int i=n+1; i>=1; i--)
 		t[0].push_back(i);
 		t[1].push_back(n+1);
		t[2].push_back(n+1);
 
	from = 0;
 	to = 1;
	candidate = 1;

	while(t[1].size() < n+1){

		cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;

		//1. Push the top of the from tower to the to tower
		t[to].push_back(t[from].back());
		//2. Remove the ring from the from tower
 		t[from].pop_back();

		//Get next from tower.
		if(t[(to+1)%3].back() < t[(to+2)%3].back())
			from = (to+1)%3;
		else
			from = (to+2)%3;

		// get next to tower
		if(t[from].back() < t[(from+1)%3].back())
			to = (from+1)%3;
		else
			to = (from+2)%3;

		//get next candidate
		candidate = t[from].back(); 
    }
return 0;
}
