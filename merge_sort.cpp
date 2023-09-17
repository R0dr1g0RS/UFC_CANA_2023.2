#include <iostream>
#include <cmath>
#include <vector>

int particao_meio (std::vector<int>& L, double inicio, double fim){
    int i = inicio;
    int j = fim -1;
    int pote;
    
    while (i != j){
        if (L.at(i) < L.at(i+1)){
            pote = L.at(j);
            L.at(j) = L.at(i+1);
            L.at(i+1) = pote;
            j--;
        } else {
            pote = L.at(i);
            L.at(i) = L.at(i+1);
            L.at(i+1) = pote;
            i++;
        }
    }
    if (i == std::floor(fim/2)){
        return i;    
    } else {
        pote = L[inicio];
        L[inicio] = L[std::floor(fim/2)];
        L[std::floor(fim/2)] = pote;
        return (particao_meio(L, inicio, fim));
    }
    
}

void bubble_sort(std::vector<int>& L, int inicio, int fim){
    bool interagiu = true;
    while (interagiu){
        interagiu = false;
        for (int i = inicio; i < fim-1; i++){
            if (L.at(i) > L.at(i+1)){
                interagiu = true;
                int pote = L.at(i);
                L.at(i) = L.at(i+1);
                L.at(i+1) = pote;
            }
        }    
    }
}

void merge_sort(std::vector<int>& L, int inicio, int fim){
    if ((inicio - fim) == (std::floor(log2(L.size())+1))){
        bubble_sort(L, inicio, fim);
    } else {
        int pivo1 = particao_meio(L, inicio, fim/2);
        int pivo2 = particao_meio(L, fim/2, fim);
        merge_sort(L, )
            
    }
}

int main(){
    std::vector<int> vetor = {4, 2, 1, 8, 9, 3, 5};
    //vetor = particao(vetor);
    //vetor = bubble_sort(vetor, 0, vetor.size());
    int r = particao_meio(vetor, 0, vetor.size());
    for (int i =0; i < vetor.size(); i++){
        if  (i != vetor.size()-1)
            std::cout <<vetor.at(i)<< " ,";
        else
            std::cout <<vetor.at(i)<< std::endl;
    }
    return 0;
}
