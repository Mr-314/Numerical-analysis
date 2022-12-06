#include <iostream>
#include "LinearAlgebra.hpp"

int main(){
  vector<vector<double> > A(6,vector<double>(6) );
  vector<double> b(6);
  
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
			if(i == j){
				A[i][j] = 1;
			}
			else if(i == j+1){
				A[i][j] = 6;
			}
			else if(i == j+2){
				A[i][j] = 5;
			}
			else if(i == j+3){
				A[i][j] = 4;
			}
			else if(i == j+4){
				A[i][j] = 3;
			}
			else if(i == j+5){
				A[i][j] = 2;
			}
			else if(i == j-1){
				A[i][j] = 2;
			}
			else if(i == j-2){
				A[i][j] = 3;
			}
			else if(i == j-3){
				A[i][j] = 4;
			}
			else if(i == j-4){
				A[i][j] = 5;
			}
			else if(i == j-5){
				A[i][j] = 6;
			}
			else{
				A[i][j] = -1;
			}
			b[i] = i;
		}
	}
	
	printMatrix(A);
	printVector(b);
	vector<double> x = LUdecomp(A, b);
	cout << "x= " << endl;
	printVector(x);
	
	
	return 0;
}