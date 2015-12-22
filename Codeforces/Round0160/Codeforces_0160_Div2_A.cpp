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

int n,k;
int ans;
bool check(string ss)
{
	int res=0;
	rep(i,ss.size())
	{
		if(ss[i]=='7'||ss[i]=='4')
			res++;
	}
	return res<=k;

}

int main()
{
	cin>>n>>k;
	rep(i,n)
	{
		string ss;
		cin>>ss;
		if(check(ss))
			ans++;
	}
	cout<<ans<<endl;


	return 0;
}


