clc;
clear all
a = arduino('COM4');
close all;
clear amostra;
interv = 1000;
passo = 1;
t=0;
i=1;
ax1 = -50;  
ax2 = 70;
amostra = 0;
teste = 0;
 b = 0;
 x1 = -40;
 x2 = 20;
 read(1) = 0;
 for i = 1:interv
     tic;
     read(i) = a.analogRead(0);
     plot(read,'red','linewidth',2);% plot do gráfico
     grid on;
     title('Dados')% título do gráfico
     axis([0,1000,0,1023]);
     x1 = x1 + 1;
     x2 = x2 + 1;
     drawnow;% não gera outra figura
     toc;
     ts(i) = toc;
     read(i) = ts(i);%random('unif',0,1023);
 end
median(ts)
delete(a)