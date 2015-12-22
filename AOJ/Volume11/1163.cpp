#include<stdio.h>
#include<iostream>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int n,m;
int b[507];
int r[507];

int gcd(int a,int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve() {
	int ans=0;
	int x[507],y[507];
	rep(i,m) cin>>b[i];
	rep(i,n) cin>>r[i];
	
	rep(i,m) {
		int cnt=0;
		rep(j,n) {
			if(gcd(b[i],r[j])!=1) {
				//printf("[debug] %d,%d,%d\n",b[i],r[j],gcd(b[i],r[j]));
				cnt++;
			}
		}
		x[i]=cnt;
		ans=max(ans,cnt);
		
	}
	
	rep(i,n) {
		int cnt=0;
		rep(j,m) {
			if(gcd(b[j],r[i])!=1) {
				cnt++;
			}
		}
		y[i]=cnt;
		ans=max(ans,cnt);
	}
	/*
	rep(i,m) cout<<x[i]<<" ";
	cout<<endl;
	rep(i,n) cout<<y[i]<<" ";
	cout<<endl;
	*/
	cout<<ans<<endl;


	

}

int main() {
	while(cin>>m>>n) {
		if(m+n==0) return 0;
		solve();
	}


	return 0;
}