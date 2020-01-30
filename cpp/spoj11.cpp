#include <iostream>
using namespace std;
int Z(int n){
	int count=0;
	for(int i=5;i<=n;i*=5)
		count+=n/i;
	return count;
}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int N;
		cin>>N;
		cout<<Z(N)<<endl;
	}
	return 0;
}