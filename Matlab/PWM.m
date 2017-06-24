close all
clear all
clc

fc = 60*10;
L = input('Valor do Indutor (mH): ')
fc = 1/2*pi*sqrt(L*10^-3*C)
C