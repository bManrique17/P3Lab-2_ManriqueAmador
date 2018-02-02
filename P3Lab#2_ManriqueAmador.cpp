#include <iostream>
#include <string>
#include <stdlib.h> 
#include <math.h>

using namespace std;

int menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
bool serTriangular(int);
int triangularMenor(int);
double calcularAngulo(double,double,double);
double calcularArea(double,double,double);
bool serTTRectangulo(double,double,double);
long factorial(long);
void serieCatalana(long);

#define PI 3.14159265

int main(){
	char respuesta = ' ';
	do{
		switch(menu()){
			case 1:
				ejercicio1();
			break;
			case 2:
				ejercicio2();
			break;
			case 3:
				ejercicio3();
			break;
			default:
				cout<<"Invalido"<<endl;
			break;
		}
		cout<<"Desea ejecutar de nuevo [S/N]"<<endl;
		cin>>respuesta;
	}while(respuesta=='s' || respuesta=='S');	
}

int menu(){
	int retorno;
	cout<<"    \nMENU"<<endl;
	cout<<"(1)Ejercicio 1"<<endl<<
		"(2)Ejercicio 2"<<endl<<
		"(3)Ejercicio 3"<<endl<<
		"->Ingrese su opcion: ";
	cin>>retorno;
	return retorno;
}

void ejercicio1(){
	int opcion = 0;
	cout<<"  **Ejercicio1"<<endl;
	cout<<"->Ingrese el inciso a revisar(1,2 o 3): ";
	cin>>opcion;
	switch(opcion){
		case 1:{
			cout<<"\nPrimera parte"<<endl;
			cout<<"Ingrese el numero a evaluar si es triangular: ";
			int aEvaluar;
			cin>>aEvaluar;
			if(serTriangular(aEvaluar)){
				cout<<aEvaluar<<" si es triangular"<<endl;
			}else{
				cout<<aEvaluar<<" no es triangular"<<endl;
			}
	      	}			
		break;
		case 2:{
			cout<<"\nSegunda parte"<<endl;
	       		int random = 0;
			random = rand() % 1000 + 1;
			cout<<"El aleatorio escogido es: "<<random<<endl;
			if(serTriangular(random)){
				cout<<random<<" si es triangular"<<endl;
			}else{
				cout<<random<<" no es triangular"<<endl;
			}
		 }
		break;
		case 3:{
			cout<<"\nTercera parte"<<endl;
			int aEvaluar = 0;
			cout<<"Ingrese el numero a evaluar: ";
			cin>>aEvaluar;
			cout<<"El triangular mas cercano a "<<aEvaluar<<" es: "<<triangularMenor(aEvaluar)<<endl;
		}
		break;
		default:{
			cout<<"Invalido"<<endl;
		}
		break;
	}
}

bool serTriangular(int numero){
	int temp;
	int acum = 1;
	do{
		temp = 0;
		for(int i = 1; i<= acum; i++){
			temp+=i;
		}
		if(temp == numero)
			return true;
		else{
			if(acum>numero)
				return false;
			else
				acum++;
		}
	}while(true);
}

int triangularMenor(int valor){
	int temp = 0;
	int acum = 1;
	bool bandera = true;
	int triangularPrevio, triangularActual;
	do{
		temp = 0;
		for(int i = 1; i<=acum; i++){
			temp+=i;	
		}
		triangularPrevio = triangularActual;
		triangularActual = temp;		
		acum++;
	}while(triangularActual<=valor);
	return triangularPrevio;
}

void ejercicio2(){
	double lado1,lado2,lado3;
	cout<<"  **Ejercicio 2"<<endl;
	cout<<"Ingrese lado 1: ";
	cin>>lado1;
	cout<<"Ingrese lado 2: ";
	cin>>lado2;
	cout<<"Ingrese lado 3: ";
	cin>>lado3;
	if(lado1<1 || lado2<1 || lado3<1){
		cout<<"No es un triangulo"<<endl;
	}else{
		if(serTTRectangulo(lado1,lado2,lado3))
			cout<<"EL triangulo formado si es rectangulo"<<endl;
		else
			cout<<"El triangulo formado no es rectangulo"<<endl;

		cout<<"Primer angulo: "<<calcularAngulo(lado1,lado2,lado3)<<endl;
		cout<<"Segundo angulo: "<<calcularAngulo(lado2,lado1,lado3)<<endl;
		cout<<"Tercer angulo: "<<calcularAngulo(lado3,lado1,lado2)<<endl;
		
		cout<<"El area es: "<<calcularArea(lado1,lado2,lado3)<<endl;
	}
}

double calcularAngulo(double lado1,double lado2,double lado3){
	return ( acos((-lado1*lado1 + lado2*lado2 + lado3*lado3)/(2*lado2*lado3)) )*(180.0/PI);
}

double calcularArea(double lado1,double lado2,double lado3){
	double semiP = (lado1+lado2+lado3)/2;
	return sqrt( ( semiP * (semiP-lado1) * (semiP-lado2) * (semiP-lado3)) );

}


bool serTTRectangulo(double lado1, double lado2, double lado3){
	if(lado1*lado1 + lado2*lado2 == lado3*lado3)
		return true;
	else
		if(lado2*lado2 + lado3*lado3 == lado2*lado2)
			return true;
		else
			if(lado1*lado1 + lado3*lado3 == lado2*lado2)
				return true;
			else
				return false;
}

void ejercicio3(){
	cout<<"  **Ejercicio 3"<<endl;
	cout<<"Ingrese el numero de elementos catalanes deseados: ";
	long elementos;
	cin>>elementos;
	serieCatalana(elementos);
}

void serieCatalana(long elementos){
	long acum=0,FFelemento1,FFelemento2,valor1,valor2,senuelo;
	if(elementos==1){
		cout<<1;
	}else{
		cout<<"1,";
		senuelo = elementos;
		for(int i = 2 ; i<=senuelo ; i++){
			if(i%2 == 0){
				FFelemento1 = i;	
			}else{
				FFelemento1 = i+1;
				i++;	
				senuelo++;
			}

			FFelemento2 = FFelemento1/2;
			valor1 =  factorial(FFelemento1) / ( factorial(FFelemento2) * factorial( (FFelemento1 - FFelemento2) ) );
			FFelemento2++;
			valor2 =  factorial(FFelemento1) / ( factorial(FFelemento2) * factorial( (FFelemento1 - FFelemento2) ) );
			acum = valor1 - valor2;
			cout<<acum<<",";
		}
	}
}

long factorial(long numero){
	int acum = 1;
	for(int i = 1; i<=numero; i++){
		acum*=i;
	}
	return acum;
}


