// Simulacion ByD Manufacturing.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Operario.h"
#include <vector>
#include <string>

using namespace std;

int Probabilidades_Descompostura();
int Probabilidades_Arreglo();
string aHrMin(int);

int main()
{
	srand(time(NULL));
	int cant_empleados;
	float espera_total = 0;
	vector<Operario> lista;

	cout << "Cuantos operarios posee la empresa ";
	cin >> cant_empleados;
	for (int i = 0; i < cant_empleados; i++)
		lista.push_back(Operario(i));
	
	
	float hs_descom = 480;	//8am
	float final_arreglo=0, final_arreglo_viejo=0;
	float espera=0;

	cout << "TeD\tHdD\tTA\tFA\tEsp\tOp"<<endl;
	while (hs_descom <= 960)
	{
		int tiempo_entre_desc = Probabilidades_Descompostura();	
		hs_descom += tiempo_entre_desc;		
		float tiempo_arreglo = Probabilidades_Arreglo();
		if (hs_descom != 480)
		{
			final_arreglo_viejo = final_arreglo;
			for (int i = 0; i < cant_empleados; i++)
			{
				if (lista[i].getfinalizacion() < hs_descom)
					lista[i].setEstado(true);
			}
		}

		final_arreglo = hs_descom + tiempo_arreglo;

		bool flag = false;
		int i = 0;
		bool ocupado=false;

		while (ocupado == false && i < cant_empleados)
		{
			if (lista[i].getEstado()==false)
				i++;
			else
			{
				flag = true;
				ocupado = true;
				lista[i].setEstado(false);
				lista[i].setfinalizacion(final_arreglo);
				espera = 0;
			}
		}
		if (flag == false)
		{
			espera = final_arreglo - hs_descom;
			espera_total += espera;
			cout << tiempo_entre_desc << '\t' << aHrMin(hs_descom) << '\t' << tiempo_arreglo << '\t' << aHrMin(final_arreglo) << '\t' << espera << endl;
		}
		else
			cout<< tiempo_entre_desc << '\t' << aHrMin(hs_descom) << '\t' << tiempo_arreglo << '\t' << aHrMin(final_arreglo) << '\t' << espera << '\t' << i+1<<endl;
		//cout << tiempo_entre_desc << '\t' << hs_descom/60 << '\t' << tiempo_arreglo << '\t' << final_arreglo/60 << '\t' << espera << '\t' << i+1<<endl;
	}
	if (cant_empleados * 8 * 8 > espera_total / 60)
		cout << "Se tiene un gasto mayor al tener mas operarios, que los gastos generados por tener una maquina sin funcionar";
	else if (cant_empleados * 8 * 8 < espera_total / 60)
		cout << "Se tiene un gasto mayor teniendo maquinas sin operar, que teniendo mas operarios";
	else
		cout << "La proporcion entre gastos de empleados y de maquina sin funcionar es la misma, por lo que se esta en el punto optimo";
	system("Pause");
    return 0;
}

int Probabilidades_Descompostura()
{
	int r1 = rand() % 100 + 1;
	if (r1 >= 1 && r1<5)
		return 15;
	else if (r1 <= 14)
		return 16;
	else if (r1 <= 24)
		return 17;
	else if (r1 <= 43)
		return 18;
	else if (r1 <= 67)
		return 19;
	else if (r1 <= 85)
		return 20;
	else if (r1 <= 95)
		return 21;
	else if (r1 <= 100)
		return 22;
}

int Probabilidades_Arreglo()
{
	int r1 = rand() % 100 + 1;

	if (r1 >= 1 && r1 < 5)	//5-15
		return 5 + rand() % 10 + 1;
	else if (r1 <= 30)
		return 15 + rand() % 10 + 1;
	else if (r1 <= 70)
		return 25 + rand() % 10 + 1;
	else if (r1 <= 95)
		return 35 + rand() % 10 + 1;
	else if (r1 <= 100)
		return 45 + rand() % 10 + 1;
}

string aHrMin(int a)
{
	int sec=a*60, hr, min;
	hr = sec / (60 * 60);
	sec %= 60 * 60;
	min = sec / 60;
	sec %= 60;
	string tiempo;
	if(min<10)
		tiempo = to_string(hr) + '.' + '0'+to_string(min);
	else
		tiempo = to_string(hr) + '.' + to_string(min);
	return tiempo;
}
