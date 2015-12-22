#include<stdio.h>
#include<iostream>
#include<algorithm>


#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int x,y;
int c[20][20];
int dp[20][20];

void solve() {
	rep(i,20) rep(j,20) c[i][j]=1;
	rep(i,20) rep(j,20) dp[i][j]=0;

	rep(i,y) rep(j,x) cin>>c[i][j];

	rep(i,x) if(c[0][i]!=1) dp[0][i]=1;
	
	for(int i=0;i<y;i++) {
		for(int j=0;j<x;j++) {
			if(c[i][j]==2) {
				dp[i+2][j] += dp[i][j];
			}
			else if(c[i][j]==0) {
				if(c[i+1][j]!=1) {
					dp[i+1][j] += dp[i][j];
				}
				if(0<=j-1 && c[i+1][j-1]==0) {
					dp[i+1][j-1] += dp[i][j];
				}
				if(j+1 < x && c[i+1][j+1]==0) {
					dp[i+1][j+1] += dp[i][j];
				}
			}
		}
	}


	int ans=0;
	rep(i,x) if(c[y-1][i]!=1) ans+=dp[y-1][i];
	rep(i,x) ans+=dp[y][i];

	cout<<ans<<endl;

}

int main() {
	while(cin>>x>>y) {
		if(x+y==0) return 0;
		solve();
	}
	return 0;
}

/* 2014/04/23 AC */