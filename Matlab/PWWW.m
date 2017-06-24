clear all
close all
clc

fc = 60*10;
L = input('Digite o valor de L(mH): ');
C = 1/((2*pi*fc)^2*L*10^-3)
