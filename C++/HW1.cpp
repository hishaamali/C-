// Hishaam Ali // HW#1: 8 Queens 1D no goto //Lab

#include <iostream>
#include <cmath>
using namespace std;

bool check(int q[], int c){
	for (int i=0; i<c; i++)
		if ((q[i] == q[c]) || (abs(q[c]-q[i]) == (c-i)))
			return false;
	return true; }

void print (int q[], int count){
	cout << "Solution # " << count << endl;
	for (int i=0; i<8; i++)
		cout << q[i] << " ";
	cout << endl << endl;
}
void backtrack(int &c){
	c--;
}

int main (){
        int q[8], c=0;
	q[0]=0;
        int count=0;
        bool from_backtrack=false;
        while (true){
                while (c<8){
			if(c==-1) return 0;
                        if (!from_backtrack){
				c++;
				if (c==8) break;
				q[c]=-1;
                        }
                         from_backtrack = false;
                         while (q[c] < 8){
                                 q[c]++;
				 if(q[c]==8){
			        	 backtrack(c);
					 from_backtrack=true;
					 break;
                                 }
				 if (check(q,c)) break;
			 } 
		}
                count ++;
                print (q,count);
		backtrack(c);
                from_backtrack=true;
        }
        
}
