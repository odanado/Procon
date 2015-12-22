#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>


#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef pair<int,int> P;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int w,h;
int map[501][501];
bool flag[501][501][3];

int main() {
	cin>>w>>h;

	P s,g;
	rep(i,501) rep(j,501) rep(k,3) flag[i][j][k]=false;

	rep(i,w) rep(j,h) {
		char c;
		cin>>c;
		map[i][j]=c;
		if(c=='s') {
			s.first=i;
			s.second=j;
		}
		if(c=='g') {
			g.first=i;
			g.second=j;
		}
	}

	queue<pair<P,int> > que;
	que.push(make_pair(s,0));

	while(que.size()) {
		pair<P,int> p = que.front(); que.pop();
		int x=p.first.first;
		int y=p.first.second;
		int cnt=p.second;
		if(flag[x][y][cnt]) continue;
		flag[x][y][cnt] = true;

		rep(i,4) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!(0<=nx&&nx<w && 0<=ny&&ny<h)) continue;
			if(map[nx][ny]=='#') {
				if(cnt==2) continue;

				que.push(make_pair(P(nx,ny),cnt+1));

			}
			else {

				que.push(make_pair(P(nx,ny),cnt));


			}
			if(map[nx][ny]=='g') {
				cout<<"YES"<<endl;
				return 0;
			}

		}
	}

	cout<<"NO"<<endl;
	

	return 0;
}

/* 2014/04/16 AC */