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

string str;

char f(char a,char b)
{
	if(a!='b'&&b!='b') return 'b';
	if(a!='g'&&b!='g') return 'g';
	else return 'r';
}

bool check(string ss)
{
	rep(i,ss.size()-1)
	{
		if(ss[i]!=ss[i+1])
			return false;
	}
	return true;

}

int solve()
{
	//’Ž‚Ìó‘Ô‚Æ‰½Žè–Ú‚©‚ð‚à‚Á‚½bfs
	
	queue<pair<string,int> > que;
	que.push(mp(str,0));
	map<string,int> dist;

	while(que.size())
	{
		pair<string,int> p = que.front();
		if(check(p.fr))
		{
			return p.sc;
					
		}

		que.pop();

		string ss=p.fr;
		if(dist.find(ss)!=dist.end()) continue;

		dist[ss]=p.sc;

		rep(i,ss.size()-1)
		{
			
			if(ss[i]!=ss[i+1])
			{
				char c=f(ss[i],ss[i+1]);
				string tmp=ss;
				tmp[i]=c;
				tmp[i+1]=c;
				que.push(mp(tmp,p.sc+1));
			}

		}

	}

	return -1;

}

int main()
{
	while(cin>>str)
	{
		if(str=="0")
			return 0;
		int a=solve();
		if(a==-1) cout<<"NA"<<endl;
		else cout<<a<<endl;

	}
		return 0;
}

