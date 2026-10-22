todo: main

main: main.o editor.o linea.o texto.o diccionario.o
	g++ -Wall -o main main.o editor.o linea.o texto.o diccionario.o

main.o: main.c editor/editor.h definiciones.h
	g++ -Wall -c main.c -o main.o

editor.o: editor/editor.c editor/editor.h linea/linea.h texto/texto.h definiciones.h
	g++ -Wall -c editor/editor.c -o editor.o

linea.o: linea/linea.c linea/linea.h definiciones.h
	g++ -Wall -c linea/linea.c -o linea.o

texto.o: texto/texto.c texto/texto.h linea/linea.h definiciones.h
	g++ -Wall -c texto/texto.c -o texto.o

diccionario.o: diccionario/diccionario.c diccionario/diccionario.h definiciones.h
	g++ -Wall -c diccionario/diccionario.c -o diccionario.o

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