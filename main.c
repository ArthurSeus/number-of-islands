#include <stdio.h>
#include <stdlib.h>

int rows = 5;
int columns = 4;

int grid[5][4] = {
  {0, 1, 0, 1},
  {0, 1, 1, 1},
  {1, 1, 0, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 0}
};

int checkGrid[5][4] = {
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
};

void printGrid(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d", checkGrid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

//this function will mark all indexes that are from a same island
void traverseIsland(int i, int j){
    //mark that this index was already visited
    checkGrid[i][j] = 1;

    //check each and every one of the four sides of the current to see if it is land and was not visited yet
    //the first ifs are so that we don't try to access indexes in the grid that don't exist and get segfault error
    if(i+1 < rows){
        if(grid[i + 1][j] && !checkGrid[i + 1][j]){
            traverseIsland(i + 1, j);
        }
    }
  
    if(i-1 > -1){
        if(grid[i - 1][j] && !checkGrid[i - 1][j]){
            traverseIsland(i - 1, j);
        }
    }

    if(j+1 < columns){
        if(grid[i][j + 1] && !checkGrid[i][j + 1]){
            traverseIsland(i, j + 1);
        }
    }

    if(j-1 > -1){
        if(grid[i][j - 1] && !checkGrid[i][j - 1]){
            traverseIsland(i, j - 1);
        }
    }

}

int islandCounter(){
    int count = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            //if this is a land and it was not visited yet
            if(grid[i][j] && !checkGrid[i][j]){
                traverseIsland(i, j);
                count++;
            }
        }
        //printGrid();
    }
    return count;
}



int main(void) {
    printf("%d", islandCounter());
}