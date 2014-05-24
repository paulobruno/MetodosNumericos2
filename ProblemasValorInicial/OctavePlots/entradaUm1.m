figure;

a = ezplot("e^(0.25*x^4-1.5*x)",[0,2])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 1.0, 2.0]
yeuler = [1, -0.5, -0.25]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 1.0, 2.0]
yrk2 = [1, 0.375, 0.890625]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 1.0, 2.0]
yrk3 = [1, 0.369791666666667, 2.413275824652778]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 1.0, 2.0]
yrk4 = [1, 0.427365540695016, 2.146220190549039]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 1.0, 2.0]
ypc3 = [1, 0.427365540695016, 2.146220190549039]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 1.0, 2.0]
ypc4 = [1, 0.427365540695016, 2.146220190549039]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
