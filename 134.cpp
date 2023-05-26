#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <string>


using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    int inf = pow(10, 9);
    vector<int> a, b, c, d;
    string line;

    getline(input, line);
    int n = stoi(line);

    getline(input, line);
    int s = stoi(line.substr(0, line.find(' ')));
    int f = stoi(line.substr(line.find(' ') + 1));

    getline(input, line);
    int m = stoi(line);

    for (int i = 0; i < m; i++)
    {
        getline(input, line);
        int val1 = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        int val2 = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        int val3 = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        int val4 = stoi(line);

        a.push_back(val1);
        b.push_back(val2);
        c.push_back(val3);
        d.push_back(val4);
    }

    cout << "a: ";
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "b: ";
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "c: ";
    for (int i = 0; i < m; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    cout << "d: ";
    for (int i = 0; i < m; i++)
    {
        cout << d[i] << " ";
    }


    vector<int> destination(n, inf);

    destination[s - 1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (destination[c[j] - 1] > d[j] && destination[a[j] - 1] != inf && b[j] >= destination[a[j] - 1])
            {
                destination[c[j] - 1] = d[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (destination[i] == inf)
        {
            destination[i] = 0;
        }
    }
    cout << endl;

    cout << "destination: ";
    for (int i = 0; i < n; i++)
    {
        cout << destination[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (destination[i] == 0)
        {
            destination[i] = -1;
            destination[s - 1] = 0;
        }
    }

    int ans = destination[f - 1];
    cout << ans << endl;

    output << ans << endl;

    input.close();
    output.close();

    return 0;
}