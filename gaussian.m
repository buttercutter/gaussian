x = dlmread('results.txt');

figure (1);
hist(x,100,1);
title ("histogram in time domain");

figure (2);
f=plot(20*log10(abs(fft(x)).^2));
title ("power spectrum in frequency domain");

waitfor(f)

%http://www.ni.com/white-paper/4278/en/

