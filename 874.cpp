#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int countValidColorings(int n, int k, int m, const vector<pair<int, int>>& wires, vector<int>& colors, int currentVertex)
{
    if (currentVertex > n)
    {
        return 1;
    }
    int count = 0;
    for (int c = 1; c <= k; c++)
    {
        bool isValidColor = true;
        for (const auto& wire : wires)
        {
            int u = wire.first;
            int v = wire.second;
            if ((u == currentVertex && colors[v] == c) || (v == currentVertex && colors[u] == c))
            {
                isValidColor = false;
                break;
            }
        }
        if (isValidColor)
        {
            colors[currentVertex] = c;
            count += countValidColorings(n, k, m, wires, colors, currentVertex + 1);
            colors[currentVertex] = 0;
        }
    }
    return count;
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n, k, m;
    input >> n >> k >> m;

    vector<pair<int, int>> wires;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        input >> u >> v;
        wires.push_back({ u, v });
    }

    vector<int> colors(n + 1, 0);
    int count = countValidColorings(n, k, m, wires, colors, 1);

    cout << count << endl;
    output << count << endl;

    input.close();
    output.close();

    return 0;
}