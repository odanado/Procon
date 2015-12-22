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

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;


int P=4;
int Q=15;
int R=50;
int C=400;

bool check(int p,int q,int r,int c)
{
	return (P>=p && Q>=q && R>=r && C>=c);
}

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> p,q,r,i;
		bool f=true;
		if(!n) return 0;
		rep(j,n)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			i.pb(a);
			p.pb(b);
			q.pb(c);
			r.pb(d);
		}
		cin>>P>>Q>>R>>C;
		rep(j,n)
		{
			if(check(p[j],q[j],r[j],p[j]*4+q[j]*9+r[j]*4))
			{
				f=false;
				cout<<i[j]<<endl;
			}
		}
		if(f) cout<<"NA"<<endl;
	}
		return 0;
}


