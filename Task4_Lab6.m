%Task 4: Adding Gaussian white noise:
SNRdB = 10;                                            %chosen value for SNR
% % Determining the value of No, Eb, and Es given SNR
g_T = conv(transmit_filter,channel_filter);
a  = (g_T)'*(g_T);                                      %[gt*gc]^2
Es = 1*a;                                               %Energy per symbol for BPSK
Eb = Es/1;                                              %Energy per bit for BPSK
N_o = Eb / SNR;

variance = (N_o/2);                                 %covariancedB;
standard_dev = sqrt(variance);                                 %std. deviation

N = (0 + variance.*randn(1,1000));                      %create Noise vector

oversampfact = 4;                                       %T/4
ts = 1/oversampfact;

% % Upsample the noise vector for receiver filter:
nsamples_noise = ceil(1/ts);                 
nsymbols_noise = 1000;
nsymbols_upsampled_noise = 1 + (nsymbols_noise - 1)*nsamples_noise;
symbols_upsampled_noise = zeros(nsymbols_upsampled_noise,1);
symbols_upsampled_noise(1:nsamples_noise:nsymbols_upsampled_noise) = N;

% %Pass the signal through the filter:
receive_noise = conv(symbols_upsampled_noise,received_response); %sending signal into system
receive_output_noise = conv(receive_noise,receive_filter); %applying thee filter

%Capture the noise vector and add it receiver input
interval = zeros(48091,1);
interval(1:1:length(receive_output_noise)) = receive_output_noise;

%Adding the noise to the output
total_noise = bit_receive_output + interval;

%Plotting the resulting vector w/ added noise
figure(5)
plot(total_noise)
xlim([0 5000])

%Plotting the input/output noise after filter:
figure(4)
subplot(2,1,1);
plot(receive_noise)
xlabel('Samples')
ylabel('Amplitude')
title('Noise Input')
subplot(2,1,2)
plot(receive_output_noise)
title('Noise Output')
plot(N)  %display noise 