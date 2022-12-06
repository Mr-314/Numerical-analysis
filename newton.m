function newton(t0)
%1変数newton法のプログラム
N = 50; %最大反復回数
eps = 1e-12;
t = zeros(N,1); %配列の宣言
t(1) = t0; %初期値の代入

f = @(t) t^2-2;
df = @(t) 2*t;

for i = 1 : N-1
    t(i+1) = t(i) - f(t(i))/df(t(i));
    if abs(f(t(i+1))) < eps
        disp('このNewton法は収束し, その値は')
        t(i+1)
        break
    elseif i+1 == 50
        disp('このNewton法は収束しない')
    end
end