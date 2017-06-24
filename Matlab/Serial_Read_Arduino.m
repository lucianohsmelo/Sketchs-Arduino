%clear all
clc
close all
s=serial('COM4','BaudRate',9600); 
fopen(s) 
x=1:100; 
n=1;
interv = 1000;
passo = 1;
t=1;
x=0;
i=1;
ax1 = -40;
ax2 = 100;
last = 0;
amostra = 0;
teste = 0;
while(t<=interv)
    tic;
    tmp=fscanf(s,'%s');
    y = str2num(tmp)
%     plot(x,'red','linewidth',2);
%     axis([ax1,ax2,0,1023]);
%     grid on
%     ax1 = ax1+1;
%     ax2 = ax2+1;
%     
%     drawnow;
%     delta = (toc - last);%Ts milisegundos
%     Hertz = 1/delta;
%     
%     teste = teste+1;
%     
    i=i+1;
    t=t+passo;
    amostra = amostra+1;
    toc;
    ts(amostra) = toc;
end
fclose(instrfind)
median(ts)
fclose(s)