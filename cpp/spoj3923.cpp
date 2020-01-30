#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T){
    int h,w;
    cin>>h>>w;
    int p[h][w],q[h][w];
    for (int i=0;i<h;i++)
      {for (int j=0;j<w;j++){
        cin>>p[i][j];
        if(i==0)
          q[i][j]=p[i][j];
        else if(j==0)
          q[i][j]=p[i][j]+max(q[i-1][j],q[i-1][j+1]);
        else if(j==w-1)
          q[i][j]=p[i][j]+max(q[i-1][j],q[i-1][j-1]);
        else
          q[i][j]=p[i][j]+max(max(q[i-1][j-1],q[i-1][j]),q[i-1][j+1]);
      }
    }
    cout<<*max_element(q[h-1],q[h-1]+w)<<endl;
    T--;
  }
  return 0;
}
