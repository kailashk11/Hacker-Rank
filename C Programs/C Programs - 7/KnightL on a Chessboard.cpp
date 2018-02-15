#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int is_inside(int x, int y, int n)
{
   return (x >= 0 && x < n && y >= 0 && y < n);
}

int find_minimum_moves_with(int a, int b, int n)
{
    int visited[n][n];
    memset(visited, false, sizeof(visited));

    int no_of_neighbours = 8;
    int x_step[] = {a, a, -a, -a, b, b, -b, -b};
    int y_step[] = {b, -b, b, -b, a, -a, a, -a};

    queue <int> X;
    queue <int> Y;
    queue <int> minimum_moves;

    X.push(0); Y.push(0); minimum_moves.push(0);
    visited[0][0] = true;

    while(!X.empty())
    {
        int x = X.front(); X.pop();
        int y = Y.front(); Y.pop();
        int min_moves = minimum_moves.front(); minimum_moves.pop();

        for(int i = 0; i < no_of_neighbours; i++)
        {
            int neighbour_x = x + x_step[i];
            int neighbour_y = y + y_step[i];

            if(neighbour_x == n - 1 && neighbour_y == n - 1)
            {
                return (min_moves + 1);
            }

            if(is_inside(neighbour_x, neighbour_y, n) && !visited[neighbour_x][neighbour_y])
            {
                X.push(neighbour_x);
                Y.push(neighbour_y);
                minimum_moves.push(min_moves + 1);

                visited[neighbour_x][neighbour_y] = true;
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int minimum_moves[n][n];

    for(int a = 1; a < n; a++)
    {
        for(int b = a; b < n; b++)
        {
            minimum_moves[a][b] = find_minimum_moves_with(a, b, n);
            minimum_moves[b][a] = minimum_moves[a][b];
        }
    }

    for(int a = 1; a < n; a++)
    {
        for(int b = 1; b < n; b++)
        {
            printf("%d ", minimum_moves[a][b]);
        }
        printf("\n");
    }

    return 0;
}