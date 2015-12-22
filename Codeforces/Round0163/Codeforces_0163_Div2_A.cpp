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

int n;
string str;

int main()
{
	int ans=1,temp=1;
	char c;
	cin>>n;
	cin>>str;
	
	c=str[0];
	rep(i,n)
	{
		if(!i) continue;
		if(c==str[i])
		{
			temp++;
		}
		else
		{
			c=str[i];
			ans=max(ans,temp);
		}
	}
	ans=max(ans,temp);

	cout<<ans-1<<endl;

	return 0;
}


