#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<math.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef pair<int,int> P;

int n;

P data[10010];

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

void solve() {
	rep(i,10010) data[i]=P(0,0);

	rep(i,n-1) {
		int d,n;
		cin>>n>>d;

		data[i+1] = P(data[n].first+dx[d],data[n].second+dy[d]);
	}
	
	int f_min=1000000,f_max=0;
	int s_min=1000000,s_max=0;

	rep(i,n) {
		f_min=min(f_min,data[i].first);
		f_max=max(f_max,data[i].first);
		s_min=min(s_min,data[i].second);
		s_max=max(s_max,data[i].second);
	}

	printf("%d %d\n",f_max-f_min+1,s_max-s_min+1);

}

int main() {

	while (cin>>n)
	{
		if(n==0) return 0;
		solve();
	}

}

/* 2014/05/07 AC */