#include <iostream>
using namespace std;
int main() {
	// your code goes here
	unsigned int mw;
	float tc;
	cin>>mw;
	cin>>tc;
	if(((mw+0.5)>tc)||((mw%5)!=0))
	cout<<tc;
	else
	cout<<tc-(mw+0.5);
	return 0;
}
