#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};
int main(){
    // Sample Input
    vector<vector<int> > v={
         {0, 1, 4  },
         {0, 7, 8  } ,
         {1, 2, 8  } ,
         {1, 7, 11  } ,
         {2, 3, 7  } ,
         {2, 8, 2  } ,
         {2, 5, 4  } ,
         {3, 4, 9  } ,
         {3, 5, 14  } ,
         {4, 5, 10  } ,
         {5, 6, 2  } ,
         {6, 7, 1  } ,
         {6, 8, 6  } ,
         {7, 8, 7  }
    };
    int n=9,source=0;
    // Input End

    vector< pair<int,int> > G[n];
    
    for(int i=0;i<v.size();i++){
        G[v[i][0]].push_back(make_pair(v[i][1],v[i][2]));
        G[v[i][1]].push_back(make_pair(v[i][0],v[i][2]));
    }

    // for(int i=0;i<n;i++){
    //     for(auto v:G[i]){
    //         cout<<i<<v.first<<v.second<<endl;
    //     }
    // }

    vector<int> dist(n,INT_MAX);

    priority_queue< pair<int,int> , vector<pair<int,int> > , compare > pq;
    
    pq.push(make_pair(source,0));
    dist[source]=0;

    while(!pq.empty()){
        int u=pq.top().first;
        pq.pop();
        for(auto i:G[u]){
            int v=i.first;
            int len=i.second;
            if(dist[u] + len < dist[v]){
                dist[v]=dist[u]+len;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }

    for(int i=0;i<n;i++)    cout<<dist[i]<<endl;

    return 0;
}
