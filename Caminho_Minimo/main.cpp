#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N_MAX 1000
#define M_MAX 1000
#define INF 1000000

using namespace std;

vector<vector<pair<int, int>>> G(N_MAX);
int d[N_MAX];
int pred[N_MAX];

int n;
int m;

pair<int, vector<int>> Dijkstra(int s, int f) {
    for(int v = 0; v < n; v++){
        d[v] = INF;
        pred[v] = -1;
    }
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    
    while (!Q.empty()) {
        int distanciaAtual = Q.top().first;
        int u = Q.top().second;
        Q.pop();

        if (distanciaAtual > d[u]) continue;

        for (auto &vizinho : G[u]) {
            int peso = vizinho.first;
            int v = vizinho.second;

            if (d[u] + peso < d[v]) {
                d[v] = d[u] + peso;
                pred[v] = u;
                Q.push({d[v], v});
            }
        }
    }
    vector<int> caminho;
    if (d[f] != INF) {
        for (int v = f; v != -1; v = pred[v]) {
            caminho.push_back(v);
        }
        reverse(caminho.begin(), caminho.end());
    }

    return {d[f], caminho};
}

int main() {
    
    cout << "Digite o quantidade de vértices: ";
    cin >> n;
    cout << "Digite o quantidade de arestas: ";
    cin >> m;
    
    int u, v, peso;
    for (int i = 0; i < m; i++) {
        cout << "Digite a aresta " << i + 1 << " e seu peso: (u v peso) ";
        cin >> u >> v >> peso;
        
        G[u].push_back({peso, v});
    }
    
    int s, f;

    cout << "Digite o vertice inicial: ";
    cin >> s;
    
    cout << "Digite o vertice final: ";
    cin >> f;
    
    auto resultado = Dijkstra(s, f);
    int custo = resultado.first;
    vector<int> caminho = resultado.second;

    // Imprime o custo e o caminho
    if (custo == INF) {
        cout << "Não existe caminho entre " << s << " e " << f << "." << endl;
    } else {
        cout << "Custo do caminho mais curto de " << s << " para " << f << ": " << custo << endl;
        cout << "Caminho: ";
        for (int v : caminho) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}
