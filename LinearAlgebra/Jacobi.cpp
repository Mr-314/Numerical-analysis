#include "LinearAlgebra.hpp"
#include <iostream>
int main(){
    int N = 3; //行列の次元
    int M = 100; //最大反復回数
    int p = 0; //試行回数
    double epsilon = 1e-07; //許容誤差条件
    double error; //誤差
    vector<double>x(N); //初期値
    vector<double>y(N);
    vector<vector<double> > A(N, vector<double>(N)); //係数行列
    vector<double> b(N); //右辺ベクトル

    for(int i = 0; i<N; i++){
        for (int j= 0; j<N; j++){
            if(i==j){
                A[i][j]=4;
            }
            else{
                A[i][j]=-1;
            }
            b[i]=1;

        }
    }
    x = b;
    y = b;

    //Jacobi法
    for(int m=0; m<=M; m++){
        for(int i=0; i<=N-1; i++){
            y[i]=b[i];
            for(int j=0; j<=N; j++){
                y[i] -= A[i][j]*x[j];
            }
            y[i] += A[i][i]*x[i];
            y[i] /= A[i][i];
        }
        p += 1;
        error = VectorNormInfty(VectorSubtract(x, y))/VectorNormInfty(y);
        if(error <= epsilon){
            printf("Jacobi法の反復回数は%d回\n", p);

            printVector(x);
            break;
        }
        else if(p ==M){
            printf("収束しません");
        }
        else{
            for (int i = 0; i<=N-1; i++){
                x[i] = y[i];
            }
        }
    }
    return 0;
}