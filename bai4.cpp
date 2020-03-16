#include <iostream>			// De su dung cin cout
#include <fstream>			// De doc ghi file		
#include <cstdlib>			// De su dung cac thu vien cua he thong
#include <ctime>			// De dem thoi gian

#include <algorithm>		// De su dung cac thuat toan co ban
	
#include <vector>			// Cau truc du lieu vector
#include <string>			// Cau truc du lieu string


using namespace std;

bool sorted = false;

int normalSearch(vector<int> &A,int N, int num){
	for (int i=0; i<N; i++) {
		if (A[i]==num) return i; 
	}
	return -1;
}

/*******************FAIL******************************
int binarySearch(vector<int> &A, int N, int num) {
	if (!sorted) {
		sort(A.begin(), A.end());
	}
	
	int d=0, c=N-1; 
	while (d<c) {
		int g = (d+c)/2;
		if (A[g] == num) return g;
		if (A[g] > num) {
			d = g+1;
		}
		else {
			c = g-1;
		}
	}
	 
    return -1; 
}
********************************************************/

int main(int argc, char** args) {
	cout << args[0] << endl;
	// De do thoi gian
	clock_t thoigian_batdau = clock();
	
	//---------------------------------------------------------------
	string input_file = "search1.in"; 				// Ten file input
	string output_file = "search1.out"; 			// Ten file input
	int N;	
	int num;										// Do day day so
	vector<int> A;									// Day so
	
	//---------------------------------------------------------------
	// Mo file va doc du lieu
	ifstream fin(input_file.c_str());	
	fin >> N;
	fin >> num;
	A.assign(N, 0);				// Khoi tao day A co N phan tu, moi phan tu co gia tri = 0
	for (int i = 0; i < N; i++) fin >> A[i];	
	// Dong file
	fin.close();
	//---------------------------------------------------------------
	// Tim kiem 
	int srch = normalSearch(A, N, num);
	cout << srch;
	//---------------------------------------------------------------
	// Mo file va doc du lieu
	ofstream fout(output_file.c_str());	
	if (-1 == srch) 
		fout << "NO" << endl;
	else 
		fout << srch << endl;
	// Dong file
	fout.close();
	//---------------------------------------------------------------
	
	// De do thoi gian
	clock_t thoigian_chayxong = clock();
	// CLOCKS_PER_SEC la thoi gian doi tu` dong ho cua chip sang giay
	double thoigian_chay = double(thoigian_chayxong - thoigian_batdau) / CLOCKS_PER_SEC;		
	cout << "Thoi gian chay: " << thoigian_chay << endl;
	 	
	return 0;
}

