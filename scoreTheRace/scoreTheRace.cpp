#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(){
	string r, teams, winner;
	int count = 0;
	double n = 0;
	double minScore = 100;
	char c;
	string valid(string race);
 
	cout << "Enter a string indicating the outcome of a race: ";
    cin >> r;  
	if(r == "DONE") return 0;
	cout << r << endl;

	teams = valid(r);
	cout << "There are " << teams.length() << " teams." << endl << endl;
	cout << "Each team has " << r.length()/teams.length() << " runners." << endl;
	
	for(int i=0;i<teams.length(); i++){
		count=0;
		n=0;
		for(int j=0; j<r.length(); j++){
			if(teams[i] == r[j]){
				count++;
				n=n+(j+1);
			}
		}
		n=n/count;
		c = teams[i];
		if(n < minScore){
			minScore = n;
			winner = c;
		}
		cout << c << ": " << n << endl;
	}

	cout << "The winning team is " << winner << ", scoring: " << minScore << endl;

return 0;
}


string valid(string race){
	string a = "";
	for(int i = 0; i<race.size(); i++){
		if(a.find(race[i]) == string::npos)
			a = a + race[i];
	}
	return a;
}
