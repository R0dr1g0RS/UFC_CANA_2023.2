/*
Imagine que L ´e uma lista de tamanho n, que cont´em elementos repetidos.
A tarefa consiste em agrupar todas as ocorrências dos elementos repetidos,
mantendo a ordem relativa da 1ª ocorrência de cada elemento
Este algoritmo é ineficiente, faz essa ordenação em O(n³)
*/

#include <stdio.h>
#include <iostream>
#include <vector>

void troca(std::vector<int>& L1, int pos1, std::vector<int>& L2, int pos2){
    int pote = L1.at(pos1);
    L1.at(pos1) = L2.at(pos2);
    L2.at(pos2) = pote;
    return;
}

std::vector<int> agrup_duplicata (std::vector<int>& L){
    for (int i = 0; i < L.size(); i++){
        for (int j = (i+1); j < L.size(); j++){
            if (L.at(j) == L.at(i)){
                for(int k = j; k > i; k--){
                    troca(L, k, L, (k-1));   
                }
                i++;
            }
        }
    }
    
    return L;
}

int main(){
    std::vector<int> vetor = {5, 2, 2, 1, 3, 1, 5, 2, 3, 4, 1, 2};
    
    agrup_duplicata(vetor);
    
    for (int i =0; i < vetor.size(); i++){
        if  (i != vetor.size()-1)
            std::cout <<vetor.at(i)<< " ,";
        else
            std::cout <<vetor.at(i)<< std::endl; 
            // resultado: {5, 5, 2, 2, 2, 2, 1, 1, 1, 3, 3, 4}
    }    
    return 0;
}
