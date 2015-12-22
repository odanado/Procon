#include <iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct Dice{
    int face[6]; // top,bottom,left,right,front,back
    void Rotate(int a,int b,int c,int d){
        int temp=face[a]; 
        face[a]=face[b]; 
        face[b]=face[c]; 
        face[c]=face[d]; 
        face[d]=temp;
    }
    void TurnF(int n){rep(i,n)Rotate(0,2,1,3);} // x軸を回転軸として右回りに90n度回転
    void TurnR(int n){rep(i,n)Rotate(0,4,1,5);} // y軸を回転軸として右回りに90n度回転
    void TurnU(int n){rep(i,n)Rotate(4,3,5,2);} // z軸を回転軸として右回りに90n度回転
    void TurnF(){TurnF(1);}
    void TurnR(){TurnR(1);}
    void TurnU(){TurnU(1);}
    void show() {
        cout<<"top    : "<<face[0]<<endl;
        cout<<"bottom : "<<face[1]<<endl;
        cout<<"left   : "<<face[2]<<endl;
        cout<<"right  : "<<face[3]<<endl;
        cout<<"front  : "<<face[4]<<endl;
        cout<<"back   : "<<face[5]<<endl;
    }
};
int n;
void solve() {
    Dice dice;
    dice.face[0]=1; dice.face[1]=6;
    dice.face[2]=4; dice.face[3]=3;
    dice.face[4]=2; dice.face[5]=5;

    int ans=1;
    rep(i,n) {
        string s; cin>>s;
        if(s=="North") dice.TurnR(1);
        else if(s=="South") dice.TurnR(3);
        else if(s=="East") dice.TurnF(1);
        else if(s=="West") dice.TurnF(3);
        else if(s=="Right") dice.TurnU(1);
        else if(s=="Left") dice.TurnU(3);
        ans+=dice.face[0];
    }
    cout<<ans<<endl;
}

int main() {
    while(cin>>n) {
        if(!n) break;
        solve();
    }
    return 0;
}
