#include <stdio.h>
#define N 10

void InsertionSort(int array[], int tam){
   int pivo, j;

	for (int i = 1; i < tam; i++) {
        pivo = array[i];

        for(j = i - 1; (j >= 0) && (array[j] > pivo) ; j--){
            array[j+1] = array[j];
        }
		array[j+1] = pivo;
	}
}

void Imprime(int array[], int tam){
    printf("[");
    for(int i = 0; i < tam; i++){
        printf("%d", array[i]);
        if(i != tam - 1){
            printf(",");
        }
    }
    printf("]\n");
}

int main(){
    int opcao;
    int array1[N] = {0,1,4,6,8,9,10,14,18,22};
    int array2[N] = {2,5,8,9,10,20,18,17,16,13};
    int array3[N] = {20,18,16,15,12,9,7,5,3,2};

    printf("\tInsertion Sort\n1- Melhor Caso\n2- Caso Mediano\n3- Pior Caso\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            Imprime(array1, N);
            InsertionSort(array1, N);
            printf("\n\tArray Ordenado:\n");
            Imprime(array1, N);
            break;
        case 2:
            Imprime(array2, N);
            InsertionSort(array2, N);
            printf("\n\tArray Ordenado:\n");
            Imprime(array2, N);
            break;
        case 3:
            Imprime(array3, N);
            InsertionSort(array3, N);
            printf("\n\tArray Ordenado:\n");
            Imprime(array3, N);
            break;
    }
}

