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

string str;

int dfs(int i)
{
	if(i==str.size()) return 0;

	if(str[i]=='r')
	{
		cout<<i+1<<endl;
		dfs(i+1);
	}
	else
	{
		dfs(i+1);
		cout<<i+1<<endl;
	}
}

int main()
{
	cin>>str;

	dfs(0);


	return 0;
}


