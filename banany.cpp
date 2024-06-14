#include <cstdio>
#include <string>
#include <vector>

using namespace std;


//Wczytuje i tworzy macierz sąsiedztwa 
void readArray(int n){
    
    if(n>0){
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

        int bitsInRow=0;
        int rowCounter=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (int)(getchar()-'0');
                if(matrix[i][j]==1)bitsInRow++;
                // printf("%d ", matrix[i][j]);
            }
            // printf("\n");
            if(bitsInRow==1){
                rowCounter++;
            }
            bitsInRow=0;  
        }
        if(rowCounter>0){
            printf("%d bananas :)\n",rowCounter);
        }
        else{
            printf("%d bananas :(\n",rowCounter);
        }
        rowCounter=0;
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
        
        lines--;
    }
    return 0;
}
