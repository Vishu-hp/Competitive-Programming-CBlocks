#include<iostream>
#include<algorithm>
using namespace std;



int main() {
	int n, key;

	int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
	n = 8;

	key = 40;

	bool present = binary_search(arr, arr + n, key);

	if (present) {
		cout << "Present" << endl;
	}
	else {
		cout << "Absent" << endl;
	}


	auto lb = lower_bound(arr, arr + n, key);
	cout << "Lower bound of 40 is :" << lb - arr << endl;



	auto ub = upper_bound(arr, arr + n, key);
	cout << "Upper bound of 40 is :" << ub - arr << endl;


	cout << "Occ Freq of 40 is :" << ub - lb << endl;

	return 0;
}
