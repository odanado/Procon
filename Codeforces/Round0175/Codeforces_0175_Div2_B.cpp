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

int n,s,t;
int a[100007];
int ans=0;
int main()
{
	
	cin>>n>>s>>t;

	rep(i,n+1)
	{
		if(!i) continue;
		cin>>a[i];
	}
	
	if(s==t)
	{
		cout<<"0"<<endl;
		return 0;
	}

	rep(i,1000000)
	{
		s=a[s];
		if(s==t)
		{
			cout<<i+1<<endl;
			return 0;
		}

	}

	puts("-1");

	return 0;
}


