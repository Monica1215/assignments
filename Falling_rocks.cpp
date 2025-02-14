#include <bits/stdc++.h>
using namespace std;

const char rock = 'R', _empty='E', you = 'Y';

bool there_is_rock(char **matrix, int des, int time)
{
    return (matrix[time][des] == rock);
}

bool avoid_rocks(char **matrix, int destination, int time, int w, int h)
{
    if (destination<0 || destination>=w ) return false;
    if (time == h) return true;
    if (time!=0)
        if (there_is_rock(matrix, destination, time) || there_is_rock(matrix, destination, time-1))
        return false;
    return (avoid_rocks(matrix, destination, time+1, w, h) ||
            avoid_rocks(matrix, destination-1, time+1, w, h)||
            avoid_rocks(matrix, destination+1, time+1, w, h));

}

int main()

{
    int w,h;
    cin >> w >> h;
    char **matrix = new char* [h];
    for (int i=0;i<h;i++)
    {
        matrix[i]=new char [w];
        for (int j=0;j<w;j++)
            cin >> matrix[i][j];
    }
    int my_pos;
    for (int i=0;i<w;i++)
    if (matrix[0][i] == you) {
        my_pos = i;
        break;
    }

    string s = avoid_rocks(matrix, my_pos, 0, w, h) ? "YES" : "NO";
    cout << s;

    for (int i=0;i<h;i++) delete[] matrix[i];
    delete[] matrix;
    return 0;
}
