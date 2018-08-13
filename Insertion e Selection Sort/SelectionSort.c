#include <stdio.h>


void SelectionSort(int array[]){
    int auxiliar = 0,
        min_valor = 0;
    //Inicio do Algoritmo
    for(int i = 0; i < 9; i++){
        min_valor = i;

        for(int j = i + 1; j < 10; j++){
            if(array[j] < array[min_valor]){
                min_valor = j;
            }
        }
        
        if(min_valor != i){
            auxiliar = array[i];
            array[i] = array[min_valor];
            array[min_valor] = auxiliar;
        }
    } //FIm do Algoritmo
}

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
    int opcao, resp;
    int array1[10] = {0,1,4,6,8,9,10,14,18,22};
    int array2[10] = {2,5,8,9,10,20,18,17,16,13};
    int array3[10] = {20,18,16,15,12,9,7,5,3,2};

    printf("Algoritmos de Ordenação:\n1- Selection Sort\n2- InsertionSort\n");
    scanf("%d", resp);
    if(resp == 1){
        printf("\tSelection Sort\n1- Melhor Caso\n2- Caso Mediano\n3- Pior Caso\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                Imprime(array1, 10);
                SelectionSort(array1);
                printf("\n\tArray Ordenado:\n");
                Imprime(array1, 10);
                break;
            case 2:
                Imprime(array2,10);
                SelectionSort(array2);
                printf("\n\tArray Ordenado:\n");
                Imprime(array2,10);
                break;
            case 3:
                Imprime(array3, 10);
                SelectionSort(array3);
                printf("\n\tArray Ordenado:\n");
                Imprime(array3,10);
                break;
        }
    }else if(resp == 2){
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
    
}

