#include <iostream>
#include "LinearAlgebra.hpp"

int main(){
  int n = 3;
  vector<double> a(n);
  vector<double> x(n);
  vector<vector<double> > A(n,vector<double>(n) );
  
  for (int i=0; i<n; i++){
    a[i] = i;
    for (int j=0; j<n; j++){
      A[i][j] = i+2*j;
    }
  }
  cout << "a= "<< endl;
  printVector(a);
  
  cout << "A= " << endl;
  printMatrix(A);
}