#ifndef LinearAlgebra_hpp
#define LinearAlgebra_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace::std;

void printVector(vector<double>);
void printMatrix(vector<vector<double> >);
vector<double> VectorSubtract(vector<double>,vector<double>);
vector<double> MatrixVector(vector<vector<double> >,vector<double>);
vector<double> ResidualError(vector<vector<double> >,vector<double>,vector<double>);
double VectorNorm1(vector<double>);
double VectorNorm2(vector<double>);
double VectorNormInfty(vector<double>);
double MatrixNorm1(vector<vector<double> >);
double MatrixNormInfty(vector<vector<double> >);

vector<double> Backwarg_sub(vector<vector<double> >, vector<double>);
vector<double> GaussianElimination(vector<vector<double> >, vector<double>);

vector<double> LUdecomp(vector<vector<double> >,vector<double>);


#endif /* LinearAlgebra_hpp */