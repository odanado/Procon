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

int a,d,n;
bool isPrime[1000003];

void init() {
	rep(i,1000003) isPrime[i]=true;
	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<1000003;i++) {
		if(isPrime[i]) {
			for(int j=i+i;j<1000003;j+=i) isPrime[j]=false;
		}
	}


}
void solve() {
	int cnt=0;
	while (true)
	{
		if(isPrime[a]) cnt++;
		if(cnt==n) break;
		a+=d;
	}
	
	cout<<a<<endl;
}

int main() {
	init();
	while (cin>>a>>d>>n)
	{
		if(a+d+n==0) return 0;
		solve();
	}
	return 0;
}

/* 2014/04/30 AC */