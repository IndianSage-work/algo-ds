#include <iostream>
#include <algorithm>
using namespace std;
int F(int x,int arr[],int &N,int &c){
	int cows=1,last=0;
	for(int i=1;i<N;i++){
		if(arr[i]-arr[last]>=x){
			cows++;
			if(cows==c)
				return 1;
			last=i;
		}
	}
	return 0;
}

int main(){
	int t,n,c;
	cin>>t;
	while(t){
		cin>>n>>c;
		int stall[n],i=0;
		while(i<n)
			cin>>stall[i++];
		sort(stall,stall+n);
		int start=stall[0],end=stall[n-1],mid;
		while(end-start>1){
			mid = start + (end-start)/2;
			(F(mid,stall,n,c)?start:end) = mid;
		}
		cout<<start<<endl;
		t--;
	}
	return 0;
}
