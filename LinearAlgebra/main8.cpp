//Rayleigh商
#include "LinearAlgebra.hpp"
#include <iostream>

int main(){
    int N = 3;
    vector<double>x(N);
    vector<double>y(N);
    int M = 200; //最大反復回数
    int K = 0; //試行回数
    double lambda1 = 0;
    double lambda2 = 0;
    double norm;
    vector<vector<double> > A(N,vector<double>(N));
    A[0][0] = 1;
    A[0][1] = 1;
    A[0][2] = 0;
    A[1][0] = 1;
    A[1][1] = 2;
    A[1][2] = 1;
    A[2][0] = 2;
    A[2][1] = 5;
    A[2][2] = 3;
    for(int i =0; i<N; i++){
        x[i] = 1;
    }

    //Rayleigh商を用いた固有値の計算
    double epsilon = 1e-08;
    for(int i=0; i<M; i++){
        K += 1;
        norm = VectorNorm2(x); //正規化
        for(int j=0; j<N; j++){
            x[j] /= norm;
        }
        y = MatrixVector(A, x);
        //Rayleigh商の式の計算
        lambda2 = 0;
        for (int k=0; k<N; k++){
            lambda2 += x[k]*y[k];
        }
        lambda2 /= (VectorNorm2(x)*VectorNorm2(x));

        //収束判定
        if(fabs(lambda1-lambda2)/fabs(lambda2)<epsilon){
            break;
        }
        else{
            lambda1 = lambda2;
            x = y;
        }
    }
    printf("試行回数は%d回\n",K);
    printf("固有値の最大値は%.8e\n",lambda2);
    printf("これに対応する固有ベクトルは");
    printVector(y);
}