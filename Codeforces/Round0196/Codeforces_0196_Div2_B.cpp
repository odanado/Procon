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

int a,b,c,d;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

P f(int a,int b)
{
	int c=gcd(a,b);
	while(c!=1)
	{
		//printf("%d,%d,%d\n",a,b,c);
		a/=c;
		b/=c;
		c=gcd(a,b);
	}

	return P(a,b);
}

int main()
{
	cin>>a>>b>>c>>d;


	P ans = f((b*c-a*d),c);
	if(ans.fr<0)
	{
		ans = f(a*d-b*c,d);
		ans = f(ans.fr,a*ans.sc);
		printf("%d/%d\n",(ans.fr),ans.sc);
	}
	else
	{
		ans = f(ans.fr,b*ans.sc);
		printf("%d/%d\n",ans.fr,ans.sc);
	
	}
	
	/*
	P ans = f(abs(b*c-a*d),a*c);

	printf("%d/%d\n",ans.fr,ans.sc);
	//printf("%d,%d\n",b*c-a*d,a*c);
*/
	return 0;
}


