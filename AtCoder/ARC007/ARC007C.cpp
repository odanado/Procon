#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<string>
 
 
#define rep(i,n) for(int i=0;i<(n);i++)
 
using namespace std;
const int INF = 100000000;
const double EPS = 0.0000001;
typedef pair<int,int> P;

string ss;
unsigned int mask;
unsigned int m;

int dfs(unsigned int n) {
	if(mask == n) return 1;

	int res = INF;

	rep(i,ss.size()) {
		if(n == ((n | (m<<i))&mask)) continue;
		res = min(res,dfs(((n | (m<<i))&mask))+1);

	}
	return res;
}

int main() {
	cin>>ss;

	mask = (1<<ss.size())-1;

	unsigned int n=0;
	rep(i,ss.size()) {
		if(ss[i]=='o') {
			n |= (1<<i);
		}
	}
	m=n;
	cout<<dfs(n)<<endl;


	return 0;
}