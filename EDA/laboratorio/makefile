todo: main

main: main.o editor.o linea.o texto.o diccionario.o
	g++ -Wall -o main main.o editor.o linea.o texto.o diccionario.o

main.o: main.cpp editor/editor.h definiciones.h
	g++ -Wall -c main.cpp -o main.o

editor.o: editor/editor.cpp editor/editor.h linea/linea.h texto/texto.h definiciones.h
	g++ -Wall -c editor/editor.cpp -o editor.o

linea.o: linea/linea.cpp linea/linea.h definiciones.h
	g++ -Wall -c linea/linea.cpp -o linea.o

texto.o: texto/texto.cpp texto/texto.h linea/linea.h definiciones.h
	g++ -Wall -c texto/texto.cpp -o texto.o

diccionario.o: diccionario/diccionario.cpp diccionario/diccionario.h definiciones.h
	g++ -Wall -c diccionario/diccionario.cpp -o diccionario.o

clean:
	rm -f main *.o




# todo: main.o editor.o
#	g++ -Wall -o main main.o editor.o
#main.o: main.c
#	g++ -Wall -c main.c
#editor.o: editor.h editor.c
#	g++ -Wall -c editor/editor.c
# se deben agregar aca las reglas de compilacion para los modulos que agreguen
# agregar tambien las dependencias en la regla todo:
# clean:
#	rm -f main
#	rm -f *.o