#include <iostream>
using namespace std;

class NeuronaHebbiana
{
private:
	int ne;//Número de entradas
	int np;//Número de patrones
	int n = 10; //Número de épocas
	int I;	//Sumatoria
	int ys;	//Salida
	int E;	//Error
	int** x;//Matriz para la entrada
	int* y; //matriz de salida
	int* w; //Matriz de pesos
	int b;	//bias y su valor inicial

public:
	NeuronaHebbiana(int a);
	~NeuronaHebbiana();
	void ingresoValores();
	void visualizar();
	void Entrenar();
	void Evaluar();
	void Imprimir();
};
