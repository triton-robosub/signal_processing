clear all;
clc;
%% import csv data to matlab using data import tool
%% add noise using the wgn() function
%AWGN is used to add Gaussian white noise to a signal.
%SNR is Signal to Noise Ratio in dB
%the level of a desired signal to the level of background noise 
%plotting the ping
A = readtable('Ping Ex1.csv');
figure;
y = A{:,2};
x = A{:,1};
plot(x,y);
axis([-inf inf -0.18 0.16])
title('Channel 3 Ping - 1');
xlabel('ch3times');
ylabel('ch3valueV');
snr = 40;

%adding white noise
noiseSignal = awgn(y,snr);
plot(x, noiseSignal);

%bandpass filter
bpFilt = designfilt('bandpassfir', 'FilterOrder', 20, 'CutoffFrequency1', ...
    25000, 'CutoffFrequency2', 40000,'SampleRate', 100000000);
  
freqz(bpFilt)

filtered_data = filtfilt(bpFilt,y);
figure;
plot(x, filtered_data);