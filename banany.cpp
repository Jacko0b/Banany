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
            }
        }
    }
}

void countLeaves(int n){

    set<int> notRoot;
    set<int> root;
    set<int> branches;

    //dla kazdego wiersza w macierzy
    int leafCounter=0;
    int rowCounter=0;
    for(vector<int> row: matrix) {
        
        //jak jest lisciem
        if(countRow(row,n)==1){
            leafCounter++;
            notRoot.insert(rowCounter);
            //dla kazdego elementu w lisciu
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
    for (int i=0;i<n;i++){
        root.insert(i);
    }

    for(int element: notRoot) {
        root.erase(element);
    }
    if(n>2 && root.size()==0 && branches.size()==1){
        root=branches;
    }


    //Sprawdzanie czy bananaTree - rowna ilosc jedynek na galeziach
    bool bananaTree = false;
    int firstBranchSum = countRow(matrix[*branches.begin()],n);
    if(branches.size()!=1){

    }
    for(int branch : branches){
        if(firstBranchSum==countRow(matrix[branch],n)){
            bananaTree = true;
        }
        else{
            bananaTree = false;
        }
    }
    //ZLE WYPISUJE JEZELI MAMY DRZEWO Z GLEBOKOSCIA WIECEJ NIZ 3
    //WYPISANIE WYNIKU
    if(!bananaTree){
        printf("0 bananas :(\n");
    }
    else if(root.size()==0 && n==2){
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
        countLeaves(n);
        
        lines--;
    }
    return 0;
}
