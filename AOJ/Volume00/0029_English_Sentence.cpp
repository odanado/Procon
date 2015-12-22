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

map<string,int> mp;
string ans,ans2;
int ma=0;

int main()
{
	string str;
	while(cin>>str)
	{
		//if(str=="!") break;
		if(ma<str.size())
		{
			ma=str.size();
			ans=str;
		}
		mp[str]++;
	}
	ma=0;
	map<string,int>::iterator it=mp.begin();
	while(it!=mp.end())
	{
		if(ma<it->sc)
		{
			ma=it->sc;
			ans2=it->fr;
		}
		++it;
	}

	cout<<ans2<<" "<<ans<<endl;
	


	return 0;
}


