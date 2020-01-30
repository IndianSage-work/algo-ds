#include <iostream>
using namespace std;
int main(){
	int x[3];
	while(1){
		cin>>x[0]>>x[1]>>x[2];
		if(x[0]==0 && x[2]==0)
			break;
		else{
			if(x[1]-x[0]==x[2]-x[1])
				cout<<"AP "<<x[2]+(x[2]-x[1])<<endl;
			else
				cout<<"GP "<<x[2]*(x[2]/x[1])<<endl;
		}
	}	
	return 0;
}