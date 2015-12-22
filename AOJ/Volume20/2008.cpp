#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
const int INF=100000000;


int n;
int hx,hy;
int dx,dy;
int cx[21],cy[21];


double dist(int _x0,int _y0,int _x1,int _y1) {
	double d = (_x0-_x1)*(_x0-_x1) + (_y0-_y1)*(_y0-_y1);
    //printf("[dist debug] %d %d %d %d %d\n",_x0,_y0,_x1,_y1,(int)(d));
	return sqrt(d);
}

int pow2(int a) {
	return a*a;
}

bool check(int x,int y,double d,int ind) {
    return dist(x,y,cx[ind],cy[ind]) < (dist(dx,dy,cx[ind],cy[ind]) - d);
}

bool dfs(int x,int y,double d,int S) {
    printf("[debug] %d,%d,%lf,%d\n",x,y,d,S);
	if(S==(1<<n)-1) return true;
	rep(i,n) {
		if(!((S>>i)&1)) {
			if(check(x,y,d,i)) {
				return dfs(cx[i],cy[i],d+(dist(x,y,cx[i],cy[i])),S|(1<<i));
			}
		}
	}

	return false;

}


void solve() {
	rep(i,n) cin>>cx[i]>>cy[i];
	if(dfs(hx,hy,0.0,0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}

int main() {
	while (cin>>n>>hx>>hy>>dx>>dy)
	{
		if(n+hx+hy+dx+dy==0) return 0;
		solve();
	}

	return 0;
}
