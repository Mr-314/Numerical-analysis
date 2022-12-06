function fractal(p, n, l)
% p 点の個数
% n 解きたい方程式の次数
% l 区間

function y = f(x, y)
    y = (x.^n) - 1; %Newton法を用いる関数
end

function y = df(x, n)
    y = n*(x.^(n-1)); %Newton法を用いる導関数
end

    N = 40;                    %反復回数
    x = 0;                     %実軸の中心
    y = 0;                     %虚軸の中心
    error = 1e-10;             %収束先判定のための許容誤差
    x = linspace(x-1, x+l, p); %実軸のプロット数
    y = linspace(y-1, y+l, p); %虚軸のプロット数
    [X, Y] = meshgrid(x, y);
    Z = X+1i*Y;

%Newton法の実行
for k = 1:N
    Z = Z - (f(Z, n)./ df(Z, n));
end

%フラクタルを描く
fracMat = zeros(p, p);      %フラクタルを描くための行列の宣言
for j = 1:n
    omega = exp(2*pi*1i/n)^j;       %d乗根のj乗を考える（1 <= j <= d）
    Mj = abs(Z - omega);
    color = (Mj <= error)*j;        % |Z - omega | < error の箇所をcolorと定義する
    fracMat = fracMat + color;
end

imagesc(fracMat)        %画像を表示する
colormap(hsv);      %色合いの設定
axis('square', 'equal', 'off');
imagetitle = sprintf('Newtonフラクタル（次数:%i）', n)
title(imagetitle)      %タイトルの表示
end
