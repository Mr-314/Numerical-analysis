#include <iostream>
#include "LinearAlgebra.hpp"
#include<vector>
#include<math.h>

int main(){
  vector<vector<double> > A(3,vector<double>(3) );
  vector<double> b(3);
  
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
			if(i == j){
				A[i][j] = 3;
			}
			else{
				A[i][j] = -1;
			}
			b[i] = 1;
		}
	}
	printMatrix(A);
	printVector(b);
	vector<double> x = LUdecomp(A, b);
	cout << "x= " << endl;
	printVector(x);
	
	return 0;
}