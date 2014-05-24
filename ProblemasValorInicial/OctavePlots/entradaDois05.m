figure;

a = ezplot("(1/4)*((2*t^2+t+2)^2)",[0,1])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 0.5, 1.0]
yeuler = [1, 1.5, 3.337117307087384]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 0.5, 1.0]
yrk2 = [1, 2.168558653543692, 5.888309007569514]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 0.5, 1.0]
yrk3 = [1, 2.242215925453816, 6.190910628691463]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 0.5, 1.0]
yrk4 = [1, 2.195896934397212, 6.01330555893985]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 0.5, 1.0]
ypc3 = [1, 2.195896934397212, 6.01330555893985]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 0.5, 1.0]
ypc4 = [1, 2.195896934397212, 6.01330555893985]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
