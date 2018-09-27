#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Aresta{
private:
	int origem, destino, peso;

public:
	Aresta(int origem, int destino, int peso){
		this->origem = origem;
		this->destino = destino;
		this->peso = peso;
	}

	int getOrigem(){
		return origem;
	}
	int getDestino(){
		return destino;
	}
	int getPeso(){
		return peso;
	}
};

//função que compara os pesos entre duas arestas
bool compara(Aresta num1, Aresta num2){
	return (num1.getPeso() < num2.getPeso());
}

vector<Aresta> Kruskal(vector<Aresta> grafo){

	vector<Aresta> solucaoKruskal;
	//Ordenando a listaArvore pelo minimo
	sort(grafo.begin(),grafo.end(), compara);
	//array para auxiliar na construção da Arvore geradora minima
	int aux[grafo.size()] = {};
	//iniciando todo o array com -1
	for(int i = 0; i < grafo.size(); i++){
		aux[i] = -1;
	}

	for(int i = 0; i < grafo.size(); i++){
		if(aux[grafo[i].getOrigem()] == - 1){
			solucaoKruskal.push_back(grafo[i]);
			aux[grafo[i].getOrigem()] = grafo[i].getOrigem();
		}
	}

	return solucaoKruskal;
}

int main(){

	vector<Aresta> listaArvore;
	vector<Aresta> solucao;
	int tamanho = 0, custo = 0;
	//Lendo a matriz a partir de um arquivo
	ifstream grafo_matriz("dij10.txt", ios::in);
	
	grafo_matriz >> tamanho; //salva o tamanho da matriz

	int matriz[tamanho][tamanho]= {0};

	for (int i = 0; i < tamanho; i++){
		for (int j = i; j < tamanho; j++){
			if (i == j)
				continue;
			grafo_matriz >> matriz[i][j];
			
		}
	}

	for (int i = 0; i < tamanho; i++){
		for (int j = i + 1; j < tamanho; j++){
			Aresta aresta(i,j,matriz[i][j]);
			listaArvore.push_back(aresta);
		}
	}

	/* Caso queira exibir o que foi lido do arquivo;
	for (int i = 0; i < listaArvore.size(); i++){
		cout << " " << listaArvore[i].getOrigem();
		cout << "-" << listaArvore[i].getDestino();
		cout << " " << listaArvore[i].getPeso() << endl;
	}
	*/
	
	//exibindo a solução
	solucao = Kruskal(listaArvore);

	for (int i = 0; i < solucao.size(); i++){
		cout << " " << solucao[i].getOrigem();
		cout << "-" << solucao[i].getDestino();
		cout << " " << solucao[i].getPeso() << endl;
	}

	for (int i = 0; i < solucao.size(); i++){
		
		custo += solucao[i].getPeso();
	}
	cout << "Custo da solução: " << custo << endl;
	
	return 0;
}

