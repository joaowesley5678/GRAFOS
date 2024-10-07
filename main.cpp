#include <iostream>
#include <vector
#include <algorithm>


#define N_MAX 1000
#define M_MAX 1000


using namespace std;

vector<pair<int, double>> G[N_MAX];
int e[M_MAX];
int pai[N_MAX];

int n;
int m;

int FIND_SET(int u){
    if(u == pai[u]){
        return u;
    }
    return FIND_SET(pai[u]);
}

void UNION(int u, int v){
    pai[FIND_SET(v)] = FIND_SET(u);
}

void Kruskal(){
    for(int u = 0; u < n; u++){
        pai[u] = u;
    }
    
    sort(G.begin(), G.end(), [](const pair<int, double>& a, const pair<int, double>& b){
        return a.second < b.second;
    });
    
    int A;
    for(int i = 0; i < m; i++){
        
    }
}

int main()
{
    cout << "Digite o quantidade de vértices: ";
    cin >> n;
    cout << "Digite o quantidade de arestas: ";
    cin >> m;
    
    int u, v, peso;
    for (int i = 0; i < m; i++) {
        cout << "Digite a aresta " << i + 1 << " e seu peso: (u v peso) ";
        cin >> peso >> u >> v;
        
        G[u].push_back({v, peso});
        G[v].push_back({u, peso});
    }

    int s;

    cout << "Digite o vertice inicial: ";
    cin >> s;
    
    Kruskal();

    return 0;
}