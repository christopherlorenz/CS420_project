clear all;
close all;
clc;

A = [1 1 1 1;
     2 3 5 8;
     4 6 8 12
     6 8 10 22];
 
v = ones(1,length(A));
L = diag(v);
U = zeros(length(A),length(A));
 
%Iterate through columns
for j = 1:length(A)
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
