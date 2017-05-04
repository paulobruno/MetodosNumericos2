figure;

a = ezplot("(1/4)*(2*t^2-2*t+3*e^(-2*t)+1)",[0,2])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 1.0, 2.0]
yeuler = [1, -1, 2]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 1.0, 2.0]
yrk2 = [1, 1.5, 3]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 1.0, 2.0]
yrk3 = [1, -0.166666666666667, 1.222222222222222]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 1.0, 2.0]
yrk4 = [1, 0.796296296296296, 1.683127572016461]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 1.0, 2.0]
ypc3 = [1, 0.796296296296296, 1.683127572016461]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 1.0, 2.0]
ypc4 = [1, 0.796296296296296, 1.683127572016461]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
