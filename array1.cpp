#define DEBUG 

#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string


using namespace std;

int gcd(int a, int b) {
	return (b == 0)?(a):gcd(b,a%b);
}

int main(int argc, char** args) { 	// đoạn này là thêm các argument để gọi sinh cho dễ
									// VD: sinh 1000 số <100 thì gọi ./array1 1000 100
	// De do thoi gian
	clock_t thoigian_batdau = clock();
	
	int N, K;
	
	/*	nhận N được truyền từ arguments		*/
	//	N mặc định là 10000 nếu không dduwocj truyền vào.
	if (NULL != args[1]) {
		N = atoi(args[1]);
	}
	else { 
		N = 10000;
	}
#ifdef DEBUG
	cout << "Genernating " << N << " numbers"<< endl;
#endif
	/***************************************/
	
	/*	nhận K được truyền từ arguments		*/
	// K mặc định là 1000 nếu k được truyền vào 
	if (NULL != args[2]) { 
		K = atoi(args[2]);
		if (K==0) K=1000;
	}
	else {
		K = 1000;
	} 
#ifdef DEBUG
	cout << "Each below " << K << endl;
#endif
	/***************************************/
	
	vector<int> A;
	
	int seed = 1;
	srand(seed);
	
		
	// Khoi tao A co N phan tu
	A.assign(N, 0);
	for (int i = 0; i < N; i++) A[i] = rand() % K;
	
	string output_file = "day1.in";
	
	// Mo file day1.in de ghi ket qua
	ofstream fout(output_file.c_str());
	fout << N << endl;
	for (int i = 0; i < N; i++) 
		if (i < N-1) {
			fout << A[i] << " ";
		}
		else {
			fout << A[i] << endl;
		}
	fout.close();	// Dong file
	
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
#ifdef DEBUG
	cout << "Thoi gian chay[array1.cpp]: " << thoigian_chay << endl<<endl;
#endif
	return 0;
}

