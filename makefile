program:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/IkiliAgacDugumu.cpp -o ./lib/IkiliAgacDugumu.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/AgacYoneticisi.cpp -o ./lib/AgacYoneticisi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/IkiliAgacDugumu.o ./lib/Dugum.o ./lib/Kuyruk.o ./lib/AgacYoneticisi.o ./lib/main.o -o ./bin/main.exe
calistir:
	./bin/main.exe