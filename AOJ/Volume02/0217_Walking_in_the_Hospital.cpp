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

void solve(int n)
{
	vector<P> vec;
	rep(i,n)
	{
		int p,d1,d2;
		cin>>p>>d1>>d2;
		vec.pb(P(d1+d2,p));
	}

	sort(all(vec),greater<P>());

	vector<P>::iterator it = vec.begin();

	cout<<it->sc<<" "<<it->fr<<endl;

}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) return 0;

		solve(n);
	}
		return 0;
}


