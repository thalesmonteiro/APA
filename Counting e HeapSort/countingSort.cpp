#include <iostream>

using namespace std;

void countingSort(int array[], int tam){
	int k = 0;

	k = array[0]; //guarda o maior numero do array

	int B[tam];

	for(int i = 1; i < tam; i++){
		if(array[i] > k)
			k = array[i];
		
	}

	int C[k + 1] = {}; //criando um array auxiliar
	//zerando o auxiliar
	for(int i = 0; i < k; i++){
		C[i] = 0;
	}
	//contando quantos elementos tem no array
	for(int i = 0; i < tam; i++){
		C[array[i]]++;
	}

	for(int i = 1; i <= k; i++){
		C[i] += C[i-1];
	}

	for(int j = tam - 1; j >= 0; j--){
		B[C[array[j]] - 1] = array[j];
		C[array[j]] = C[array[j]] - 1;
	}

	for(int i = 0; i < tam; i++){
		cout << (i) << ": " << B[i] << endl;
	}
	cout << endl;

}

int main(){
	int array[8] = {11,10,9,8,0,7,0,83};

	countingSort(array, 8);
	return 0;
}
