clear all;
close all;
clc;

A = [1 1 1;
     0 0 3;
     0 2 3];
 
v = ones(1,length(A));
L = diag(v);
U = zeros(length(A),length(A));
 
%Iterate through columns
for j = 1:length(A)
    %Check for need to swap pivot
    if(A(j,j) == 0)
        %Search for maximum value below pivot
        for l = j:length(A)
            max = 0;
            maxRow = 0;
            if(abs(A(l,j)) > abs(max))
                max = A(l,j);
                maxRow = l;
            end
        end
        %Swap rows
        for k = j:length(A)
            temp(k) = A(j,k);
            A(j,k) = A(maxRow,k);
            A(maxRow,k) = temp(k);
        end
    end
    %Zero out all values in column below pivot iterating through rows
    for i = (j+1):length(A)
     %Check for need to swap pivot (will be implemented later)
        if(A(i,j) ~= 0)
            %Calculate L value and store
            L(i,j) = A(i,j)/A(j,j);
            %Perform row-wise addition to zero out values below pivot
            for k = (j):length(A)
                A(i,k) = A(i,k) - L(i,j)*A(j,k);
            end
        end
    end
end
    

U = A;
U
L
A_check = L*U
