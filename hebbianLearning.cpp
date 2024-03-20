#include "hebbiana.h"

int main()
{
	//Indicar el tamaño de la matriz de entrada x
	int ne = 2;

	//Creacion de la clase Neurona Hebbiana
	NeuronaHebbiana<int> nh(ne);
	nh.ingresoValores();
	nh.visualizar();
	nh.Entrenar();
	printf("El resultado del entrenamiento es (Hebbiana):\n");
	nh.Imprimir();

	////Evaluando el entrenamiento Hebbiana
	printf("\n\nEvaluando el resultado (Hebbiana): \n\n");
	nh.Evaluar();


	//Creacion de la neurona Perceptron
	NeuronaPerceptron<int> Np(ne);
	Np.ingresoValores();
	Np.visualizar();
	Np.Entrenar();
	printf("El resultado del entrenamiento es (Perceptron) :\n");
	Np.Imprimir();

	////Evaluando el entrenamiento Perceptron
	printf("\n\nEvaluando el resultado (Perceptron):\n\n");
	Np.Evaluar();

	return 0;
}
