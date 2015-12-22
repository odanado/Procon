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

double n,m,l;
double p,q,r;

int main()
{
	cin>>n>>m>>l;
	cin>>p>>q>>r;
	if(n<p&&m<p&&l<p){ puts("0");return 0;}
	if(n<q&&m<q&&l<q){ puts("0");return 0;}
	if(n<r&&m<r&&l<r){ puts("0");return 0;}

	double d=(n*m*l)/(p*q*r);
	if(true)//d==(int)d)
	{
		cout<<(int)d<<endl;
	}
	else
	{
	//if(n<p||m<p||l<p){ puts("0");return 0;}
	//if(n<q||m<q||l<q){ puts("0");return 0;}
	//if(n<r||m<r||l<r){ puts("0");return 0;}


		puts("0");
	}
	return 0;
}


