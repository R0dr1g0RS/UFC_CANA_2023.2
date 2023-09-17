#include <iostream>
#include <vector>

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

int main(){
    std::vector<int> vetor = {4, 2, 1, 8, 9, 3, 5};
    //vetor = particao(vetor);
    bubble_sort(vetor, 0, vetor.size());
    for (int i =0; i < vetor.size(); i++){
        if  (i != vetor.size()-1)
            std::cout <<vetor.at(i)<< " ,";
        else
            std::cout <<vetor.at(i)<< std::endl;
    }
    return 0;
}
