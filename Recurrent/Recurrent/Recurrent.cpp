// Recurrent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n_input;
    cin >> n_input;
    auto input = vector<vector<int>>(n_input);

    for (int i=0; i < n_input; i++) {
    	std::copy_n(std::istream_iterator<int>(std::cin), 7, std::inserter(input[i], input[i].begin()));
    }

    long int MOD = 1000000007;

    for (int i=0; i<=n_input-1; i++)
    {
	    const int n = input[i][0];

        int a_k = input[i][1] * input[i][3] + input[i][2] * input[i][4];
        int b_k = input[i][1] * input[i][5] + input[i][2] * input[i][6];

        int a_prev = a_k;
        int b_prev = b_k;

        for (int j=0; j<= n-2; j++)
        {
        	a_k = a_prev * input[i][3] + b_prev * input[i][4];
            b_k = a_prev * input[i][5] + b_prev * input[i][6];
        	a_prev = a_k % MOD;
        	b_prev = b_k % MOD;
        }
        cout << a_k << '\n';
    }
}
