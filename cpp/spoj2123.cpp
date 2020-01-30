#include <iostream>
using namespace std;
int main(){
	int x,y;
	while(1){
		cin>>x;
		if(x == -1)
			break;
		else{
			int sum=0,div,a[x];
			for(int i=0;i<x;i++){
				cin>>a[i];
				sum+=a[i];
			}
			if(sum%x != 0)
				cout<<-1<<endl;
			else{
				div = sum/x;
				int count=0;
				for(int i=0;i<x;i++){
					if(a[i]>div)
						count+=(a[i]-div);
				}
				cout<<count<<endl;
			}
		}
	}	
	return 0;
}