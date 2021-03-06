#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &is_abundant, vector <int> &abundant, int LIMIT)
{
    vector <int> largest_prime_factor(LIMIT, 0);
    vector <int> divisor_sum(LIMIT, 1);

    for(int i = 2; i < LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple < LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }

        int p = largest_prime_factor[i], p_power_alpha = 1;
        int reduced_i = i;

        while(reduced_i%p == 0)
        {
            reduced_i /= p;
            p_power_alpha *= p;
        }

        int gp_sum = (p*p_power_alpha - 1)/(p - 1);
        divisor_sum[i] = gp_sum*divisor_sum[reduced_i];
    }

    for(int i = 1; i < LIMIT; i++)
    {
        if(divisor_sum[i] > 2*i)
        {
            is_abundant[i] = true;
            abundant.push_back(i);
        }
    }
}

void solve(vector <int> &is_abundant, vector <int> &abundant)
{
    int n;
    scanf("%d", &n);

    int sum_possible = false;
    for(int i = 0; i < abundant.size() && abundant[i] < n; i++)
    {
        if(is_abundant[n - abundant[i]])
        {
            sum_possible = true;
            break;
        }
    }

    printf(sum_possible ? "YES\n" : "NO\n");
}

int main()
{
    const int LIMIT = 28123;
    vector <int> is_abundant(LIMIT, false);
    vector <int> abundant;
    precompute(is_abundant, abundant, LIMIT);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve(is_abundant, abundant);

    return 0;
}

