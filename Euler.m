function euler1_1(omega,N,a,b)
%N : 分割数
%h : 時間刻み
h = (b-a)/N;
t = a:h:b; %区間分割（[a,b]区間をN個に分割）

%初期条件
y1 = zeros(size(t)); 
y1(1) = 0;           
y2 = zeros(size(t)); 
y2(1) = 1;           
for i = 1:length(t)-1
    y1(i+1) = y1(i)+y2(i)*h;
    y2(i+1) = -h*omega^2*y1(i)+y2(i);
end
figure(1)
plot(t,y1,'-s','DisplayName','y');
hold on
plot(t,y2,'-p','DisplayName','dy');
hold off
xlabel('t-axis')
ylabel('y-axis')
legend
format longE
y1(N+1)
