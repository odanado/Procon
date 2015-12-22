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

int n;
ll b[100007];
ll f(int x)
{
	ll res=0;
	if(!x) return 0;
	if(x%2==0)
	{
		res+=f(x/2);
	}
	else
	{
		res+=f(x/2)+1;
	}
	return res;

}
ll ma=-1;
int main()
{

	cin>>n;
	rep(i,n)
	{
		int a;
		cin>>a;
		b[f(a)]++;
		ma=max(ma,f(a));
	}
	ll ans=0;
	rep(i,ma+1)
		ans+=(ll)((b[i]*(b[i]-1))/2);
	cout<<ans<<endl;

	return 0;
}


