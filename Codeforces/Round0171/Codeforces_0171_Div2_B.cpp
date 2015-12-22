#include<algorithm>
#include<functional>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long ull;
typedef long long ll;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n,t;
int a[100007];
int b[100007];
int main()
{
	cin>>n>>t;
	rep(i,n+1)
	{
		if(!i) continue;
		cin>>a[i];
	}

	b[1]=a[1];
	rep(i,n+1)
	{
		if(!i||i==1) continue;
		b[i]=b[i-1]+a[i];
		
	}

	//rep(i,n+1) cout<<b[i]<<endl;
	int ans=0;
	rep(i,n+1)
	{
		if(!i) continue;
		int c=upper_bound(b+i,b+1+n,t+b[i-1])-b-i;
		//cout<<c<<endl;
		ans=max(ans,c);

	}
	cout<<ans<<endl;


	return 0;
}
//http://www.codeforces.com/contest/279/problem/B

