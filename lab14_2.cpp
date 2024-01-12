#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	double x;
	for(int i = 0; i < N ; i++){
		cout << "Row " << i+1 << ": " ;
		for(int j = 0 ; j < N ; j++){
			cin >> x;
			A[i][j] = x;
		}
	}
}


void findLocalMax(const double A[][N], bool B[][N]){
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(i == 0 || i == N-1 || j == 0 || j == N-1){
				B[i][j] = false;
			}else{
				double top = A[i-1][j], bot = A[i+1][j], left = A[i][j-1], right = A[i][j+1];
				if(A[i][j] >= top && A[i][j] >= bot && A[i][j] >= left && A[i][j] >= right) {
					B[i][j] = true;
				}else{
					B[i][j] = false;
				}
			}
		}
	}
	
}

void showMatrix(const bool B[][N]){
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << B[i][j] << " ";
		}
		cout << "\n";
	}
}
