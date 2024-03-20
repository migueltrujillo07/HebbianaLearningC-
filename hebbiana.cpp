#include "hebbiana.h"

//Inicialización de la clase Neurona Hebbiana
template <class T1>
NeuronaHebbiana<T1>::NeuronaHebbiana(int a)
{
    printf("-Neurona Hebbiana- \n");
    b = 1;
    ne = a;
    np = 1 << a;

    //Asignar espacio de memoria
    x = (int**)malloc(np * sizeof(int*));

    for (int i = 0; i < np; i++)
    {
        x[i] = (int*)malloc(ne * sizeof(int));
    }

    //Asignar Espacio de Memoria
    y = (int*)malloc(np * sizeof(int));

    // Inicializar salidas con 1
    for (int i = 0; i < np; ++i) 
        y[i] = 1;

    // Asignar memoria para los pesos
    w = (int*)malloc(ne * sizeof(int));

    // Inicializar los pesos con ceros
    for (int i = 0; i < ne; ++i) 
        w[i] = 0;
}
template<class T1>
NeuronaHebbiana<T1>::~NeuronaHebbiana()
{
    for (int i = 0; i < np; ++i)
    {
        free(x[i]);
    }
    free(x);

    free(y);
    free(w);
}

template<class T1>
void NeuronaHebbiana<T1>::ingresoValores()
{
    cout << "Ingrese los elementos de la entrada: " << endl;
    for (int i = 0; i < np; ++i)
    {
        for (int j = 0; j < ne; ++j)
        {
            cout << "Ingrese el valor de la posicion: (" << i + 1 << ", " << j + 1 << "): ";
            cin >> x[i][j];
        }
    }

    cout << "Ingrese los elementos de la salida (y): " << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "Ingrese el valor de la posicion " << i + 1 << ": ";
        cin >> y[i];
    }
}

template<class T1>
void NeuronaHebbiana<T1>::visualizar() {
    cout << "Entradas:" << endl;
    for (int j = 0; j < ne; ++j) {
        cout << "X" << j + 1 << endl;
        for (int i = 0; i < np; ++i)
            cout << x[i][j] << endl;
    }

    cout << "Salida: " << endl;
    for (int i = 0; i < np; i++)
        cout << y[i] << endl;
    cout << "\n";
}

template<class T1>
void NeuronaHebbiana<T1>::Entrenar()
{
    for (int k = 1; k < n; k++)
    {
        printf("Entrenando la epoca no. %d\n", k);
        ////Se realiza el entrenamiento para 1 época
        for (int i = 0; i < np; i++)//Controla el # de patrón
        {
            for (int j = 0; j < ne; j++)//Controla el # de entrada
                w[j] += y[i] * x[i][j];
            b += y[i];
        }
        ////Se evalúa el resultado
        E = 0;
        for (int i = 0; i < np; i++)
        {
            I = b;
            for (int j = 0; j < ne; j++)
                I += x[i][j] * w[j];
            ys = (I >= 0) ? 1 : -1;
            E += (ys == y[i]) ? 0 : 1;
        }
        if (E == 0) break;
    }
}

template<class T1>
void NeuronaHebbiana<T1>::Evaluar()
{
    for (int i = 0; i < ne; i++)
    {
        cout << "X" << i << "\t";
        if (i == ne - 1)
        {
            cout << "y" << endl;
        }
    }
        
	
	for (int i = 0; i < np; i++)
	{
		I = b;
		for (int j = 0; j < ne; j++)
			I += x[i][j] * w[j];
		ys = (I >= 0) ? 1 : -1;
		printf("%d\t%d\t%d\n", x[i][0], x[i][1], ys);
	}

}

template<class T1>
void NeuronaHebbiana<T1>::Imprimir()
{
    for (int i = 0; i < ne; i++)
        printf("W%d = %d\n", i, w[i]);
    printf("b = %d\n", b);
}
