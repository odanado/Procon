#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<stack>
#include<functional>
#include<sstream>
#include<iomanip>
#include<set>
#include<bitset>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<n;i++)
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

int n,m;
vector<int> vec;
int a[107];

bool f()
{
	//if(vec[0]-vec[1]!=vec[n-2]-vec[n-1]) return false;

	//printf("%d,%d,%d,%d\n",vec[0],vec[1],vec[n-2],vec[n-1]);
	for(int i=1;i<n-1;i++)
	{
		//printf("%d,%d,%d\n",vec[i-1],vec[i],vec[i+1]);
		if(vec[i-1]-vec[i]!=vec[i]-vec[i+1])
		{
			return false;
		}
	}
	return true;
}

int solve()
{
	rep(i,m)
	{
		vec.clear();
		rep(j,m)
		{
			if(i==j) continue;
			vec.pb(a[j]);
		}
		//printf("%d?\n",a[i]);
		if(f())
		{
			cout<<a[i]<<endl;
			return 0;
		}
	}
}

int main()
{
	while(true)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		if(!n) return 0;
		m=n+1;
		rep(i,m)
			cin>>a[i];
		solve();
	}

	


	return 0;
}


