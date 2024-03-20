template <typename T2>
class NeuronaPerceptron
{
private:
	int ne;//Número de entradas
	int np;//Número de patrones
	int n = 100; //Número de épocas
	int I;	//Sumatoria
	int yi;	//Salida
	int E;	//Error
	int** x;//Matriz para la entrada
	int* y; //matriz de salida
	int* w; //Matriz de pesos
	int theta; //Tetha
	T2 beta;	//beta

public:
	NeuronaPerceptron(int a);
	~NeuronaPerceptron();
	void ingresoValores();
	void visualizar();
	void Entrenar();
	void Evaluar();
	void Imprimir();

};

template class NeuronaHebbiana<int>;
template class NeuronaHebbiana<float>;
template class NeuronaHebbiana<double>;

template class NeuronaPerceptron<int>;
template class NeuronaPerceptron<float>;
template class NeuronaPerceptron<double>;
