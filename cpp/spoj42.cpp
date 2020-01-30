#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y;
		string xs = to_string(x);
		string ys = to_string(y);
		reverse(xs.begin(),xs.end());
		reverse(ys.begin(),ys.end());
		x = stoi(xs);
		y = stoi(ys);
		z=x+y;
		string zs = to_string(z);
		reverse(zs.begin(),zs.end());
		cout<<stoi(zs)<<endl;
	}
	return 0;
}