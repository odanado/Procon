include<algorithm>
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

bool flag;

bool check(queue<int> que)
{
	int prev=que.front();
	que.pop();
	int n=que.size();
	rep(i,n)
	{
		if(prev>que.front())
			return false;
		prev=que.front();
		que.pop();
	}
	return true;
}

void dfs(queue<int> a,queue<int> b,queue<int> c)
{
	if(a.empty())
	{
		if(check(b)&&check(c))
			flag=true;		
		else
			return;
	}

	if(b.front()<a.front())
	{
		b.push(a.front());
		a.pop();
	}
	

}

void solve(queue<int> a)
{

	queue<int> b,c;
	b.push(-1);
	c.push(-1);

	dfs(a,b,c);

}

int main()
{
	int n;
	cin>>n;

	rep(i,n)
	{
		queue<int> a;
		int m;

		rep(i,10)
		{
			cin>>m;
			a.push(m);
		}

	}
		return 0;
}

