#define DEBUG

#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string


using namespace std;

/************ hàm search *************************/
/* @Para: 
*		A: tham chiếu đến vector A
*		N: số lượng phần tử của vector A
*		num: số cần tìm
************************************************/

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
	// thực hiện tìm số ần xuất hiện
	int dem=0;	//lưu số lần xuất hiện của x 
	int max=0; 	// lưu số lần xuất hiện lớp nhất
	int Amax=0;	// lưu số có lần xuất hện lớn nhất
	int i=0;
	for (int x: A) {
	 	cout << i++ << endl;
	 	dem =0;
		for (int i=0; i<N; i++) {
			if (x == A[i]) dem ++;
		}
		if (dem > max) {
			max git = dem;
			Amax = x;
		}
	}
	cout << Amax << " " << max << endl;
	//---------------------------------------------------------------

	// Mo file va ghi du lieu
	ofstream fout(output_file.c_str());	
	fout << max << " " << Amax << endl;
	// Dong file
	fout.close();
	//---------------------------------------------------------------
	
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
#ifdef DEBUG
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
	cout << "Thoi gian chay: " << thoigian_chay << endl;
#endif

	return 0;
}

