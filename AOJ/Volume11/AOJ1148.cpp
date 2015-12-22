#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<math.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,m;

//Žž,Šw¶
int data[1300][10003];

void solve() {
	rep(i,1300) rep(j,10003) data[i][j]=0;
	int r;
	cin>>r;
	rep(i,r) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==1) {
			data[a][c]++;
		}
		else {
			data[a][c]--;
		}
	}

	rep(i,m+1) {
		for(int j=1;j<1300;j++) {
			data[j][i]+=data[j-1][i];
		}
	}

	int q;
	cin>>q;
	rep(i,q) {
		int a,b,c;
		cin>>a>>b>>c;
		int ans=0;
		for(int j=a;j<b;j++) {
			if(data[j][c]!=0) {
				ans++;
				//printf("[debug] %d,%d = %d\n",j,c,data[j][c]);
			}
		}
		//cout<<"ans="<<ans<<endl;
		cout<<ans<<endl;
	}

}

int main() {

	while (cin>>n>>m)
	{
		if(n+m==0) {
			return 0;
		}
		solve();
	}

	return 0;
}

/* 2014/05/07 AC */