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

int ans;
string str;
void solve()
{
	string str1,str2;
	int n=str.size();
	
	str1=str.substr(0,n/2);
	str2=str.substr(n/2+n%2,n);
	reverse(all(str2));
	if(str1==str2) ans++;
	return;
}
int main()
{
	while(cin>>str)
	{
		//if(str=="!") break;
		solve();

	}
	

	cout<<ans<<endl;

	return 0;
}


