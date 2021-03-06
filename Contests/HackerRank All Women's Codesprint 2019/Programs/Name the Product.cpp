#include <bits/stdc++.h>

using namespace std;


int main()
{
    int no_of_strings;
    cin >> no_of_strings;

    const int NO_OF_POSITIONS = 5, NO_OF_ALPHABETS = 26, oo = 1e9;
    typedef vector <int> v_int;

    vector <v_int> frequency(NO_OF_POSITIONS, v_int(NO_OF_ALPHABETS, 0));
    for(int i = 0; i < no_of_strings; i++)
    {
        string S;
        cin >> S;

        for(int l = 0; l < NO_OF_POSITIONS; l++)
            frequency[l][S[l] - 'a']++;
    }

    vector <int> min_frequency(NO_OF_POSITIONS, oo);
    for(int p = 0; p < NO_OF_POSITIONS; p++)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            min_frequency[p] = min(min_frequency[p], frequency[p][alpha]);
        }
    }

    string answer;
    for(int p = 0; p < NO_OF_POSITIONS; p++)
    {
        for(int alpha = NO_OF_ALPHABETS - 1; alpha >= 0; alpha--)
        {
            if(frequency[p][alpha] == min_frequency[p])
            {
                answer += (char)('a' + alpha);
                break;
            }
        }
    }

    cout << answer;
    return 0;
}
