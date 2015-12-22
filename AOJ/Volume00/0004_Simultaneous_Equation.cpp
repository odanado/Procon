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

double a,b,c,d,e,f;


int main()
{

	while(cin>>a>>b>>c>>d>>e>>f)
	{
		double y=(f*a-d*c)/(a*e-b*d);

		double x=(c-b*y)/a;
		/*
		if(x==0.0)
			x=0.0;
		if(y==0.0)
			y=0.0;
			*/
		printf("%.3lf %.3lf\n",x,y);

	}
	


	return 0;
}


