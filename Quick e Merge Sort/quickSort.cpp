#include <iostream>

using namespace std;

 void quicksort(int array[], int inicio, int fim){
     int pivo, aux;
     int i = inicio;
     int j = fim - 1;

    pivo = array[(inicio + fim) / 2]; //Elemento do meio do vetor

    while(i <= j){
        while(array[i] < pivo && i < fim){
            i++;
        }
        while(array[j] > pivo && j > inicio){
            j--;
        }

        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }

    if( j > inicio){
        quicksort(array, inicio, j + 1);
    }
    if( i < fim){
        quicksort(array, i, fim);
    }
 }


 int main(){
     int array[10] = {11, 3, 2, 9, 0, 4, 8, 10, 1, 5};

     for(int i = 0; i < 10; i++){
         cout << array[i] << ' ';
     }

    cout << endl ;

    quicksort(array, 0, 10);

    for(int i = 0; i < 10; i++){
        cout <<  array[i]  << ' ';
    }

    cout << endl;

    return 0;
 }