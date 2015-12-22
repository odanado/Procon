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


string FizzBuzz[100007];

std::string int_to_str(int _int)
{
		std::string res;
		std::ostringstream os;
		os << _int;
		return os.str();
}
void solve(int m,int n)
{
	string str;
	bool player[10007];
	int index=0;
	int cnt=0;
	rep(i,m+1) player[i]=true;


	rep(i,n)
	{
		cin>>str;
		while(!player[index]) 
		{
			index++;
			index%=m;
		}
		if(player[index])
		{
			player[index] = (str == FizzBuzz[i+1]);
			index++;
			index%=m;
			if(str != FizzBuzz[i+1])
			{
				cnt++;
				if(m-1==cnt) break;
			}
		}
	}
	int a=0;

	rep(i,m) if(player[i]) a=i+1;

	rep(i,m)
	{
		if(player[i])
		{
			if(a==i+1)
				cout<<i+1<<endl;
			else
				cout<<i+1<<" ";

		}

	}
				
				

}
int main()
{
	rep(i,100007)
	{
		if(!i) continue;
		if(i%3==0) FizzBuzz[i]+="Fizz";
		if(i%5==0) FizzBuzz[i]+="Buzz";
		if(i%3!=0&&i%5!=0) FizzBuzz[i]+=int_to_str(i);

	}

	int n,m;
	while(cin>>m>>n)
	{
		if(n==0&&m==0) return 0;

		solve(m,n);
	}
		return 0;
}


