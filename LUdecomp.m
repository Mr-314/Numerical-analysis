function [A, x] = LUdecomp(C, b)
%Aは正方行列
A = C;
n = length(A);

for k = 1 : n
    for i = k+1: n
        alpha = A(i,k)/A(k,k);
        A(i,k) = alpha;
        for j = k+1 : n
            A(i,j) = A(i,j) - alpha*A(k,j);
        end
    end
end

%前進代入
y = zeros(size(b));
for k = 1 : n
    y(k) = b(k);
    for j = 1 : k - 1
        y(k) = y(k) - A(k,j)*y(j);
    end
end

%後進代入
x = zeros(size(b));
for k = 1 : n
    x(n-k+1) = y(n-k+1);
    for j = n-k+2 : n
        x(n-k+1) = x(n-k+1) - A(n-k+1,j)*x(j);
    end
    x(n-k+1) = x(n-k+1)/A(n-k+1,n-k+1);
end

