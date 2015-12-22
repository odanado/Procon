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


int main()
{
	int n;
	while(cin>>n)
	{
		if(!n) return 0;
		rep(i,n)
		{
			int a,b,c,d,e,f,g,h;
			cin>>a>>b>>c>>d>>e>>f>>g>>h;
			cout<<a*e-b*f-c*g-d*h<<" ";
			cout<<a*f+e*b+c*h-g*d<<" ";
			cout<<a*g-b*h+e*c+f*d<<" ";
			cout<<a*h+b*g-c*f+d*e<<endl;
		}
	}
		return 0;
}


