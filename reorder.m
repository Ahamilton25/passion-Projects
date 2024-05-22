function [output_order] = reorder(input)
output_order = zeros(1,length(input));
A1 = input(1:4:length(input));
B1 = input(2:4:length(input));
C1=  input(3:4:length(input));
D1 = input(4:4:length(input));

for k =1:length(A1)
    A1(k) = (-1-1i);
    B1(k) = (-1+1i);
    C1(k) = (1-1i);
    D1(k) = (1+1i);
end
for m=1:length(input)
output_order(1:4:length(input)) = A1;
output_order(2:4:length(input)) = B1;
output_order(3:4:length(input)) = C1;
output_order(4:4:length(input)) = D1;
end
end

