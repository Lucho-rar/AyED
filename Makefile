make:
	g++ Lista.h Nodo.h Cola.h Administrador.h Pagina.h Router.h Terminal.h Administrador.cpp Pagina.cpp Paquete.cpp Router.cpp Terminal.cpp main.cpp -o main

remove:
	rm main