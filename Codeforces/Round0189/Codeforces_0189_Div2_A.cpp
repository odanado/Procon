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


int main()
{
	string str;
	cin>>str;

	int n=str.size();

	str+="11";
	bool one;
	int a=0;

	rep(i,n)
	{
		if(str[i]=='1'&&str[i+1]=='4'&&str[i+2]=='4')
		{
			i+=2;
		}
		else if(str[i+1]=='4'&&str[i]=='1')
		{
			i+=1;
		}
		else if(str[i]=='1')
		{
		}
		else
		{
			//cout<<i<<endl;
			printf("NO\n");
			return 0;
		}
	
		

	}
	printf("YES\n");
	/*
	if(str[str.size()-2]=='1'&&str[str.size()-1]=='4')
	{
		printf("YES\n");
		return 0;
	}
	else if(str[str.size()-2]=='1'&&str[str.size()-1]=='1')
	{
		printf("YES\n");
		return 0;
	}
	else if(str[str.size()-3]=='1'&&str[str.size()-2]=='4'&&str[str.size()-1]=='4')
	{
		printf("YES\n");
		return 0;
	}
	else if(str.size()==1&&str[str.size()-1]=='1')
	{
		printf("YES\n");
		return 0;
	}
		
		printf("NO\n");
*/

		return 0;
}

