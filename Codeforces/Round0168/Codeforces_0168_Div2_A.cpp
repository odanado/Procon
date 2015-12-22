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

int a[3][3]={ {1,1,1},{1,1,1},{1,1,1}};

int main()
{
	int n;

	rep(i,3)
	{
		rep(j,3)
		{
			cin>>n;
			rep(k,n)
			{
				a[i][j]^=1;
				rep(l,4)
				{
					int nx=i+dx[l];
					int ny=j+dy[l];
					if(!(0<=nx&&nx<3)) continue;
					if(!(0<=ny&&ny<3)) continue;

					a[nx][ny]^=1;
				}
			}
		}
	}
	rep(i,3)
	{
		rep(j,3)
			cout<<a[i][j];
		cout<<endl;
	}



	return 0;
}


