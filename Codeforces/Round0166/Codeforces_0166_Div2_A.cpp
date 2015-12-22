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

bool check(int n)
{
	ostringstream os;
	os<<n;
	string s=os.str();

	if(s[0]!=s[1]&&s[0]!=s[2]&&s[0]!=s[3])
	{
		if(s[1]!=s[2]&&s[1]!=s[3])
		{
			if(s[2]!=s[3])
				return true;
		}
	}


	return false;

}

int main()
{
	
	int y;
	cin>>y;
	y++;
	while(true)
	{
		if(check(y))
		{
			cout<<y<<endl;
			return 0;
		}
		y++;

	}


	return 0;
}


