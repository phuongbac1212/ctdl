#define DEBUG

#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string


using namespace std;

/************ hàm doicho *************************/
/* @Para: 
*		x: tham chiếu thứ nhất
*		y: tham chiếu thứ 2
************************************************/
void doi_cho(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}

int main(int argc, char** args) {
#ifdef DEBUG
	cout << args[0] << endl;
	// De do thoi gian
	clock_t thoigian_batdau = clock();
#endif

	//---------------------------------------------------------------
	string input_file = "day1.in"; 				// Ten file input
	string output_file = "xuathien.out"; 			// Ten file input
	int N;	
	int num;										// Do day day so
	vector<int> A;									// Day so
	
	//---------------------------------------------------------------
	// Mo file va doc du lieu
	ifstream fin(input_file.c_str());	
	fin >> N;
	A.assign(N, 0);				// Khoi tao day A co N phan tu, moi phan tu co gia tri = 0
	for (int i = 0; i < N; i++) fin >> A[i];	
	// Dong file
	fin.close();
	//---------------------------------------------------------------
	// insertion sort 
	for (int i=0; i<N; i++) {
		for (int j=i; j>=0; j--) {
			if (A[j] < A[j-1])  
				doi_cho(A[j], A[j-1]); 
	 		else 
	   			break;
	   	}
	}

	for (int x: A) cout << x << " ";		
	
	//---------------------------------------------------------------

	// Mo file va ghi du lieu
	//ofstream fout(output_file.c_str());	
	//fout << max << " " << Amax << endl;
	// Dong file
	//fout.close();
	//---------------------------------------------------------------
#ifdef DEBUG
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
	cout << "Thoi gian chay: " << thoigian_chay << endl;
#endif

	return 0;
}

