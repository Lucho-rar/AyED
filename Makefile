make:
	g++ main.cpp Lista.h Nodo.h Router.h Terminal.h Pagina.h Administrador.h Paquete.h LazoDeConexion.h Direccion.h Router.cpp Terminal.cpp Pagina.cpp Administrador.cpp Paquete.cpp LazoDeConexion.cpp Direccion.cpp -o main

remove:
	rm main
