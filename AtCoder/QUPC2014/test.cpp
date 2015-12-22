#include<string>
#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<cmath>
 
using namespace std;
 
#define EPS_B 1E-10
#define EPS 1E-8
#define INF 1E100
 
typedef pair<double,double> pdd;
 
 
 
double getlength(double x0,double y0,double vx,double vy,double vh,double t){
	double x = x0 + t*vx;
	double y = y0 + t*vy;
	
	double len = sqrt(x*x + y*y);
	double h = vh*t;
	
	return len-h;
}
 
int main(){
	double x0,y0,vx,vy,vh;
	cin>>x0>>y0>>vx>>vy>>vh;
	
	
	double left = 0;
	double right = INF;
	
	while(1){
		double dist = right-left;
		double h1 = left + dist/3;
		double h2 = left + dist*2/3;
		
		//printf("%lf %lf %lf %lf\n",left,h1,h2,right);
		
		double t1 = getlength(x0, y0, vx, vy, vh, h1);
		double t2 = getlength(x0, y0, vx, vy, vh, h2);
		
		if(t1<=0)t1=0;
		if(t2<=0)t2=0;
		
		pdd d1 = pdd(t1, h1);
		pdd d2 = pdd(t2, h2);
		
		//printf("\t%lf %lf %lf %lf\n\n",t1,h1,t2,h2);
		
		if(d1<d2){
			right = h2;
		}else{
			left = h1;
		}
		
		if(right-left<EPS_B)break;
	}
	
	//printf("%lf %lf\n",left, getlength(x0, y0, vx, vy, vh, left));
	if(getlength(x0, y0, vx, vy, vh, left)>EPS)printf("IMPOSSIBLE\n");
	else printf("%lf\n",left);
}
 