#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a;
	cin >> a;
	int n = sqrt(a);
	
	for (int i =1i; i<n; i++) {
		if (a % i == 0)  {
			cout << i << " " << a/i << " ";
		}
	} 
	if (n*n == a) cout << n;
	return 0;
}
