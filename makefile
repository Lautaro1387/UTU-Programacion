push:

	git add .
	git commit -m "Add exercises"
	git push

run:

	g++ -c funciones.cpp
	g++ -c main.cpp
	g++ funciones.o main.o -o prog
	./prog