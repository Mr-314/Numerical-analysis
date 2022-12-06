function [A,Q]=JacobiMethod(B)
%Jacobi法のプログラム
%B：対称行列
%A:対角化行列, Q:固有ベクトルからなる行列

n=length(B);
s=50; %最大反復回数
epsilon=10^(-5);%許容誤差
A=B;
Q=eye(n);


for l=1:s
    %行列の絶対値最大値とその位置を探す
    a=0;
    for i = 1:n
        for j = 1:n
            if i~=j && abs(A(i,j))>abs(a)
                a=A(i,j);
                k=i;%絶対値最大のi成分
                m=j;%絶対値最大のj成分
            end
        end
    end
    %収束判定
    if abs(a)<epsilon
        break
    end

    %角度thetaの決定
    if A(k,k)==A(m,m)
        theta=pi/4;
    else
        theta=1/2*atan(A(k,m)/(A(k,k)-A(m,m)));
    end

    %Givens回転行列の定義
    P=eye(n);
    P(k,k)=cos(theta);
    P(k,m)=-sin(theta);
    P(m,k)=sin(theta);
    P(m,m)=cos(theta);

    %transpose(P)APを計算する
    A=transpose(P)*A*P;
    Q=Q*P;

end