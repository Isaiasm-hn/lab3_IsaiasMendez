#include<iostream>
#include<stdlib.h>
using namespace std;

void Ejercicio1();

int** InitMat(int);

int** llenarMat(int,int);

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
			break;
	}

	}while(ejer != 3);
	return 0;
}

void Ejercicio1(){
	int** tablero=NULL;
	int** tablero2=NULL;
	int size;
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
