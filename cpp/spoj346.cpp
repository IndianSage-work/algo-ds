#include <iostream>
#include <map>
using namespace std;

map<int, long long> d;

long long f(int n){
	if (n==0)
		return 0;
	long long r = d[n];
	if(r==0){
		r = f(n/2)+f(n/3)+f(n/4);
		d[n]=n>r?n:r;
	}
	return d[n];
}

int main(){
	int n;
	while(cin>>n)
		printf("%lld\n",f(n));
	return 0;
}
