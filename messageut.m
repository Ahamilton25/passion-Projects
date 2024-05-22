function [ut,t] = messageut(mm, t1, t2, dt, cc)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
t = t1:dt:t2;
ut = size(t);
for n = 1:length(t)
    if (t <= t2)
        ut(n) = mm(n)*cc(n);
    else 
        ut = t1;
    end
end
end