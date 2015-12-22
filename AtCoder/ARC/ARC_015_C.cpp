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
#define rep(i,n) for(long long i=0;i<(n);i++)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const long long INF=100000000;
long long dx[4]={1,0,-1,0};
long long dy[4]={0,1,0,-1};

using namespace std;

typedef pair<long long ,long long > P;

vector<P> G[207];

map<string,long long> mstr;
//map<long long,string> small,laege;
map<long long,string> mstr2;

long long a,b;
long long n;

long long ans;
long long ans1,ans2;

void dfs(long long s,long long v,long long m)
{
	//prlong longf("[debug]:%d\n",v);
	if(ans<m)
	{
		ans=m;
		ans1=s;
		ans2=v;
	}
	
	rep(i,G[v].size())
	{
		P e = G[v][i];
		dfs(s,e.fr,e.sc * m);
	}
}

int main()
{
	
	long long cnt=0;
	cin>>n;
	rep(i,n)
	{
		long long m;
		string str1,str2;

		cin>>str1>>m>>str2;

		if(mstr.find(str1)==mstr.end())
		{
			mstr2[cnt]=str1;
			mstr[str1]=cnt++;
		}
		if(mstr.find(str2)==mstr.end())
		{
			mstr2[cnt]=str2;
			mstr[str2]=cnt++;
		}
		G[mstr[str1]].pb(P(mstr[str2],m));

	}
	
	rep(i,cnt)
	{
		dfs(i,i,1);
	}

	cout<<"1"<<mstr2[ans1]<<"="<<ans<<mstr2[ans2]<<endl;

	return 0;
}
