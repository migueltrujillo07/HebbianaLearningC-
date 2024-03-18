#include "hebbiana.h"

int main()
{
	//Indicar el tamaño de la matriz de entrada x
	int ne = 2;

	NeuronaHebbiana nh(ne);
	nh.ingresoValores();
	nh.visualizar();
	nh.Entrenar();
	printf("El resultado del entrenamiento es:\n");
	nh.Imprimir();

	////Evaluando el entrenamiento
	printf("\n\nEvaluando el resultado:\n\n");
	nh.Evaluar();
	return 0;
}
