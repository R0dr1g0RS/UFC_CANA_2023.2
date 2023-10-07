#include <stdio.h>
#include <iostream>
#include <vector>


std::vector<int> combinarAD(std::vector<int>& L1, std::vector<int>& L2){
    int n1 = L1.size();
    int n2 = L2.size();
    int i = 0;
    int j = 0;
    int h = 0;
    std::vector<int> L(n1 + n2);
    
    while(i < n1){
        L.at(h) = L1.at(i);
        h++;
        if (L1.at(i) != L1.at(i+1)){
            if (L1.at(i) == L2.at(j)){
                L.at(h) = L2.at(j); 
                L2.at(j) = -1;
                h++; j++;
            }
        }else {i++;}
        j = 0;
    }
    
    for (j = 0; j < n2; j++){
        if (L2.at(j) != -1){
            L.at(h) = L2.at(j);
            h++;
        }
    }
    
    return (L);
}

std::vector<int> agrup_duplicata_V2(std::vector<int>& L, int ini, int fim) {
    if (fim <= (ini+1)){
        std::vector<int> Lalterada(fim-ini+1);
        //std::cout <<Lalterada.size()<< std::endl;
        for (int q = 0; q < Lalterada.size(); q++){
            std::cout <<q<< std::endl;
            std::cout<<"ok1"<<std::endl;
            Lalterada.at(q) = L.at(ini+q);
        }
        return Lalterada;
    }
    std::cout <<fim/2<< std::endl;
    std::vector<int> L1 = agrup_duplicata_V2(L, ini, (fim/2));
    std::vector<int> L2 = agrup_duplicata_V2(L, ((fim/2)+1), fim);
    std::vector<int> V = combinarAD(L1, L2);
    return(V);
}

int main(){
    std::vector<int> vetor = {5, 2, 2, 1, 3, 1, 5, 2, 3, 4, 1, 2};
    
    agrup_duplicata_V2(vetor, 0, 11);
    
    for (int i =0; i < vetor.size(); i++){
        if  (i != vetor.size()-1)
            std::cout <<vetor.at(i)<< " ,";
        else
            std::cout <<vetor.at(i)<< std::endl;
    }
    
    return 0;
}
