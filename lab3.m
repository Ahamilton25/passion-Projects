%Lab 3 AM Signals 
%Task 1:
close all
clear all
m = 40;
Ts = 0.001;
time_p = 0:1/m:1; %sampling times over duration of pulse
p = sin(pi*time_p); %samples of the pulse
ns = 1000;
x = randn(1,ns); %creating array of random sample points
y = [];
for i = 1:length(x) %Assign the symbols to each instance
    if x(i) >= 0
        y = [y 1];
    else
        y = [y -1];
    end
end
symbols = y;
%step 2: Upsample by m
nsymbols = length(symbols);%length of original symbol sequence
nsymbols_upsampled = 1+(nsymbols-1)*m;%length of upsampled symbol sequence
symbols_upsampled = zeros(nsymbols_upsampled,1);%
symbols_upsampled(1:m:nsymbols_upsampled)=symbols;%insert symbols with spacing 
% step 3: Discrete conv. of signal
u = conv(symbols_upsampled,p).'; %transpose the matrix returning the nonconjugating transpose
%step4: plot signal to verify
time_u = 0:(1/m):(length(u)-1)/m;
figure(1);
plot(time_u,u);
xlim([0 10]);
%step5: Fourier Trans
[X,f,df] = contFT(u,time_p(1),(Ts/m),1);
figure(2);
plot(f, (abs(X).^2/(ns*Ts)))
 
%Task 2: Rerun task 1 3 more times

%Task 3:

%Using Run 4 from part 2
fc = 10/Ts;
t = 0:Ts/m:ns*Ts; %producing a time interval the same size as timeu
signalu = u.*cos(2*pi*fc*t); %create the signal ut = m(t)cos(2pi*fc*t)

figure(9);
plot(time_u,signalu) %plot the signal ut over the conv. time interval
xlim([0 4]) %focus on 4 occurrences of the symbol


%Task 4

%Re-use code for Task 1,2,3 and 4
[Xu,fu,dfu] = contFT(signalu,time_p(1),(Ts/m),1);
figure();
plot(fu, (abs(Xu).^2/(ns*Ts)))
 

%Task 5 Redo plots

m = 40; %Task 1 
Ts = 0.001;
time_p = 0:1/m:1; %sampling times over duration of pulse
p = sin(pi*time_p); %samples of the pulse
ns = 1000;
x = randn(1,ns); %creating array of random sample points
y = [];
for i = 1:length(x) %Assign the symbols to each instance
    if x(i) >= 0
        y = [y 1];
    else
        y = [y -1];
    end
end
symbols = y;

%step 2: Upsample by m
nsymbols = length(symbols);%length of original symbol sequence
nsymbols_upsampled = 1+(nsymbols-1)*m;%length of upsampled symbol sequence
symbols_upsampled = zeros(nsymbols_upsampled,1);%
symbols_upsampled(1:m:nsymbols_upsampled)=symbols;
%insert symbols with spacing 

% step 3: Discrete conv. of signal
u = conv(symbols_upsampled,p).'; %transpose the matrix returning the nonconjugating transpose

%step4: plot signal to verify
time_u = 0:(1/m):(length(u)-1)/m;

fc = 10/Ts; %Task 3
t = 0:Ts/m:ns*Ts; %producing a time interval the same size as timeu
Ac = 1;

for i =1:length(u)
    signalu(i) = (Ac + u(i)).*cos(2*pi*fc*t(i));
end

figure();
plot(time_u,signalu) %plot the signal ut over the conv. time interval
xlim([0 4])

[Xu,fu,dfu] = contFT(signalu,time_p(1),(Ts/m),1); %Task4
figure();
plot(fu, (abs(Xu).^2/(ns*Ts)))


%Task 6:

                                %a) Pass the signal through diode filter
uplus = zeros(1,length(t));
for i =1:length(t)
if signalu(i) < 0
    uplus(i) = 0;
else 
    uplus(i) = signalu(i);
end
end
                                    
                                 %b) Establish RC const. and h for conv.
RC = 0.0004;
h = exp(-1*t/(RC));
uRC = contconv1(uplus,h,t(1),t(1),Ts/m);
plot(uRC )
                          
                                  %c) DC Block
%The mean value is shown in the data sheet of the plot
uRC_new = uRC - (5.08e-5); %In this case the mean was 5.08E-5

%7
uRC_new = uRC - (3.196E-6); %case 0.4E-7

uRC_new = uRC - (0.1275); %case 0.1275