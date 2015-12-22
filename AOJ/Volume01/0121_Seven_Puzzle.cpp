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

typedef pair<int,int> P;

//àÍíiÇµÇΩÇÕ+4

int main()
{
	map<string,int> dist;

	int DX[]={1,-1,4,-4};
	//èÛë‘Ç∆0ÇÃà íu
	queue<pair<string,int> > que;
	que.push(mp("01234567",0));
	dist["01234567"]=0;

	while(que.size())
	{
		pair<string,int> p=que.front();
		que.pop();

		rep(i,4)
		{
			int nx=p.sc+DX[i];
			string nextstr=p.fr;
			if(p.sc%4==0&&i==1) continue;
			if(p.sc%4==3&&i==0) continue;
			if(0<=nx&&nx<8)
			{
				swap(nextstr[nx],nextstr[p.sc]);
				if(dist.find(nextstr)==dist.end())
				{
					que.push(mp(nextstr,nx));
					dist[nextstr]=dist[p.fr]+1;
				}
			}
		}
	}

	string str;
	while(getline(cin,str))
	{
		stringstream ss(str);

		string str2,str3;

		while(ss>>str2)
			str3+=str2;
		cout<<dist[str3]<<endl;

	}

		return 0;
}

