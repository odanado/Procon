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

int m;
int c[107];
int x,y;


int main()
{
	int sum=0;
	cin>>m;
	rep(i,m) cin>>c[i];
	cin>>x>>y;

	rep(i,m) sum+=c[i];

	int s=0;
	rep(i,m)
	{
		s+=c[i];
		//cout<<s<<","<<sum<<endl;
		if(x<=s&&s<=y && x<=sum-s&&sum-s<=y)
		{
			cout<<i+2<<endl;
			//cout<<((i+1)*(i+2))/2<<endl;
			return 0;
		}
	}
	cout<<"0"<<endl;

		return 0;
}


