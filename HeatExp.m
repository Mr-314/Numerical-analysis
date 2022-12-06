function U=HeatExp(n,m)
%[0,1]区間の熱方程式の陽解法

h=1/(n);%分割幅
k=1/(m);%分割幅
r=k/(h^2);

U=zeros(n+1,m+1);%配列の宣言

%初期関数
for s=2:n
    U(s,1)=1;
end

%陽解法の実行
for j=2:m+1
    for i=2:n
        U(i,j)=r*U(i-1,j-1)+(1-2*r)*U(i,j-1)+r*U(i+1,j-1);
    end
end

%グラフのプロット
figure(1)
clf
plot(linspace(0,1,n+1),U(:,m+1));
xlabel('x-axis')
ylabel('u-axis')


%以下のようにグラフを出力すると, 熱分布の変化を視覚的に確認することができます.
%figure(1)
%clf
%hold on
%for i=0:10
%    plot(linspace(0,1,n+1),U(:,1+50*i))
%    pause
%end
%hold off