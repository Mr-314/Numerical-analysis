#include <iostream>
#include "LinearAlgebra.hpp"
#include <vector>
#include <math.h>
#include <iomanip>

int main(){
  vector <vector<double> > A(8,vector<double>(8));
  vector<double> b(8);
  
  for(int i = 0; i<8; i++){
    for (int j = 0; j<8; j++){
      if(i==j){
        A[i][j]=4;
      }
      else if(0 <= abs(i-j) and abs(i-j)<=2){
        A[i][j]=1;
      }
      else{
        A[i][j] = 0;
      }
      b[i]=1;
    }
  }
  
  //（１） コードわからないけどて計算だと両方8になる
  //double A_1 = MatrixNorm1(A);
  //double A_i = MatrixNormInfty(A);
  //printf("%f", A_1);
  //printf("%f", A_i);
  
  
  //（２）
  cout<<"A="<<endl;
  printMatrix(A);
  
  cout<<"b="<<endl;
  printVector(b);
  
  //（３）
  vector<double> x(8);
  x = GaussianElimination(A,b);
  
  cout<<"x="<<endl;
  printVector(x);
  
  //（４）
  vector<double> y = ResidualError(A,x,b);
  double y_1 = VectorNorm1(y);
  double y_2 = VectorNorm2(y);
  double y_i = VectorNormInfty(y);
  
  cout<<"||Ax-b||_1="<<std::setprecision(3)<< y_1 <<endl;
  cout<<"||Ax-b||_2="<<std::setprecision(3)<< y_2 <<endl;
  cout<<"||Ax-b||_∞="<<std::setprecision(3)<< y_i <<endl;
  
}