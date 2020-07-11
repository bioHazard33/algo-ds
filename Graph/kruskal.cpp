#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a,vector<int> b){
    return a[2]<b[2];
}

class DSU{
    public:
        vector<int> link;
        vector<int> length;

        DSU(int n){
            link=vector<int>(n);
            for(int i=0;i<n;i++)    link[i]=i;
            length=vector<int>(n,1);
        }

        int find(int a){
            if(a==link[a])  return a;
            else return find(link[a]);
        }

        void merge(int a,int b){

            if(length[a]<length[b]){
                swap(a,b);
            }

            link[find(b)]=find(a);
            
            length[a]+=length[b];
            length[b]=0;
        }

        bool same(int a,int b){
            return find(a)==find(b);
        }
};

int main(){
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
    int n=9;

    DSU dsu(n);
    sort(v.begin(),v.end(),compare);

    cout<<"MST is : "<<endl;
    for(int i=0;i<v.size();i++){
        if(!dsu.same(v[i][0],v[i][1])){
            cout<<"{ "<<v[i][0]<<" , "<<v[i][1]<<" , "<<v[i][2]<<" } "<<endl;
            dsu.merge(v[i][0],v[i][1]);
        }
    }

    return 0;
}