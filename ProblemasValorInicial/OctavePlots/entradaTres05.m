figure;

a = ezplot("(1/4)*(2*t^2-2*t+3*e^(-2*t)+1)",[0,2])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 0.5, 1.0, 1.5, 2.0]
yeuler = [1, 0, 0.125, 0.5, 1.125]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 0.5, 1.0, 1.5, 2.0]
yrk2 = [1, 0.5625, 0.53125, 0.828125, 1.4140625]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 0.5, 1.0, 1.5, 2.0]
yrk3 = [1, 0.364583333333333, 0.319444444444444, 0.637731481481482, 1.243827160493827]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 0.5, 1.0, 1.5, 2.0]
yrk4 = [1, 0.465856481481481, 0.414697466563786, 0.713851224029778, 1.306195202938747]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 0.5, 1.0, 1.5, 2.0]
ypc3 = [1, 0.465856481481481, 0.414697466563786, 0.712052766078675, 1.293669577894466]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 0.5, 1.0, 1.5, 2.0]
ypc4 = [1, 0.465856481481481, 0.414697466563786, 0.713851224029778, 1.271416028486013]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
