CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o Prostopadloscian.o Graniastoslup6.o uklad_wsp.o dron.o Powierzchnia.o plaskowyz.o wzgorze.o plaskowyz_prostopadl.o scena.o
	g++ -o example.out example.o Dr3D_gnuplot_api.o Prostopadloscian.o Graniastoslup6.o uklad_wsp.o dron.o Powierzchnia.o plaskowyz.o wzgorze.o plaskowyz_prostopadl.o scena.o -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

Prostopadloscian.o: Prostopadloscian.cpp Prostopadloscian.hh
	g++ ${CPPFLAGS} -o Prostopadloscian.o Prostopadloscian.cpp

Graniastoslup6.o: Graniastoslup6.cpp Graniastoslup6.hh
	g++ ${CPPFLAGS} -o Graniastoslup6.o Graniastoslup6.cpp

uklad_wsp.o: uklad_wsp.cpp uklad_wsp.hh
	g++ ${CPPFLAGS} -o uklad_wsp.o uklad_wsp.cpp 

dron.o: dron.cpp dron.hh
	g++ ${CPPFLAGS} -o dron.o dron.cpp

Powierzchnia.o: Powierzchnia.cpp Powierzchnia.hh
	g++ ${CPPFLAGS} -o Powierzchnia.o Powierzchnia.cpp

plaskowyz.o: plaskowyz.cpp plaskowyz.hh
	g++ ${CPPFLAGS} -o plaskowyz.o plaskowyz.cpp

wzgorze.o: wzgorze.cpp wzgorze.hh
	g++ ${CPPFLAGS} -o wzgorze.o wzgorze.cpp

plaskowyz_prostopadl.o: plaskowyz_prostopadl.cpp plaskowyz_prostopadl.hh
	g++ ${CPPFLAGS} -o plaskowyz_prostopadl.o plaskowyz_prostopadl.cpp

scena.o: scena.cpp scena.hh
	g++ ${CPPFLAGS} -o scena.o scena.cpp

clear:
	rm example.out example.o Dr3D_gnuplot_api.o Graniastoslup6.o Prostopadloscian.o uklad_wsp.o dron.o Powierzchnia.o plaskowyz.o wzgorze.o plaskowyz_prostopadl.o scena.o
