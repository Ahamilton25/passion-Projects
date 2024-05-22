close all
clear all
Tf = 0.01; %time iteration factor
t = -6:Tf:6; %interval of iteration
x = signalx(t) %call to function signalx
xlabel('Time(s)');
ylabel('Signal X(t)')
title('X(t) v. Signal X(t)');
title('Time(s) v. Signal X(t)');
title('Time(s) v. Signal X(t)'); %title and axis declerations

clc;
close all;
clear all;
Tf = 0.01; %time iteration factor
t = -6:Tf:6; %interval of iteration
x = signalx(t-3); %call to function signalx
plot(t,x); %plotting generated signal versus t
xlabel('Time(s)');
ylabel('Signal X(t-3)')
title('Time(s) v. Signal X(t-3)');
title('Time(s) v. Signal X(t-3)'); %title and axis declerations
grid

clc;
close all;
clear all;
Tf = 0.01; %time iteration factor
t = -6:Tf:6; %interval of iteration
x = signalx(3-t); %call to function signalx
plot(t,x); %plotting generated signal versus t
xlabel('Time(s)');
ylabel('Signal X(3-t)')
title('Time(s) v. Signal X(3-t)');
title('Time(s) v. Signal X(3-t)'); %title and axis declerations
grid

clc
close all;
clear all;
Tf = 0.01; %time iteration factor
t = -6:Tf:6; %interval of iteration
x = signalx(2t); %call to function signalx
x = signalx(2*t); %call to function signalx

clc
close all;
clear all;
Tf = 0.01; %time iteration factor
t = -6:Tf:6; %interval of iteration
x = signalx(2*t); %call to function signalx
plot(t,x); %plotting generated signal versus t
xlabel('Time(s)');
ylabel('Signal X(2t)')
title('Time(s) v. Signal X(2t)');
title('Time(s) v. Signal X(2t)'); %title and axis declerations
grid
clc
close all
clear all