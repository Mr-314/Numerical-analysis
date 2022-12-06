#include "LinearAlgebra.hpp"
#include <iostream>
#include <vector>
#include <math.h>

//ベクトルaを出力する
void printVector(vector<double> a){
  for (int i=0; i<a.size(); i++){
    printf("%.2e\t",a[i]);
  }
  printf("\n");
}

//行列Aを出力する
void printMatrix(vector<vector<double> > A){
  for (int i=0; i<A.size(); i++){
    for (int j=0; j<A.size(); j++){
      printf("%.2e\t",A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

//ベクトルa-bを計算し、結果を残す
vector<double> VectorSubtract(vector<double> a,vector<double> b){
  unsigned long n = a.size();
  vector<double> c(n);
  for (int i=0; i<n; i++){
    c[i] = a[i]-b[i];
  }
  return c;
}

//行列Aとベクトルxの乗算を行い、結果を返す
vector<double> MatrixVector(vector<vector<double> > A,vector<double> x){
  unsigned long n = x.size();
  vector<double> c(n);
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      c[i] = c[i]+A[i][j]*x[j];
    }
  }
  return c;
}

//A*x-bを返す
vector<double> ResidualError(vector<vector<double> > A,vector<double> x,vector<double> b){
  unsigned long n = x.size();
  vector<double> c(n);
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      c[i] = c[i]+A[i][j]*x[j];
    }
    c[i] = c[i]-b[i];
  }
  return c;
}

//ベクトルaの1ノルムを返す
double VectorNorm1(vector<double> a){
  double norm =0 ;
  for (int i=0; i<a.size(); i++){
    norm += fabs(a[i]);
  }
  return norm;
}

//ベクトルaの2ノルムを返す
double VectorNorm2(vector<double> a){
  double norm =0 ;
  for (int i=0; i<a.size(); i++){
    norm += fabs(a[i])*fabs(a[i]);
  }
  return sqrt(norm);
}

//ベクトルaのInfinityノルムを返す
double VectorNormInfty(vector<double> a){
  double norm =0 ;
  for (int i=0; i<a.size(); i++){
    if(norm<fabs(a[i])){
    norm = fabs(a[i]);
    }
  }
  return norm;
}

//行列Aの1ノルムを返す
double MatrixNorm1(vector<vector<double> > A){
  double norm =0 ;
  double x[A.size()];
  for (int j=0; j<A.size(); j++){
    for (int i=0; j<A.size(); i++){
      x[j] += fabs(A[i][j]);
    }
    if(norm<x[j]){
      norm = x[j];
    }
  }
  return norm;
}

//行列AのInfinityノルムを返す
double MatrixNormInfty(vector<vector<double> > A){
  double norm =0 ;
  double x[A.size()];
  for (int i=0; i<A.size(); i++){
    for (int j=0; j<A.size(); j++){
      x[i] += fabs(A[i][j]);
    }
    if(norm<x[i]){
      norm = x[i];
    }
  }
  return norm;
}

//後退代入Ax=b.
vector<double> Backwarg_sub(vector<vector<double> > A, vector<double> b){
  int N = int(b.size());
  vector<double> x(N);
  for(int k = N-1; k>=0; k--){
    x[k] = b[k];
    if(k !=N-1){
      for(int j =k+1; j<N; j++){
        x[k]=x[k]-A[k][j]*x[j];
      }
    }
    x[k] = x[k]/A[k][k];
  }
  return x;
}

//Gauss消去法
vector<double> GaussianElimination(vector<vector<double> > a, vector<double> c){
  unsigned long N = c.size();
  vector <vector<double> > A(N,vector<double>(N));
  vector <double> b(N);
  A = a;
  b = c;
  
  //前進消去法
  double alpha =0;
  for (int k = 0; k<N-1; k++){
    for (int i = k+1; i<=N-1; i++){
      alpha = A[i][k]/A[k][k];
      for(int j = k; j<=N; j++){
        A[i][j] = A[i][j]-alpha*A[k][j];
      }
      b[i] = b[i]-alpha*b[k];
    }
  }
  cout<<"前進消去\n";
  cout<<"A = " <<endl;
  printMatrix(A);
  cout<<"b = " <<endl;
  printVector(b);
  //後退代入
  cout<<"後退代入\n";
  vector<double> x(N);
  x = Backwarg_sub(A,b);
  return x;
}

//LU分解
vector<double> LUdecomp(vector<vector<double> > a,vector<double> c){
  unsigned long N = c.size();
  vector<vector<double> > A(N, vector<double>(N));
  vector<double> b(N);
  A = a;
  b = c;
  
  //LU分解の行列を構築する
  double alpha = 0;
  for (int k = 0;k<N-1;k++){
    for (int i = k+1; i<=N-1; i++){
      alpha = A[i][k]/A[k][k];
      A[i][k] = alpha;
      for (int j = k+1; j<= N-1; j++){
        A[i][j] = A[i][j] - alpha*A[k][j];
      }
    }
  }
  cout << "LU分解行列\n";
  cout << "A = " <<endl;
  printMatrix(A);
  
  //前進代入
  vector<double> y(N);
  y[0] = b[0];
  for (int k = 1; k<=N-1; k++){
    y[k] = b[k];
    for (int j = 0; j<k; j++){
      y[k] -= A[k][j]*y[j];
    }
  }
  //後退代入
  vector <double> x(N);
  x = Backwarg_sub(A, y);
  return x;
}