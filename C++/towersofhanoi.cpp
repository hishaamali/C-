// Hishaam Ali Towers of Hanoi non recursive
#include <iostream>
#include <vector>
using namespace std; 

int main (){
	vector<int> t[3]; // represents three towers as an array of three vector
	int n;
	int candidate;
	int to;
	int from;
	int move=0; 
	cout << "Enter amount of rings:";
	cin >> n;
	
	// initializing all three of the towers
	for (int i=n+1;i>=1;i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);
	
	from=0;
	if ((n%2)==1) to=1;
	else to=2;
	candidate=1;
	while(t[1].size()<n+1){	// while t[1] doesn't contain all rings
		t[to].push_back(t[from].back()); //ring goes from the from to the "to" tower
		t[from].pop_back(); //takes out ring 
	cout << "move #" << ++move << " Transfer ring " << candidate << 
" from tower " << char(from+65) << " to tower " << char(to+65) << endl;
		if (n%2==1){ //if the number of rings is odd
			if (t[(to+1)%3].back() < t[(to+2)%3].back())
				from=(to+1)%3;
			//the smallest ring that was not moved recently
			else 
				from=(to+2)%3;
			if (t[(from)].back() < t[(from+1)%3].back())
				to=(from+1)%3;
			else 
				to=(from+2)%3;
			candidate=(t[from].back()); //candidate is the ring that is on top of the from tower
	       	}
		//even amount of rings
	      	else{ 
			if (t[(to+1)%3].back() < t[(to+2)%3].back())
				from=(to+1)%3;
			else 
				from=(to+2)%3;
			if (t[(from)].back() < t[(from+2)%3].back())
				to=(from+2)%3;
			else
				to=(from+1)%3;
	
			candidate=(t[from].back()); // candidate is the ring on top of from tower
		}
	}
	return 0;
}			
