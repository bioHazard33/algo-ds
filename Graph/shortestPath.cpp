// A m x n grid is given, in which 'S' is starting point, 'E' is the target,
// '#' are obstacles and '.' are clear paths. Find a shortest path from 'S' to 'E' avoiding obstacles.
// Example:
// graph = {
//     {'S', '.', '.', '#', '.', '.', '.'},
//     {'.', '#', '.', '.', '.', '#', '.'},
//     {'.', '#', '.', '.', '.', '.', '.'},
//     {'.', '.', '#', '#', '.', '.', '.'},
//     {'#', '.', '#', 'E', '.', '#', '.'},
// }
// For above graph,
// Path will be: (0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2) -> (2, 3) -> (2, 4) -> (3, 4) -> (4, 4) -> (4, 3)
//                  S         .         .         .         .         .         .         .         .         E
// Explanation:
//    | 0     1    2    3    4    5    6
// _|____________
// 0  | (S)==(.)==(.)  (#)  (.)  (.)  (.)
//    |            ||
// 1  | (.)  (#)  (.)  (.)  (.)  (#)  (.)
//    |            ||
// 2  | (.)  (#)  (.)==(.)==(.)  (.)  (.)
//    |                      ||
// 3  | (.)  (.)  (#)  (#)  (.)  (.)  (.)
//    |                      ||
// 4  | (#)  (.)  (#)  (E)==(.)  (#)  (.) 

#include<bits/stdc++.h>
using namespace std;

int main(){

    vector< vector<char> > G{
        {'S', '.', '.', '#', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '#', '.'},
        {'.', '#', '.', '.', '.', '.', '.'},
        {'.', '.', '#', '#', '.', '.', '.'},
        {'#', '.', '#', 'E', '.', '#', '.'},
    };

    vector < vector<bool> > visited( G.size() ,vector<bool> ( G[0].size() , false ));
    vector < vector<char> > reach( G.size(), vector<char>( G[0].size() , '#'));
    int m=G.size();
    int n=G[0].size();

    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visited[0][0]=true;
    int E_x,E_y;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        visited[x][y]=true;
        if(G[x][y]=='E'){
            E_x=x;
            E_y=y;
            break;
        }

        if(x+1 < m && !visited[x+1][y] && G[x+1][y]!='#'){
            q.push(make_pair(x+1,y));
            reach[x+1][y]='l';
        }
        if(y+1 < n && !visited[x][y+1] && G[x][y+1]!='#'){
            q.push(make_pair(x,y+1));
            reach[x][y+1]='u';
        }
        if(x-1 >= 0  && !visited[x-1][y] && G[x-1][y]!='#'){
            q.push(make_pair(x-1,y));
            reach[x-1][y]='r';
        }
        if(y-1 >= 0  && !visited[x][y-1] && G[x][y-1]!='#'){
            q.push(make_pair(x,y-1));
            reach[x][y-1]='d';
        }
    }

    while(G[E_x][E_y]!='S'){
        cout<<"( "<<E_x<<" , "<<E_y<<" ) - > ";

        if(reach[E_x][E_y]=='l')    E_x-=1;
        else if(reach[E_x][E_y]=='u')   E_y-=1;
        else if(reach[E_x][E_y]=='d')   E_y+=1;
        else if(reach[E_x][E_y]=='r')   E_x+=1;
    }

    cout<<"( "<<E_x<<" , "<<E_y<<" )"<<endl;
    return 0;
}