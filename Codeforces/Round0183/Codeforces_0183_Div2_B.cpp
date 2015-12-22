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
Int64 getDays(int y, int m, int d)
{
	//“ú•tŒo‰ß
	if(m <= 2){
		--y;
		m += 12;
	}
	Int64 dy = 365 * (y - 1);
	Int64 c = y / 100;
	Int64 dl = (y >> 2) - c + (c >> 2);
	Int64 dm = (m * 979 - 1033) >> 5;
	return dy + dl + dm + d - 1;
}

int main()
{
	int a,b,c;
	Int64 ans=0;

	scanf("%d:%d:%d",&a,&b,&c);
	ans=getDays(a,b,c);
	scanf("%d:%d:%d",&a,&b,&c);

	ans=getDays(a,b,c)-ans;

	cout<<abs(ans)<<endl;

	


	return 0;
}


