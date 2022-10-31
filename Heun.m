function heun2(N, a, b)
  
f = @(x,y)x+y;
%h：分割幅
%[a, b]：区間
h = (b-a)/N; 
%N = (b-a)/h; 
x = a:h:b;

% 初期条件
y1 = zeros(size(x));
y1(1) = 1;          
y2 = zeros(size(x)); 
y2(1) = 1;           

for i = 1:length(x)-1
    y1(i+1) = y1(i)+h/2*(f(x(i),y1(i))+f(x(i+1),y1(i)+h*f(x(i),y1(i)))); %Heun法
end
figure(1)
plot(x, y1, '-s');
hold on
hold off
xlabel('x-axis')
ylabel('y-axis')
legend
format longE
y1(N+1)
