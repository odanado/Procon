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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
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

int a,b,c,d,e,f;

int main()
{
	int n;
	double mi,ma;
	cin>>n;
	rep(i,n)
	{
		cin>>ma>>mi;
		if(35.0<=ma) a++;
		if(30.0<=ma&&ma<35.0) b++;
		if(25.0<=ma&&ma<30.0) c++;
		if(25.0<=mi) d++;
		if(mi<0.0&&0.0<=ma) e++;
		if(ma<0.0) f++;
	}

	printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
		return 0;
}


