function BPSK[output] = BPSKMAP(symbol_in)
i = 0;
output = zeros(size(symbols_in));
for i=1:size(symbols_in)
    if symbols_in(i) = 1
        output(i) = 1;
    else
        symbols_in(i) = -1;
    end
end

