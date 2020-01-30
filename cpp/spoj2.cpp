#include <iostream>
using namespace std;
bool prime(int j){
	for(int i=2;i*i<=j;i++){
		if(j%i==0)
			return false;
	}
	return true;
}
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m,n;
		cin>>m>>n;
		if(m<2)
			m=2;
		for(int j=m;j<=n;j++){
			if(prime(j))
				cout<<j<<endl;
		}
	}
	return 0;
}