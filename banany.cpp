#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> matrix;

//Zlicza jedynki w wektorze
int countRow (vector<int> &row, int n){
    int counter=0;
    for(int element : row){
        if(element==1)
        counter++;
    }
    return counter;
}
//Wczytuje i tworzy macierz sąsiedztwa 
void readArray(int n){
    if(n>0){
        matrix = vector(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (int)(getchar()-'0');
                //printf("%d ",matrix[i][j]);
            }
           // printf("\n");
        }
    }
}

void countLeaves(int n){
    


    set<int> notRoot;
    set<int> branches;
    //osobny set dla lisci i galezi
    //dla setu galezi sprawdzac ilosc bananananana

    //dla kazdego wiersza w macierzy
    int leafCounter=0;
    int rowCounter=0;
    for(vector<int> row: matrix) {
        
        if(countRow(row,n)==1){
            leafCounter++;
            notRoot.insert(rowCounter);
            //dla kazdego elementu w wierszu ktory jest lisciem
            int columnCounter=0;
            for(int element : row){
                if(element==1){
                    notRoot.insert(columnCounter);
                    branches.insert(columnCounter);
                }
                columnCounter++;
            }
            columnCounter=0;
        }
    rowCounter++;
    }

    
    //tworzymy tablice od 0 do n
    //szukamy roota dla n>2 kiedy istnieje galaz ktora nie jest rootem

    set<int> root;
    for (int i=0;i<n;i++){
        root.insert(i);
    }

    for(int element: notRoot) {
        root.erase(element);
    }
    if(n>2 && root.size()==0){
        root=branches;
    }
    // for(int element :root){
    //     printf("NASZ ROOT ID TO:%d \n",element);     
    // }
    

 
    //WYPISANIE WYNIKU
    if(root.size()==0 && n==2){
        printf("%d bananas :)\n",leafCounter);
    }
    else if(root.size()!=1){
        printf("0 bananas :(\n");
    }
    else if(leafCounter > 0){
        printf("%d bananas :)\n",leafCounter); 
    }
    else{
        printf("%d bananas :(\n",leafCounter);   
    }
    // printf("branches size%d \n",branches.size());
    // printf("notRoot size%d \n",notRoot.size());
}

int main() {

    //Wczytanie ilosci wierszy
    int lines;
    scanf("%d", &lines);
    if(lines<=0)printf("niepoprawna ilosc wierszy!");

    while(lines>0){
        //Wczytanie n ilosci wierzchołków i usunięcie spacji przed tablica
        int n;
        scanf("%d", &n);
        getchar();

        readArray(n);

        //szuka roota zwraca jego id
        //searchForRoot(n);
        
        
        countLeaves(n);
        
        lines--;
    }
    return 0;
}
