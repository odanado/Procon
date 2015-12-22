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


const int MAX_N=2000000;


//[1,n]‚Ì•Â‹æŠÔ
int bit[MAX_N+1],n;
int a[MAX_N+1];

int sum(int i)
{
	int s=0;
	while (i>0)
	{
		s+=bit[i];
		i-=i & -i;
	}
	return s;
}

void add(int i,int x)
{
	while (i<=n)
	{
		bit[i]+=x;
		i+=i & -i;
	}

}

int c=1;
int main()
{
	cin>>n;
	add(1,0);
	rep(i,n)
	{
		rep(i,n) cout<<bit[i]<<endl;
		int t;
		cin>>t;
		if(t==1)
		{
			int a,b;
			cin>>a>>b;
			for(int i=1;i<=a;i++)
				add(i,b);
		}
		if(t==2)
		{
			int a;
			cin>>a;
			c++;
			add(c,a);
		}
		if(t==3)
		{
			c--;
		}
		int s=sum(c);
		double ans=(double)s/(double)c;
		printf("%.8lf\n",ans);
	}
		return 0;
}
