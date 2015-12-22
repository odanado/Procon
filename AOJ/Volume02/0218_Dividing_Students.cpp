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

void solve(int n)
{
	rep(i,n)
	{
		int a,b,c;
		cin>>a>>b>>c;

		string res="";

		if(a==100||b==100||c==100) res="A";
		else if(90 <= (a+b)/2) res="A";
		else if(80 <= (a+b+c)/3) res="A";
		else if(70 <= (a+b+c)/3) res="B";
		else if(50 <= (a+b+c)/3 &&(80<=a || 80<=b)) res="B";
		else res="C";

		cout<<res<<endl;

	}

}

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0) return 0;
		solve(n);

	}
		return 0;
}


