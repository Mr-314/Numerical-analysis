#include <iostream>
#include "LinearAlgebra.hpp"

int main(){
  vector <vector<double> > A(3,vector<double>(3));
  vector<double> b(3);
  
  for(int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
      if(i==j){
        A[i][j]=3;
      }
      else{
        A[i][j] = -1;
      }
      b[i]=1;
    }
  }
  
  cout<<"A="<<endl;
  printMatrix(A);
  
  cout<<"b="<<endl;
  printVector(b);
  
  vector<double> x(3);
  x = GaussianElimination(A,b);
  
  cout<<"x="<<endl;
  printVector(x);
}