function [output] = randbit(max)
output = rand(1,max)>0.5; %Produce generic vector of [0,1]
a = 0;       %variables used to count and determine distribution
b = 0;
probdf = 0;
probdf2 = 0;

a = numel(find(output ==1));  %used to return # of 1's
b = numel(find(output ==0));  %used to return # of 0's

probdf = a / max;             %verifying the distribution
probdf2 = b / max;            %verifying the distribution

while(probdf ~= probdf2)    %If it is determine that distributes are not equal
    for k =1:max                        
        if(output(k)==1) && (probdf >0.5) %replace 1s if there are more
            output(k) = 0;
           a = (a - 1);                   %recount
           b = (b + 1);
          probdf = a / max;               %recalculate distribution
          probdf2 = b / max;
        elseif(output(k)==0) &&(probdf2 >0.5)  %replace 0's if there are more
           output(k) = 1;
           b = (b - 1);                  %recount
           a = (a + 1);
           probdf = a / max;             %recalculate distribution
           probdf2 = b / max;
        end
    end

end


end
