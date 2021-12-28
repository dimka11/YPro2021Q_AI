// LCM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <unordered_set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_input;
    cin >> n_input;
    auto input = vector<vector<int>>(n_input);
    for (int i = 0; i < n_input; i++) {
        std::copy_n(std::istream_iterator<int>(std::cin), 2, std::inserter(input[i], input[i].begin()));
    }

    auto results = unordered_set<int>();

    for (int in = 0; in <= n_input - 1; in++)
    {
        int n = input[in][0];
        int m = input[in][1];

        int i_max = n;
        int j_max = m;
        int i_min = (i_max / 2) - 1;
        int j_min = (j_max / 2) -1;

        for(int i= i_max; i > i_min; i--)
        {
        	for (int j= j_max; j > j_min; j--)
        	{
                if ((i==0) || (j==0))
                {
	                continue;
                }
                int res = (lcm(i, n) / i) + (lcm(j, m) / j);
                results.insert(res);
        	}
        }

        cout << results.size() << '\n';
        results.clear();
    }
}

