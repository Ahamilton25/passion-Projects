%Task 3: BPSK generation
symbols_task3 = randbit(12000);          %Generate random bits using "randbits"
symbols_BPSK = BPSK(symbols_task3);     %Mapping the symbols using "BPSK function"
oversampling_factor = 4;
m = oversampling_factor;

% % Code from LAB 5 to generate the transmit filter and plot:

%first specify half of the filter
hhalf = [-0.025288315;-0.034167931;-0.035752323;-0.016733702;0.021602514;
0.064938487;0.091002137;0.081894974;0.037071157;-0.021998074;-0.060716277 ;
-0.051178658;0.007874526;0.084368728;0.126869306;0.094528345;-0.012839661;
-0.143477028;-0.211829088;-0.140513128;0.094601918;0.441387140;0.785875640;
1.0];
transmit_filter = [hhalf;flipud(hhalf)];
MAGft = abs(fftshift(fft(transmit_filter)));
plot(linspace(-6,6,48),transmit_filter);
title('Transmit Filter');
xlabel('t/T','FontSize',16)
plot(linspace(-6,6,48),MAGft)

% % Configuring the transmit, receiver, and channel filters:

%Configure the transmit filter and receiver filter
receive_filter = flipud(transmit_filter);

%Trivial channel filter considering an LTI system
channel_filter =1;
received_response = conv(transmit_filter,channel_filter); %input of receiver
overall_response = conv(received_response,receive_filter); %output of receiver

%upsample for conv.
nsymbols_upsampled = 1 + (12000 - 1)*m;
symbols_upsampled = zeros(nsymbols_upsampled,1);
symbols_upsampled(1:m:nsymbols_upsampled) = symbols_BPSK; %assign symbols

%pass through receiver:
bit_receive_input = conv(symbols_upsampled,received_response); %sending signal into system
bit_receive_output = conv(bit_receive_input,receive_filter); %applying thee filter
length_trans_filt_input = length(bit_receive_input);
length_trans_filt_output = length(bit_receive_output);

figure(2);
subplot(2,1,1)
plot(bit_receive_input)
xlim([0 200])
ylim([-3 3])
title('Receiver input')
xlabel('Samples');
ylabel('Amplitude');
subplot(2,1,2)
plot(bit_receive_output)
xlim([0 200])
ylim([-6 6])
title('Receiver output')
xlabel('Samples');
ylabel('Amplitude');