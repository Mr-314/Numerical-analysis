function RenritsuNewton(x0, y0)
%連立Newton法のプログラム
%x0, y0：初期値

N = 30; %最大反復回数
eps = 1E-12 %許容誤差
X = zeros(N, 1); %配列の宣言
Y = zeros(N, 1);
X(1) = x0; %初期値を設定
Y(1) = y0;

%Newton法を用いる関数と導関数を入力
f = @(x, y) x - 0.7*sin(x) - 0.2*cos(y);
g = @(x, y) y - 0.7*cos(x) - 0.2*sin(y);
fx = @(x, y) 1 - 0.7*cos(x);
fy = @(x, y) 0.2*sin(y);
gx = @(x, y) -0.7*sin(x);
gy = @(x, y) 1 - 0.2*cos(y);

for n = 1 : N
    J = [fx(X(n), Y(n)), fy(X(n), Y(n)); gx(X(n), Y(n)), gy(X(n), Y(n))]; %Jacobi行列の定義（更新）
    d = linsolve(J, -[f(X(n), Y(n));g(X(n), Y(n))]);
    X(n+1) = X(n)+d(1);
    Y(n+1) = Y(n)+d(2);

    if(norm([f(X(n+1), Y(n+1));g(X(n), Y(n))], 1)<eps)
        disp([X(n+1), Y(n+1)])
        break;
       
    elseif (n == N)
        disp('収束しない')
    end
end