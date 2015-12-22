#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool G[12][12];

int n,m;
int ans;

vector<int> vec;

void f(int i)
{
	do{
		rep(j,i)
		{
			bool flg = false;
			rep(a,j)
			{
				rep(b,j)
				{
					if(vec[a]!=vec[b])
					{
						if(!G[vec[a]][vec[b]])
							goto go;
					}
				}
			}
			ans=max(ans,j);
go:;
		}
	}while(next_combination(vec.begin(), vec.begin()+i, vec.end()));
}

int main()
{
	cin>>n>>m;
	rep(i,n) vec.push_back(i);
	rep(i,m)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a][b]=G[b][a]=true;
	}


	rep(i,n)
	{
		f(i);
	}

	cout<<ans<<endl;


	return 0;
}
