function [y,t] = contconv(x1, x2, s1(1), s2(1), dt)
     outp1 = conv(x1, x2); %convolve x1 and x2
     y = outp1*dt;
     t = ystart:dt:ystart+dt*(length(y)-1);
end
