#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i , int j , int row, int col ,int arr[][4], vector<vector<bool> > &visited){
    if((i>=0 && i<row) && (j>=0 && j<col) && (arr[i][j] == 1) && (visited[i][j] == false)){
        return true;
    }
    else{
        return false;
    }
}


void solveMaze(int arr[][4],int row, int col,int i , int j,vector<vector<bool> >&visited,vector<string> &path, string output){
    // base case
    if( i == row-1 && j == col-1){
        path.push_back(output);
        return;
    }
    
    
// down (i+1, j)
    if(isSafe(i+1, j, row,col,arr, visited)){
        visited[i+1][j] = true;
        solveMaze(arr,row,col, i+1, j, visited, path,output +'D');
         
        //backtracking
        visited[i+1][j] = false;
        
    }
    
// left (i, j-1)
    if(isSafe(i, j-1, row, col, arr,visited)){
        visited[i][j-1] = true;
        solveMaze(arr, row,col,i,j-1, visited,path,output+'l');
        
        // backtracking
        visited[i][j-1] = false;
    }
    
    
    
// right (i,j+1)
    if(isSafe(i,j+1, row,col,arr,visited)){
        visited[i][j+1] = true;
        solveMaze(arr, row,col,i,j+1,visited, path, output+'R');
        // backtracking
        
        visited[i][j+1] = false;
        
    }
    
    // up (i-1,j
    if(isSafe(i-1,j, row,col,arr,visited)){
        visited[i-1][j] = true;
        solveMaze(arr, row,col,i-1,j,visited, path, output+'U');
        // backtracking
        
        visited[i-1][j] = false;
        
    }
    
    
}


int main() {
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };
    
    //if source path doesnt exists
    if(maze[0][0] == 0){
        cout<<"path doesnt exists";
        return 0;
    }
    int row = 4;
    int col  = 4;

    vector<string> path;
    string output = "";
    
    vector<vector<bool> > visited(row,vector<bool>(col,false));
    visited[0][0]= true;
    
    solveMaze(maze,row,col,0,0,visited,path,output);
    
    cout<<"Printing the results"<<endl;
    for(auto i : path){
        cout<<i<<" ";
    }
    cout<<endl;
    
    if(path.size() == 0){
        cout<<"path not exists" <<endl;
    }
    
    
    
    return 0;
}
