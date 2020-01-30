#include<iostream>
#include<algorithm>
using namespace std;

struct act{
  int start;
  int end;
};

bool actcmp(act a, act b){
  if(a.end!=b.end)
    return a.end<b.end;
  return a.start<b.start;
}

int main(){
  int t,n;
  cin>>t;
  while(t){
    int c=0;
    cin>>n;
    act arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i].start>>arr[i].end;
    sort(arr,arr+n,actcmp);
    int j=0,end;
    while(j<n){
      c++;
      end = arr[j].end;
      j++;
      while(end>arr[j].start)
        j++;
    }
    cout<<c<<endl;
    t--;
  }
  return 0;
}
