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

int MAX_N=1000007;
bool prime[1000007];

int main()
{
	fill(prime,prime+MAX_N,true);

	prime[0]=prime[1]=false;
	for(int i=2;i<MAX_N;i++)
	{
		if(prime[i])
		{
			for(int j=i*2;j<MAX_N;j+=i) prime[j]=false;
		}
	}

	int n;
	while(cin>>n)
	{
		int ans=0;
		rep(i,n+1)
			if(prime[i])
				ans++;
		cout<<ans<<endl;
	}
	


	return 0;
}


