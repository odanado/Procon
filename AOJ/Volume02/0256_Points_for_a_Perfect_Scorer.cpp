#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<list>
#include<stack>
#include<functional>
#include<sstream>
#include<iomanip>
#include<set>
#include<bitset>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<n;i++)
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


int main()
{
	int ans=0;
	rep(i,10)
	{
		int a;
		cin>>a;
		ans+=a;
	}
	cout<<ans<<endl;


	return 0;
}


