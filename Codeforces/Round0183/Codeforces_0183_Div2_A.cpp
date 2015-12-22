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
#include<climits>
#include<ctime>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

typedef unsigned long long UInt64;
typedef long long Int64;

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

using namespace std;

typedef pair<int ,int > P;

int n;

int main()
{
	cin>>n;
	int ans=0;

	clock_t a,b;
	a=clock();
	for(int a=1;a<=n;a++)
		for(int b=a;b<=n;b++)
			for(int c=b;c<=n;c++)
			{
				if(c*c==(a*a+b*b))
					ans++;

			}
	b=clock();
	cout<<ans<<endl;
	printf("%llf\n",CLOCKS_PER_SEC);


	return 0;
}


