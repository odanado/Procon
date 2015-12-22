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

int n;

//index, x,y
vector<pair<int,P> > vec1;

bool check(int a,int b,int c,int d)
{
	return (c<a<d||c<b<d);
}

int main()
{

	cin>>n;

	int index=1;
	rep(i,n)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a==1)
		{
			vec1.pb(mp(index++,mp(b,c)));
		}
		else
		{
			int x1,x2,y1,y2;
			rep(j,vec1.size())
			{
				if(vec1[j].fr==b)
				{
					x1=vec1[j].sc.fr;
					y1=vec1[j].sc.sc;
				}
				if(vec1[j].fr==c)
				{
					x2=vec1[j].sc.fr;
					y2=vec1[j].sc.sc;
				}
			}

			//printf("[debug]:%d,%d,%d,%d\n",x1,y1,x2,y2);
			rep(j,vec1.size())
			{
				if(vec1[j].fr!=b&&vec1[j].fr!=c)
				{
					//(x1<vec1[j].sc.fr&&vec1[j].sc.fr<x2)||(y1<vec1[j].sc.fr&&vec1[j].sc.sc<y2)
					if(check(vec1[j].sc.fr,vec1[j].sc.sc,x1,y1)&&check(vec1[j].sc.fr,vec1[j].sc.sc,x2,y2))
					{
						printf("YES\n");
						goto go;
					}
				}
			}
			printf("NO\n");

go:;
		}

	}
			




		return 0;
}

