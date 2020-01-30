#include <iostream>
using namespace std;
int main(){
	int col,row;
	string s;
	while(1){
		cin>>col;
		if(col!=0){
			cin>>s;
			row=s.length()/col;
			for(int i=0;i<col;i++){
				for(int j=0;j<(row+1)/2;j++){
					cout<<s[i + j*2*col];
					if((i + (j+1)*2*col - ((2*i)+1))<s.length())
						cout<<s[i + (j+1)*2*col - ((2*i)+1)];
				}
			}
			cout<<"\n";
		}
		else
			break;
	}		
	return 0;
}