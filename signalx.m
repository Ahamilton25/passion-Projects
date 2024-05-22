function x = signalx(t) %Begin of signalx function
  for i = 1:length(t)  %Beginning of for statement to iterate the vector set%
 
      if t(i)>=-3 && t(i)<=-1 %First parameter%
         x(i) = 2*exp(t(i)+2);  %End of first sig parameters%
    
      elseif t(i)>=-1 && t(i)<=4 %Begin of second param%
          x(i) = 2*exp(-t(i))*cos(2*pi*t(i)); %end of second param%
     
      else  %any value outside range%
         x(i) = 0;
     end
  end 

end   %End of function signalx