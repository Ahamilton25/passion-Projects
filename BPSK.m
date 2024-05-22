function[output] = BPSK(input)
output = zeros(1,length(input));
for i=1:length(input)
    if (input(i) == 1)
        output(i) = 1;
    else
        output(i) = -1;
    end
end
 A1 = output(1:2:length(output));
B1 = output(2:2:length(output));

for m=1:length(output)
A1(m) = -1;
B1(m) = 1;

end
for m=1:length(output)
output(1:2:length(output)) = A1(m);
output(2:2:length(output)) = B1(m);
end

end

