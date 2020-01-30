#include <iostream>
using namespace std;
int main(){
	int N,ans;
	while(1){
		cin>>N;
		if(N!=0){
			ans=0;
			for(int i=N;i>=1;i--)
				ans+=(i*i);
			cout<<ans<<endl;
		}
		else
			break;
	}
	return 0;
}