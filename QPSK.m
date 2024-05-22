function[output] = QPSK(input1,input2)
output = zeros(1,length(input1));
for i=1:length(input1)
    if (input1(i) == 0) && (input2(i)== 0)
        output(i) = (-1-1i);
    elseif (input1(i) ==0) && (input2(i) ==1)
        output(i) = (-1+1i);
    elseif (input1(i) ==1) && (input2(i)==0) 
            output(i) = (1-1i);
    elseif (input1(i) ==1) && (input2(i)==1) 
        output(i) = (1+1i);

    end
end
output_order = zeros(1,length(output));
A1 = output(1:4:length(output));
B1 = output(2:4:length(output));
C1=  output(3:4:length(output));
D1 = output(4:4:length(output));

for k =1:length(A1)
    A1(k) = (-1-1i);
    B1(k) = (-1+1i);
    C1(k) = (1-1i);
    D1(k) = (1+1i);
end
for m=1:length(output)
output(1:4:length(output)) = A1;
output(2:4:length(output)) = B1;
output(3:4:length(output)) = C1;
output(4:4:length(output)) = D1;
end
end
