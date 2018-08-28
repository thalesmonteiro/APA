#include <iostream>

using namespace std;

void HeapSort(int array[], int tam_heap);
void BuildMaxHeap(int array[], int tam_heap);
void MaxHeapify(int array[], int i, int tam_heap);
void Print(int array[], int n);

int main(){

	int array[] = {12,11,13,5,6,7};
	int tam = sizeof(array)/sizeof(array[0]);

	HeapSort(array, tam);

	Print(array, tam);
}

void HeapSort(int array[], int tam_heap){
	int aux = 0;

	BuildMaxHeap(array, tam_heap);

	for(int i = tam_heap - 1; i >= 0; i--){
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;

		MaxHeapify(array,i, 0);
	}
}

void BuildMaxHeap(int array[], int tam_heap){
	int tam = tam_heap;

	for(int i = (tam/2) - 1; i >= 0; i--){
		MaxHeapify(array, tam_heap, i);
	}
}

// n é o comprimento do heap, i é o indice

void MaxHeapify(int array[], int tam_heap, int i){
	int esquerdo, direito, maior, aux = 0;

	esquerdo = 2*i + 1;
	direito = 2*i + 2;
	maior = i;
	
	if(esquerdo < tam_heap && array[esquerdo] > array[maior]){
		maior = esquerdo;
	}

	if(direito < tam_heap && array[direito] > array[maior]){
		maior = direito;
	}

	if(maior != i){
		aux = array[i];
		array[i] = array[maior];
		array[maior] = aux;

		MaxHeapify(array, i, maior);
	}
}

void Print(int array[], int n){
	for(int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}