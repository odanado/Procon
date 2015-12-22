#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<math.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int p;
bool isPrime[300003];

bool isMSPrime(int n) {
	if(!(n%7==1 || n%7==6)) return false;

	for(int i=2;i*i<=n;i++) {
		if(!(i%7==1 || i%7==6)) continue;
		if(n%i==0) return false;
	}
	return true;
}
void init() {
	fill(isPrime,isPrime+300003,true);
	/*
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<300003;i++) {
		if(isPrime[i]) for(int j=i+i;j<300003;j+=i) isPrime[j]=false;
	}
	*/
	rep(i,300003) isPrime[i]=isMSPrime(i);
}


void solve() {
	printf("%d:",p);
	bool flag[300003];
	fill(flag,flag+300003,false);

	for (int i = 2; i < 300003; i++)
	{
		if(!isPrime[i]) continue;
		if (p%i==0)
		{
			flag[i]=true;
		}
	}

	rep(i,300003) if(flag[i]) printf(" %d",i);
	puts("");

}

int main() {
	init();
	while (cin>>p)
	{
		if(p==1) return 0;
		solve();
	}



	return 0;
}