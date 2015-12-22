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

string str;

void solve()
{
	vector<int> vec1,vec2;

	rep(i,10) vec1.pb((str[i]-'0'));
	rep(j,5)
	{
		rep(i,vec1.size()-1)
		{
			vec2.pb((vec1[i]+vec1[i+1])%10);
		}
		vec1.clear();
		rep(i,vec2.size()-1)
		{
			vec1.pb((vec2[i]+vec2[i+1])%10);
		}
		if(j!=4) vec2.clear();
	}
	cout<<vec2[0]<<endl;
}

int main()
{
	while(cin>>str)
	{
		solve();
	}
	return 0;
}


