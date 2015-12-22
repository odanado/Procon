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
#include<climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)


typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n,s;
int ans;

void dfs(set<int> S,int sum,int cnt,int a)
{
	if(sum==s&&cnt==n+1)
	{
		ans++;
		cout<<sum<<" :";
		FOR(it,S) cout<<*it<<" ";
		cout<<endl;
		return;
	}
	if(n+1==cnt) return;
	S.insert(a);

	rep(i,10)
	{
		if(S.find(i)==S.end())
		{
			dfs(S,sum+i,cnt+1,i);
			
		}

	}


}

void solve()
{
	set<int> S;
	ans=0;

	dfs(S,0,0,-1);
	cout<<ans<<endl;


}

int main()
{
	while(cin>>n>>s)
	{
		if(n==0&&s==0)
			return 0;
		solve();

	}
	
		return 0;
}


