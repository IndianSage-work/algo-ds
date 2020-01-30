#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n,a,b;
	cin>>n;
	while(n){
		cin>>a>>b;
		if(b==0)
			cout<<1;
		else if(a==0)
			cout<<0;
		else{
			int l=a-((a/10)*10),e=(b%4)?(b%4):4;
			cout<<pow(l,e)-(((int)pow(l,e)/10)*10);
		}
		cout<<"\n";
		n--;
	}
	return 0;
}