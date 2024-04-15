#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<pair<int, int>> listaAdj[n];
    for (auto v : flights)
      listaAdj[v[0]].push_back({v[1], v[2]});

    vector<int> menorCusto(n, INT_MAX);
    menorCusto[src] = 0;

    queue<pair<int, pair<int, int>>> fila; // {paradas, {cidade, custoTotal}}
    fila.push({0, {src, 0}});

    while (!fila.empty()) {
      auto x = fila.front();
      fila.pop();

      int paradas = x.first, cidade = x.second.first,
          custoTotal = x.second.second;

      for (auto vizinho : listaAdj[cidade]) {
        int cidadeVizinha = vizinho.first, custoVoo = vizinho.second;

        if (custoTotal + custoVoo < menorCusto[cidadeVizinha] && paradas <= k) {
          menorCusto[cidadeVizinha] = custoTotal + custoVoo;
          fila.push({paradas + 1, {cidadeVizinha, custoTotal + custoVoo}});
        }
      }
    }

    return menorCusto[dst] == INT_MAX ? -1 : menorCusto[dst];
  }
};
