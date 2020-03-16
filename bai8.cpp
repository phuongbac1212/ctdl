#include <iostream>

using namespace std;

int main() {
	unsigned long x;
	cin >> x;
	bool k = false;
	
	for (int i=63; i>=0; i--) {
		if ((x>>i)&1) {
			k = true;
			cout << 1;
		}
		else if (k) {
			cout << 0;
		} 
	}
}
