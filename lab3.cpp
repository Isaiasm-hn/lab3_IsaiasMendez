#include<iostream>
#include<stdlib.h>
using namespace std;

void Ejercicio1();

void Ejercicio2();

int** InitMat(int);

int** llenarMat(int,int);

int siglo(int);

int mes(int);

int main(){
	int ejer;
	do{
	cout<<endl<<"1)- Ejercicio 1\n"<<
		  "2)- Ejercicio 2\n"<<
		  "3)- Salir\n"<<
		  "Ingrese Opcion: ";
	cin>>ejer;
	cout<<endl;
	switch(ejer){
		case 1:
			cout<<"------EJERCICIO 1------";
			Ejercicio1();
			break;
		case 2:
			cout<<"------EJERCICIO 2------";
			Ejercicio2();
			break;
	}

	}while(ejer != 3);
	return 0;
}

void Ejercicio1(){
	int** tablero=NULL;
	int** tablero2=NULL;
	int size;
	cout<<endl;
	do{
		cout<<"Ingrese dimension de la matriz >= 9: ";
		cin>>size;
	}while(size<9);
	int min;
	do{
		cout<<"Ingrese cantidad de minas >=10: ";
		cin>>min;

	}while(min<10);
	tablero= llenarMat(size,min);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(tablero[i][j]==-1){
				cout<<"|"<<tablero[i][j]<<" |";
				
			}else{
				cout<<"| "<<tablero[i][j]<<" |";
			}
		}
		cout<<endl;
	}
	
	//Lleno la matriz
	int cont=0;

}

int** InitMat(int size){
	int** mat=new int*[size];
	for(int i=0;i<size;i++){
		mat[i]=new int[size];
	}
	return mat;

}
	
int** llenarMat(int size,int mine){
	int** mat;
	mat=InitMat(size);
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			mat[i][j]=0;
		}
	}

	int cont=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if((rand() % mine + 0==j || rand() % mine + 0==i )){
				if(cont<mine){
					mat[i][j]=-1;
					cont++;
				}
			}
		}
	}
	/*for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(mat[i][j]==-1){
				if(i==0 && j==0 ){
					mat[i+1][j]=mat[i+1][j]+1;
					mat[i+1][j+1]=mat[i+1][j+1]+1;
					mat[i][j+1]=mat[i][j+1]+1;
				}if(i==size-1 && j==0){
					mat[i+1][j+1]=mat[i+1][j+1]+1;
					mat[i-1][j]=mat[i+1][j]+1;
					mat[i-1][j+1]=mat[i-1][j+1]+1;
				}if(i==size -1 && j==size-1){
					mat[i-1][j]=mat[i-1][j]+1;
					mat[i-1][j-1]=mat[i-1][j-1]+1;
					mat[i][j-1]=mat[i][j-1]+1;
				}if(i>0 && j==0 && i<size-1){
					for(int k=i+1;k<3;k++){
						mat[k][j]=mat[k][j]+1;
					}
					mat[i-1][j]=mat[i-1][j]+1;
					mat[i+1][j]=mat[i+1][j]+1;
				}
			}
		}
	}*/
	return mat;
}

void Ejercicio2(){
	int a, b, c, dia;
	int cont=0;
	int bisiesto;
	cout<<endl;
	cout<<"Ingrese dia: ";
	cin>>a;
	cout<<"Ingrese mes: ";
	cin>>b;
	cout<<"Ingrese year: ";
	cin>>c;
	cout<<endl<<endl;
	switch (b){	
		case 2:
				if(c%400==0 || c%4==0 && c%100!=0){
						bisiesto=1;
						dia=29;
					}else{
						dia=28;
						bisiesto=0;	
					}
					break;
			case 4:
					dia=30;
					break;
			case 6:
					dia=30;
					break;
			case 9:
					dia=30;
					break;
			case 11:
					dia=30;
					break;
			default:
					dia=31;
					break;	
	}
	
		int sum;
		switch (b){
			case 1:
					sum=0;
					break;
			case 2:
					sum=31;
					break;
			case 3: 
					sum=59+bisiesto;
					break;
			case 4:
					sum=90+bisiesto;
					break;
			case 5:
					sum=120+bisiesto;
					break;
			case 6:
					sum=151+bisiesto;
					break;
			case 7:
					sum=181+bisiesto;
					break;
		
			case 8: 
					sum=212+bisiesto;
					break;
			case 9:
					sum=243+bisiesto;
					break;
			case 10:
					sum=273+bisiesto;
					break;
			case 11:
					sum=304+bisiesto;
					break;
			case 12:
					sum=334+bisiesto;
					break;

		}
		int d,e,y,r;
		d=sum+a;
		e=(c-1)/4;
		r=y%7;
		switch (r){
			case 0:
				    cout<<a<<"/"<<b<<"/"<<c<<" Es Viernes";
					break;
			case 1:
					cout<<a<<"/"<<b<<"/"<<c<<" Es sabado";
					break;
			case 2:
					cout<<a<<"/"<<b<<"/"<<c<<" Es domingo";
					break;
			case 3:
					cout<<a<<"/"<<b<<"/"<<c<<" Es lunes";
					break;
			case 4:
					cout<<a<<"/"<<b<<"/"<<c<<" es martes";
					break;
			case 5:		
					cout<<a<<"/"<<b<<"/"<<c<<" es miercoles";
					break;
			case 6:
					cout<<a<<"/"<<b<<"/"<<c<<" Es jueves";
					break;
			
		}
		cout<<endl;
}
