#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    vector<int> listaAdj[n + 1];

    for (auto v : edges) {
      listaAdj[v[0]].push_back(v[1]);
      listaAdj[v[1]].push_back(v[0]);
    }

    vector<int> visitados(n + 1, 0);
    visitados[1] = 1;

    queue<pair<int, pair<int, long>>> fila;
    fila.push({0, {1, 1}});

    int segundos = 0, no = 1;
    long prob = 1;

    while (!fila.empty()) {
      auto x = fila.front();
      fila.pop();

      segundos = x.first, no = x.second.first, prob = x.second.second;

      if (!t)
        return target == 1 ? (double)1.0 / prob : 0;

      if (segundos == t && target == no)
        return prob > 10000 ? 0 : (double)1.0 / prob;

      if (listaAdj[no].size() == 0)
        return prob > 10000 ? 0 : (double)1.0 / prob;

      if (no == 1)
        prob *= listaAdj[no].size();
      else
        prob *= listaAdj[no].size() == 1 ? 1 : listaAdj[no].size() - 1;

      for (auto vizinho : listaAdj[no]) {
        if (!visitados[vizinho]) {
          visitados[vizinho] = 1;
          if (vizinho == target && segundos < t) {
            bool final = true;
            for (auto prox : listaAdj[vizinho])
              if (!visitados[prox])
                final = false;
            if (final)
              return prob > 10000 ? 0 : (double)1.0 / prob;
          }
          fila.push({segundos + 1, {vizinho, prob}});
        } else if (vizinho == target && segundos <= t)
          continue;
      }
    }

    return 0.0;
  }
};
