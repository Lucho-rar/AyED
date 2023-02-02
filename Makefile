make:
	g++ main.cpp Lista.h Nodo.h SistemaEmpaquetado.h Router.h Terminal.h Pagina.h Administrador.h Paquete.h LazoDeConexion.h Direccion.h Router.cpp Terminal.cpp Pagina.cpp Administrador.cpp Paquete.cpp LazoDeConexion.cpp SistemaEmpaquetado.cpp Direccion.cpp -o main

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem main.cpp Lista.h Nodo.h SistemaEmpaquetado.h Router.h Terminal.h Pagina.h Administrador.h Paquete.h LazoDeConexion.h  Router.cpp Terminal.cpp Pagina.cpp Administrador.cpp Paquete.cpp LazoDeConexion.cpp SistemaEmpaquetado.cpp
remove:
	rm main