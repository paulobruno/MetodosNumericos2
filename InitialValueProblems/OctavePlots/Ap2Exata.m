figure;

a = ezplot("(1/4)*(2*(t^2)+2*t+5*e^(2*t)-1)",[0,1])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
