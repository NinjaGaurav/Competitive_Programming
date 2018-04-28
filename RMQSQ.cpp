// Gaurav Bholla, ASET
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;
class SegmentTree {   // 0 Indexed
public:
	SegmentTree(int count) {
		n = count;
		data = std::vector<int>(2 * n, 0);
	}

	SegmentTree(std::vector<int> const &values) {
		n = values.size();
		data = std::vector<int>(2 * n);
		std::copy(values.begin(), values.end(), &data[0] + n);
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = std::min(data[idx * 2], data[idx * 2 + 1]);
	}

	void update(int idx, int value) { 
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = std::min(data[2 * idx], data[2 * idx + 1]);
		}
	}

	int minimum(int left, int right) { // interval [left, right)
		int ret = std::numeric_limits<int>::max();
		left += n;
		right += n;

		while (left < right) {
			if (left & 1) ret = std::min(ret, data[left++]);
			if (right & 1) ret = std::min(ret, data[--right]);
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}

private:
	int n;
	std::vector<int> data;
};

int main() {
	int n,q,l,r;
	cin>>n;
	vector<int> x(n);
	for(int i=0;i<n;i++)
	cin>>x[i];
	cin>>q;
	SegmentTree st(x);
	while(q--)
	{
		cin>>l>>r;
		cout<<st.minimum(l,r+1)<<endl;
		
	}
	return 0;
}
