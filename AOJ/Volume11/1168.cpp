#include<stdio.h>
#include<iostream>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int w,h;

char p[61][11];
const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


void dfs(int x,int y,int& mini,int& maxi,char c) {
	p[x][y]='.';
	rep(i,4) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<=nx&&nx<w && 0<=ny&&ny<h && p[nx][ny]==c) {
			mini = min(mini,nx);
			maxi = max(maxi,nx);
			cout<<p[nx][ny]<<","<<nx<<","<<ny<<endl;
			dfs(x,y,mini,maxi,c);
		}

	}
	//p[x][y]=c;
}

void solve() {
	rep(i,61) rep(j,11) p[i][j]='.';
	rep(i,w) rep(j,h) cin>>p[i][j];

	double g = 0.0;

	rep(i,w) rep(j,h) {
		if(p[i][j]!='.') {
			int mini=10000,maxi=-10000;
			dfs(i,j,mini,maxi,p[i][j]);
			cout<<mini<<" "<<maxi<<endl;
			g = (1.0*(maxi-mini)/2.0 + g)/2.0;
		}
	}
	cout<<g<<endl;
}

int main() {
	while (cin>>h>>w)
	{
		if(w+h==0) return 0;

		solve();

	}

	return 0;
}