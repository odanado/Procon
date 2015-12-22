#include<stdio.h>
#include<iostream>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int n;
void solve() {
	int sum=0;
	int maxi=-1;
	int mini=1000;
	int a;
	rep(i,n) {
		rep(j,5) {
			cin>>a;
			sum+=a;
		}
		maxi=max(maxi,sum);
		mini=min(mini,sum);
		sum=0;
	}
	cout<<maxi<<" "<<mini<<endl;
}

int main() {

	while (cin>>n)
	{
		if(!n) return 0;
		solve();
			
	}
	return 0;
}

/* 2014/04/16 AC */
