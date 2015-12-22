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

string sei(int n)
{
	string res="";
	rep(i,8)
	{
		if(n%2==0)
		{
			res+="0";
		}
		else
		{
			res+="1";
		}
		n/=2;
	}

	reverse(all(res));
	return res;
}

string syo(double d)
{
	string res="";
	rep(i,4)
	{
		d*=2;
		if((int)d==1)
		{
			res+="1";
			d-=1.0;
		}
		else
		{
			res+="0";
		}

	}
	if(d!=0.0) return "-1";

	return res;
}

int main()
{
	double d;
	while(cin>>d)
	{
		if(d==-1.0) return 0;
		
		string ans = sei((int)d)+"."+syo(d - (int)d );
		if(ans.size()==13) cout<<ans<<endl;
		else cout<<"NA"<<endl;
		//cout<<ans<<endl;

	}
		return 0;
}


