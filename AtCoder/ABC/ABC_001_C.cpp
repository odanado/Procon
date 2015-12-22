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
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
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

double deg,dis;
string dir;
string W;
int main()
{
	cin>>deg>>dis;
	deg/=10.0;

	if(0.0<=deg&&deg<78.75)
	{
		string tmp="N";

		if(11.25<=deg)
		{
			tmp+="E";
			
			if(11.25<=deg&&deg<33.75)
				dir="N"+tmp;
			else if(33.75<=deg&&deg<56.25)
				dir=tmp;
			else
				dir="E"+tmp;
		}
		else
			dir=tmp;
	}
			
	else if(78.75<=deg&&deg<168.75)
	{
		string tmp="E";

		if(101.25<=deg)
		{
			tmp="S"+tmp;
			
			if(101.25<=deg&&deg<123.75)
				dir="E"+tmp;
			else if(123.75<=deg&&deg<146.25)
				dir=tmp;
			else
				dir="S"+tmp;
		}
		else
			dir=tmp;
	}

	else if(168.75<=deg&&deg<258.75)
	{
		string tmp="S";

		if(191.25<=deg)
		{
			tmp+="W";
			
			if(191.25<=deg&&deg<213.75)
				dir="S"+tmp;
			else if(213.75<=deg&&deg<236.25)
				dir=tmp;
			else
				dir="W"+tmp;
		}
		else
			dir=tmp;
	}

	else if(258.75<=deg&&deg<348.75)
	{
		string tmp="W";

		if(281.25<=deg)
		{
			tmp="N"+tmp;
			
			if(281.25<=deg&&deg<303.75)
				dir="W"+tmp;
			else if(303.75<=deg&&deg<326.25)
				dir=tmp;
			else
				dir="N"+tmp;
		}
		else
			dir=tmp;
	}
	else
		dir="N";

	dis/=6;
	dis=floor(dis+0.5);
	dis/=10;
		
	if(0.0<=dis&&dis<=0.2)
	{	
		W="0";
		dir="C";
	}
	else if(0.3<=dis&&dis<=1.5) W="1";
	else if(1.6<=dis&&dis<=3.3) W="2";
	else if(3.4<=dis&&dis<=5.4) W="3";
	else if(5.5<=dis&&dis<=7.9) W="4";
	else if(8.0<=dis&&dis<=10.7) W="5";
	else if(10.8<=dis&&dis<=13.8) W="6";
	else if(13.9<=dis&&dis<=17.1) W="7";
	else if(17.2<=dis&&dis<=20.7) W="8";
	else if(20.8<=dis&&dis<=24.4) W="9";
	else if(24.5<=dis&&dis<=28.4) W="10";
	else if(28.5<=dis&&dis<=32.6) W="11";
	else W="12";

	cout<<dir<<" "<<W<<endl;

		


		return 0;
}


