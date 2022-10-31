function pivotgauss(A,b)
% A : 係数行列
% b : 右辺ベクトル

N = length(A);
pivot = 1;
for k = 1:N-1
    max = abs(A(k,k));
    %pivot選択
    for m = k+1:N
        if abs(A(m,k))>max
            pivot = m;
            max = abs(A(m,k));
        end
    end
        if pivot>k
            for i = k:N
                s = A(k,i);
                A(k,i) = A(pivot,i);
                A(pivot,i) = s;
            end
                t = b(k);
                b(k) = b(pivot);
                b(pivot) = t;
        end
        
    %前進消去
    for i = k+1:N
        alpha = A(i,k)/A(k,k);
        for j = k:N
            A(i,j) = A(i,j) - alpha*A(k,j);
        end
        b(i) = b(i) - alpha*b(k);
   end
end

%後退代入
x = zeros(size(b));
for k = N:-1:1
    x(k) = b(k);
    for j = k+1:N
        x(k) = x(k) - A(k,j)*x(j);
    end
    x(k) = x(k)/A(k,k);
end
x
