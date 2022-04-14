#include<bits/stdc++.h>
using namespace std;



//print all permutations not containng some substring

void permut(string s,int l,int r,string a)
{

}


//rat and maze problem
const int N=100;
bool maze[N][N],solve[N][N];
bool ratmaze()
{
    if(solvemazerec(0,0)==false)
    return false;
    else{
        // printma 
        return true;
    }
}
bool isSafe(int i,int j)
{
    return (i<N && j<N && maze[i][j]==1);
}

bool solvemazerec(int i,int j)
{
    if(i==N-1 && j==N-1){
        solve[i][j]=1;return true;
    }
    if(isSafe(i,j)==true)
    {
        solve[i][j]=1;
        if(solvemazerec((i+1),j)==true) return true;
        else if(solvemazerec(i,j+1)==true)return true;
        solve[i][j]=0;
}
return false;
}