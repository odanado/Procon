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

int n;
string ss;

int main()
{
	cin>>n;
	cin>>ss;

	int A=0,I=0,F=0;
	int ans=0;
	rep(i,n)
	{
		if(ss[i]=='F') F++;
		if(ss[i]=='A') A++;
		if(ss[i]=='I') I++;

	}
	if(I==0)
	{
		cout<<A<<endl;
	}
	else if(I==1)
	{
		cout<<"1"<<endl;
	}
	else 
	{
		cout<<"0"<<endl;
	}

	return 0;
}


