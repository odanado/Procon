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

int f(int w)
{
	int res=1150;
	
	if(w<10) return res;
	if(w<20) return (res+(w%10)*125);
	if(w<30) return (res+1250+(w%10)*140);
	if(w<40) return (res+1250+1400+(w%10)*160);
	else return (res+1250+1400+1600+(w-40)*160);

}

int main()
{
	int w;
	while(cin>>w)
	{
		if(w==-1) return 0;
		cout<<4280-f(w)<<endl;
	}
		return 0;
}


