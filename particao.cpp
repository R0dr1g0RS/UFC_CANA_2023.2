#include <iostream>
#include <vector>

std::vector<int> particao (std::vector<int>& L){
    int i = 0;
    int j = L.size() -1;
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
    return L; 
}

int main(){
    std::vector<int> vetor = {4, 2, 1, 8, 9, 3};
    vetor = particao(vetor);
    for (int i =0; i < vetor.size(); i++){
        if  (i != vetor.size()-1)
            std::cout <<vetor.at(i)<< " ,";
        else
            std::cout <<vetor.at(i)<< std::endl;
    }
    return 0;
}
