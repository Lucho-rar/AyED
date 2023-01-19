make:
	g++ main.cpp Lista.h Nodo.h Router.h Terminal.h Pagina.h Router.cpp Terminal.cpp Pagina.cpp -o main

remove:
	rm main