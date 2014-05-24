figure;

a = ezplot("(1/4)*((2*t^2+t+2)^2)",[0,1])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 0.25, 0.5, 0.75, 1.0]
yeuler = [1, 1.25, 1.809016994374947, 2.817764762320883, 4.496384660427921]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 0.25, 0.5, 0.75, 1.0]
yrk2 = [1, 1.404508497187474, 2.230729652102204, 3.706089095012849, 6.151784984030406]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 0.25, 0.5, 0.75, 1.0]
yrk3 = [1, 1.410429996573102, 2.249488708370717, 3.750936205532208, 6.242363534197566]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 0.25, 0.5, 0.75, 1.0]
yrk4 = [1, 1.405312835760820, 2.234280513837945, 3.717626538568854, 6.179788266554683]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 0.25, 0.5, 0.75, 1.0]
ypc3 = [1, 1.405312835760820, 2.234280513837945, 3.733394524180111, 6.223818723362546]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 0.25, 0.5, 0.75, 1.0]
ypc4 = [1, 1.405312835760820, 2.234280513837945, 3.717626538568854, 6.202400868427327]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
