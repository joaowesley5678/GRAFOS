#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


#define N_MAX 1000
#define M_MAX 1000


using namespace std;

vector<int> G[N_MAX];
vector<pair<string, int>> O;
bool visitada[N_MAX][N_MAX];
int P[N_MAX][N_MAX];
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

int adjacente(int u, int v) {
    for(int i = 0; i < G[u].size(); i++){
        if(G[u][i] == v){
            return 1;
        }
    }
    return 0;
}

void ordena_aresta(int v){
    for(int u = 0; u < n; u++){
        int a;
        a = adjacente(u, v);
        if(a == 1){
            if(visitada[u][v] == false){
                visitada[u][v] = true;
                visitada[v][u] = true;
                
                string uStr = to_string(u);
                string vStr = to_string(v);
                
                O.push_back({uStr + "--" + vStr, P[u][v]});
                sort(O.begin(), O.end(),[](const pair<string, int>& a, const pair<string, int>& b){
                    return a.second < b.second;
                });
            }
        }
    }
}

vector<pair<string, int>> Kruskal(){
    for(int u = 0; u < n; u++){
        pai[u] = u;
    }
    
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            visitada[u][v] = false;
            visitada[v][u] = false;
        }
    }
    
    for(int u = 0; u < n; u++){
        ordena_aresta(u);
    }
    
    vector<pair<string, int>> A;
    for(const auto& aresta : O){
        string u, v;
        u = aresta.first[0];
        v = aresta.first[3];

        if(FIND_SET(stoi(u)) != FIND_SET(stoi(v))){
            UNION(stoi(u), stoi(v));
            A.push_back({aresta.first, aresta.second});
        }
    }
    return A;
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
        cin >> u >> v >> peso;
        
        G[u].push_back(v);
        G[v].push_back(u);
        
        P[u][v] = peso;
        P[v][u] = peso;
    }
    
    vector<pair<string, int>> A;
    A = Kruskal();
    
    cout << "Arvore Geradora Minima:\n";
    for(const auto& aresta : A){
        cout << aresta.first << ": " << aresta.second << endl;
    }

    return 0;
}