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

int n,m,k;
vector<int> vec;

int main()
{
	cin>>n>>m>>k;
	rep(i,n)
		rep(i,m)
		{
			int a;
			cin>>a;
			vec.pb(a);
		}
	sort(all(vec));
	
	int b=vec[vec.size()/2];
	int ans=0;

	rep(i,vec.size())
	{
		int c=abs(b-vec[i]);
		if(c%k!=0)
		{
			puts("-1");
			return 0;
		}
		ans+=c/k;

	}

	cout<<ans<<endl;

	return 0;
}


