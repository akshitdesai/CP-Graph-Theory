/* Author :- codestromer */



// C++ program to count minimum number of steps
// required to measure d litres water using jugs
// of m litres and n litres capacity.
#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

//using Diophantine Equation  mx+ny=d
//where we have jug of m & n liters
//and we have to measure d liter water
int gcd(int a, int b){
	if (b==0)
	return a;
	return gcd(b, a%b);
}
int pour(int fromCap, int toCap, int d){
	int from = fromCap,to = 0,step = 1;
	while (from != d && to != d){
		int temp = min(from, toCap-to);
		to += temp;
		from -= temp;
		step++;
		if (from == d || to == d)
			break;
		if (from == 0){
			from = fromCap;
			step++;
		}
		if (to == toCap){
			to = 0,step++;
		}
	}
	return step;
}
int minSteps(int m, int n, int d){
	if (m > n)  swap(m, n);
	if (d > n)  return -1;
	if ((d % gcd(n,m)) != 0)    return -1;
	return min(pour(n,m,d),pour(m,n,d));
}

int main(){
    int t,n,m,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>d;
        cout<<minSteps(m,n,d)<<'\n';
    }
	return 0;
}
