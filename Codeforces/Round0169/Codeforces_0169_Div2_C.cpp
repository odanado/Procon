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

int n,q;
int a[200007];
int b[200007];

int main()
{
	cin>>n>>q;
	rep(i,n) cin>>a[i];
	rep(i,q)
	{
		int l,r;
		cin>>l>>r;
		l--;
		b[l]++;
		b[r]--;
	}
	rep(i,n)
	{
		b[i+1]+=b[i];
	}
	
	sort(a,a+n);
	sort(b,b+n);
	ll ans=0;
	rep(i,n) ans+=(ll)((ll)a[i]*(ll)b[i]);
	cout<<ans<<endl;


	return 0;
}


