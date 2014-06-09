figure;

a = ezplot("(1/4)*(2*(t^2)+2*t+5*e^(2*t)-1)",[0,1])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on

teuler = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
yeuler = [1.0, 1.3, 1.659, 2.0868, 2.59516, 3.198192000000001, 3.912830400000001, 4.759396480000001, 5.762275776000002, 6.950730931200003, 8.359877117440004]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","r")

legend('Exata','Forward Euler')
