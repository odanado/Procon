#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
 
 
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
const int INF = 100000000;
const double EPS = 0.0000001;
typedef pair<int,int> P;

int n;
//           999999
bool isPrime[1000003];

void solve() {
	int ans=0;
	rep(i,n+1) if(isPrime[i]) ans++;
	cout<<ans<<endl;
}

void init() {
	rep(i,1000003) isPrime[i]=true;
	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<1000003;i++) {
		if(isPrime[i]) {
			for(int j=i+i;j<1000003;j+=i) isPrime[j]=false;
		}
	}


}

int main() {
	init();
	while (cin>>n)
	{
		if(n==0) return 0;
		solve();

	}
}

/* 2014/04/30 AC */