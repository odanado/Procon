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

int n,m,p;


int calc0(int A,int C,double D,int Y) {
	int B;
	int sumB=0;
	rep(i,Y) {
		B = A*D;
		sumB += B;
		A-=C;
	}

	return sumB+A;
}

int calc1(int A,int C,double D,int Y) {
	int B;
	rep(i,Y) {
		B=A*D;
		A=A+B-C;
	}
	return A;
}
void solve() {
	//‰Šú‚Ì‚¨‹à
	int s;cin>>s;
	//”N”,‚µ‚ã‚é‚¢
	cin>>m>>p;
	
	int maxi = 0;

	rep(i,p) {
		int a,c;
		double b;
		cin>>a>>b>>c;

		rep(i,m) {
			//’P—˜
			if(a==0) {
				maxi=max(maxi,calc0(s,c,b,m));
			}
			else {
				
				maxi=max(maxi,calc1(s,c,b,m));
			}
		}
	}

	cout<<maxi<<endl;
}

int main() {

	cin>>n;
	rep(i,n) solve();

	return 0;
}

/* 2014/04/30 AC */
