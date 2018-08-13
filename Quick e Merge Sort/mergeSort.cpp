#include <iostream>

using namespace std;

void merge(int array[], int indEsquerda, int indMeio, int indDireita){
	
	int i = 0, 
		j = 0, 
		k = indEsquerda;

	int n1 = indMeio - indEsquerda + 1;
	int n2 = indDireita - indMeio;

	int Esquerda[n1], Direita[n2];

	for(int i = 0; i < n1; i++){
		Esquerda[i] = array[indEsquerda + i];
	}

	for(int j = 0; j < n2; j++){
		Direita[j] = array[indMeio + 1 + j];
	}

	while( i < n1 && j < n2){
		if(Esquerda[i] <= Direita[j]){
			array[k] = Esquerda[i];
			i++;
		}else{
			array[k] = Direita[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		array[k] = Esquerda[i];
		i++;
		k++;
	}	

	while(j < n2){
		array[k] = Direita[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int indEsquerda, int indDireita){
	if(indEsquerda < indDireita){ //Verifica os indices
		int meio = (indEsquerda + (indDireita - 1))/2; //Calcula o indice do meio do array

		//Chama recursivamente a função merge sort para a metade esquerda e direita do array
		mergeSort(array, indEsquerda, meio);
		mergeSort(array, meio + 1, indDireita);
		//Agrupa os sub vetores
		merge(array, indEsquerda, meio, indDireita);
	}
}

int main(){
	int array[10] = {19, 0, 2, 9, 7, 11, 8, 10, 6, 5};
	int tam = 10;

	for(int i = 0; i < tam; i++){
		cout << array[i] << ' ';
	}
	cout << endl;

	mergeSort(array, 0, tam - 1);
 
	for(int i = 0; i < tam; i++){
		cout << array[i] << ' ';
	}
	cout << endl;

	return 0;
}