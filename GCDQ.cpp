/////////////////////////////////////
//	Author:			Gaurav Bholla  //
//	Institution: 	ASET, Bijwasan //
/////////////////////////////////////

#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;
class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = new int[2 * n];
	}

	SegmentTree(int values[],int N) {
		n = N;
		data = new int[2 * n];
//		std::copy(values.begin(), values.end(), &data[0] + n);
        for(int i=n;i<2*n;i++)
            data[i]=values[i-n];
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = __gcd(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, int value) {      //arr[idx]=value   i.e. 0 indexed
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = __gcd(data[2 * idx], data[2 * idx + 1]);
		}
	}

	int rangeGCD(int left, int right) { // interval [left, right)

		left += n;
		right += n;
        int ret = data[left];
		while (left < right) {
			if (left & 1) ret = __gcd(ret, data[left++]);
			if (right & 1) ret = __gcd(ret, data[--right]);
			left >>= 1;
			right >>= 1;

		}
		return ret;
	}

private:
	int n;
	int* data;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int t;
    cin>>t;
    while(t--){
    int n,q;
    cin>>n>>q;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    SegmentTree ST(x,n);
    int l,r;

       while(q--)
       {

           cin>>l>>r;
            --l;--r;
            if(l==0)
                cout<<ST.rangeGCD(r+1,n)<<endl;
            else if(r==n-1)
                cout<<ST.rangeGCD(0,l)<<endl;
           else
               cout<<__gcd(ST.rangeGCD(0,l),ST.rangeGCD(r+1,n))<<endl;



       }
    }
    return 0;
}
