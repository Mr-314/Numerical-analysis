function eca184(N,R)
%ECA184のシミュレーション
%右端点(第N行)は0にしておく
%N:全体のサイズ
%R:繰り返し数


Z=zeros(R,N);%配列の宣言
Z(1,:)=randi([0,1],1,N);%初期条件(今回はランダムに与える)

%ルールを決める
for i=2:R
    for j=2:N-1
        if Z(i-1,j-1)==1 && Z(i-1,j)==1 && Z(i-1,j+1)==1
            Z(i,j)=1;
        elseif Z(i-1,j-1)==1 && Z(i-1,j)==1 && Z(i-1,j+1)==0
            Z(i,j)=0;
        elseif Z(i-1,j-1)==1 && Z(i-1,j)==0 && Z(i-1,j+1)==1
            Z(i,j)=1;
        elseif Z(i-1,j-1)==1 && Z(i-1,j)==0 && Z(i-1,j+1)==0
            Z(i,j)=1;
        elseif Z(i-1,j-1)==0 && Z(i-1,j)==1 && Z(i-1,j+1)==1
            Z(i,j)=1; 
        elseif Z(i-1,j-1)==0 && Z(i-1,j)==1 && Z(i-1,j+1)==0
            Z(i,j)=0;
        elseif Z(i-1,j-1)==0 && Z(i-1,j)==0 && Z(i-1,j+1)==1
            Z(i,j)=0;
        elseif Z(i-1,j-1)==0 && Z(i-1,j)==0 && Z(i-1,j+1)==0
            Z(i,j)=0;
        end
    end
end

Z=-(Z-ones(R,N));%0と1を逆転させる
figure(1)
colormap gray
imagesc(Z)