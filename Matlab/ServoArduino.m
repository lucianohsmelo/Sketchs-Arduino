 clear all;
% clc;
a = arduino('COM3');
a.servoAttach(6)
a.servoAttach(5)
clear read 

x = 180
while x < 181
x = input('Angulo_2: ');
y = input('Angulo_3: ');
read_x = a.servoRead(6)
if read_x < x
    for i = read_x:x    
    a.servoWrite(6,i);
    pause(0.01)
    i
    end
end

if read_x > x
    for i = read_x:-1:x
        a.servoWrite(6,i);
        pause(0.01) 
        i
    end 
read_x = a.servoRead(6)
end
read_y = a.servoRead(5)
if read_y < x
    for i = read_y:x    
    a.servoWrite(5,i);
    pause(0.01)
    i
    end
end

if read_y > x
    for i = read_y:-1:x
        a.servoWrite(5,i);
        pause(0.01) 
        i
    end 
read_y = a.servoRead(5)
end
end












