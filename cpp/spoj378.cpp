#include<iostream>
int main(){
	int n,c=0,i=0,a;
	std::cin>>n;
	while(i++<n){
		std::cin>>a;
		a>0?c+=a:0;
	}
	std::cout<<c;
}