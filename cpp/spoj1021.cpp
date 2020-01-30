#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T){
    string s;
    cin>>s;
    int l = s.length();
    int arr[l][l];
    string srev = s;
    reverse(srev.begin(),srev.end());
    for(int i=0;i<l;i++){
      int f=0;
      for(int j=0;j<l;j++){
        if(i==0 && s[i]==srev[j]){
          f=1;
          arr[i][j]=1;
        }
        else if(i==0 && f==1)
          arr[i][j]=1;
        else
          arr[i][j]=0;
        if(j==0 && i!=0)
          arr[i][j] = s[i]==srev[j]?1:arr[i-1][j];
        if(j!=0 && i!=0)
          arr[i][j] = s[i]==srev[j]?arr[i-1][j-1]+1:max(arr[i-1][j],arr[i][j-1]);
      }
    }
    T--;
    cout<<l - arr[l-1][l-1]<<endl;
  }
  return 0;
}
