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

int p;

int gcd(int m,int n)
{
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}

int main()
{
	cin>>p;
	int ans=0;
	rep(i,p)
	{
		if(!i) continue;
int a=gcd(i,p-1);
		//printf("[debug]:%d,%d,%d\n",i,p-1,a);
		
		if(a==1)
			ans++;
	}
	cout<<ans<<endl;


	return 0;
}


