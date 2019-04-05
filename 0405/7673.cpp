#include<iostream>
#include<string>

using namespace std;
int main() {
	bool arr[10000 + 1];
	int temp = 0;

	memset(arr, false, 10000 + 1);

	for (int i = 1; i <= 10000; i++) {
		temp = i;
		int temp_i = i;

		while (temp_i > 0) {
			temp += (temp_i % 10);
			temp_i /= 10;
		}
		if (temp <= 10000)
			arr[temp] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == false)
			cout << i << '\n';
	}

}
