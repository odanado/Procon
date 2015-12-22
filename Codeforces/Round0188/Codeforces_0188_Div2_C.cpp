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

typedef pair<int ,int > P;

typedef pair<Int64,pair<Int64,Int64> > PLL;

Int64 x,y,m;
Int64 ans;

int main()
{
	cin>>x>>y>>m;

	if(x<=0&&y<=0&&x<m&&y<m)
	{
		cout<<"-1"<<endl;
		return 0;
	}


	queue<PLL> que;

	que.push(mp(0,mp(x,y)));

	while(que.size())
	{
		PLL pll=que.front();
		que.pop();

		Int64 _x=pll.sc.fr;
		Int64 _y=pll.sc.sc;

		if(_x>=m || _y>=m)
		{
			cout<<pll.fr<<endl;
			return 0;
		}

		if(-1000000000000000000<=_x+_y&&_x+_y<=100000000000000000)
		{

			que.push(mp(pll.fr+1,mp(_x,_x+_y)));
			que.push(mp(pll.fr+1,mp(_x+_y,_y)));
		
		}
		

	}
		


		return 0;
}

