#include<iostream>
#include<string>
using namespace std;

int ctoi(char x){
  return (x - '0');
}

int main(){
  string str;
  while(1){
    cin>>str;
    int l = str.length();
    if(str == "0")
      break;
    else{
      int c[l+1];
      c[0]=1;
      c[1]=1;
      for(int i=2; i<=l; i++){
        if ((ctoi(str[i-2])>2 || str[i-2]=='0') && str[i-1]=='0'){
          c[l] = 0;
          break;
        }
        else if(str[i-1]=='0')
          c[i] = c[i-2];
        else if(str[i-2]=='1' || (str[i-2]=='2' && ctoi(str[i-1])<=6))
          c[i] = c[i-1]+c[i-2];
        else
          c[i] = c[i-1];
      }
    cout<<c[l]<<endl;
    }
  }
  return 0;
}
