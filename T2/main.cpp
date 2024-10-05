#include <iostream>
#include <vector>


#define N_MAX 1000
#define M_MAX 1000


using namespace std;

vector<int> G[N_MAX];
vector<int> e[M_MAX]
vector<int> pai[N_MAX];

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

void Kruskal(e){
    for(int u = 0; u < n; u++){
        pai[u] = u;
    }
    ordemArestas = e;
    sort(ordemArestas.begin(), ordemArestas.end());
    
    int A;
}

int main()
{
    cout << "Digite o quantidade de vértices: ";
    cin >> n;
    cout << "Digite o quantidade de arestas: ";
    cin >> m;
    
    cout << "Digite as arestas (formato: peso u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v, peso;
        cin >> peso >> u >> v;
        e[i] = {peso, {u, v}};
        
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return 0;
}