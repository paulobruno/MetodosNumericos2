figure;

a = ezplot("e^(0.25*x^4-1.5*x)",[0,2])
set(a,"linewidth",2)
set(a,"color","k")

grid on
hold on
teuler = [0, 0.5, 1.0, 1.5, 2.0]
yeuler = [1, 0.25, 0.078125, 0.05859375, 0.113525390625]
euler = plot(teuler, yeuler)
set(euler,"linewidth",2)
set(euler,"color","y")

hold on
trk2 = [0, 0.5, 1.0, 1.5, 2.0]
yrk2 = [1, 0.5390625, 0.332702636718750, 0.408080577850342, 1.884184543043375]
rk2 = plot(trk2, yrk2, "r-")
set(rk2, "linewidth", 2)

hold on	
trk3 = [0, 0.5, 1.0, 1.5, 2.0]
yrk3 = [1, 0.471537272135417, 0.287045628246334, 0.386868034732633, 2.379239987775757]
rk3 = plot(trk3, yrk3, "g-")
set(rk3, "linewidth", 2)

hold on
trk4 = [0, 0.5, 1.0, 1.5, 2.0]
yrk4 = [1, 0.507228982137882, 0.313596284036293, 0.397093330527178, 2.174904807838987]
rk4 = plot(trk4, yrk4, "b-")
set(rk4, "linewidth", 2)

hold on
tpc3 = [0, 0.5, 1.0, 1.5, 2.0]
ypc3 = [1, 0.507228982137882, 0.313596284036293, 0.413746206335784, 2.190701164845732]
pc3 = plot(tpc3, ypc3, "c-")
set(pc3, "linewidth", 2)

hold on
tpc4 = [0, 0.5, 1.0, 1.5, 2.0]
ypc4 = [1, 0.507228982137882, 0.313596284036293, 0.397093330527178, 2.139776467486892]
pc4 = plot(tpc4, ypc4, "m-")
set(pc4, "linewidth", 2)

legend('solucao analitica','Forward Euler', 'RK2', 'RK3', 'RK4', 'PC3', 'PC4');
