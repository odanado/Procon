#include<stdio.h>
#include<iostream>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int map[51][51];
int w,h;

void dfs(int x,int y) {
	map[x][y]=0;
	for(int i=-1;i<=1;i++) {
		for(int j=-1;j<=1;j++) {
			int nx = x+i;
			int ny = y+j;
			if(0<=nx&&nx<w && 0<=ny&&ny<h && map[nx][ny]==1)
				dfs(nx,ny);
		}
	}


}

void solve() {
	rep(i,51) rep(j,51) map[i][j]=0;

	rep(i,w) rep(j,h) cin>>map[i][j];

	int ans=0;
	rep(i,w) rep(j,h) {
		if(map[i][j]==1) {
			dfs(i,j);
			ans++;
		}
	}
	cout<<ans<<endl;
}

int main() {

	while (cin>>h>>w)
	{
		if(h+w==0) return 0;
		solve();

	}

	return 0;
}

/* 2014/04/16 AC */