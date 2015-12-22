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

int x,y,n;
double d,ans=1000.0;
int a,b;

int main()
{
	cin>>x>>y>>n;
	d=(double)x/(double)y;
	//cout<<d<<endl;
	rep(i,n+1)
	{
		if(!i) continue;
		int lb=0,ub=100007;
		int mid,temp1,temp2;
		rep(j,100000)
		{
			mid=(lb+ub)/2;
			temp1=lb;
			temp2=ub;
			if((double)mid/(double)i >= d) ub=mid;
			else lb=mid;
			
			//printf("[debug];%d,%d,%lf,%lf,%lf,%lf\n",mid,i,d,ans,(double)mid/(double)i,abs(d-(double)mid/(double)i));
			if(ans>abs(d-(double)mid/(double)i))
			{
				//printf("[debug];%d,%d,%lf>%lf?\n",mid,i,ans,abs(d-(double)mid/(double)i));
				ans=abs(d-(double)mid/(double)i);
				a=mid;
				b=i;
			}
			if(ans==abs(d-(double)mid/(double)i)&&(b>i||a>mid))
			{
				ans=abs(d-(double)mid/(double)i);
				a=mid;
				b=i;
			}
			if(temp1==lb&&temp2==ub) break;
			//cout<<mid<<","<<lb<<","<<ub<<","<<i<<endl;
		}
		//printf("[debug]:%d.%d,%lf\n",mid,i,(double)mid/(double)i);
		//ans=min(ans,abs((double)mid/(double)i-d));
	}
	//cout<<ans<<endl;
	cout<<a<<"/"<<b<<endl;

	return 0;
}


