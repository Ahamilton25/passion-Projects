function [mt,t] = messagesig(t1, t2, dt)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
t = t1:dt:t2;
m = sinc(100*t);
s = length(t);
for n = 1:length(t)
    if (t <= t2)
        mt = m;
    else 
        mt = t1;
    end
end
end

