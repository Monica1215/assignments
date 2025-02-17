#include <bits/stdc++.h>
using namespace std;

const int N=10;
vector<string> result;

bool canPlaceHorizontally(int r, int c, string word)
{
    if (c+word.size() > N) return false;
    for (int i=0;i<word.size();i++)
    {
        if (result[r][c+i] != '-' && result[r][c+i] != word[i]) return false;
    }
    return true;
}

vector<bool> placeHorizontally(int r, int c, string word)
{
    vector<bool> placed(word.size());
    for (int i=0;i<word.size();i++)
    {
        if (result[r][c+i]=='-')
        {
            placed[i]=true;
            result[r][c+i]=word[i];
        }
        else placed[i]=false;
    }
    return placed;
}

void removeHorizontally(int r, int c, vector<bool> placed)
{
    int n = placed.size();
    for (int i=0;i<n;i++)
    {
        if (placed[i]) result[r][c+i] = '-';
    }
}

bool canPlaceVertically(int r, int c, string word)
{
    if (r+word.size() > N) return false;
    for (int i=0;i<word.size();i++)
    {
        if (result[r+i][c] != '-' && result[r+i][c] != word[i]) return false;
    }
    return true;
}

vector<bool> placeVertically(int r, int c, string word)
{
    vector<bool> placed(word.size());
    for (int i=0;i<word.size();i++)
    {
        if (result[r+i][c]=='-')
        {
            placed[i]=true;
            result[r+i][c]=word[i];
        }
        else placed[i]=false;
    }
    return placed;
}

void removeVertically(int r, int c, vector<bool> placed)
{
    int n = placed.size();
    for (int i=0;i<n;i++)
    {
        if (placed[i]) result[r+i][c] = '-';
    }
}

bool solve(vector<string> word_list, int ind)
{
    if (ind==word_list.size()) return true;
    string word = word_list[ind];

    for (int r=0;r<N;r++)
    {
        for (int c=0;c<N;c++)
        {
            if (canPlaceHorizontally(r,c,word))
            {
                vector<bool> placed = placeHorizontally(r,c,word);
                if (solve(word_list, ind +1)) return true;
                removeHorizontally(r,c,placed);
            }
            if (canPlaceVertically(r,c,word))
            {
                vector <bool> placed = placeVertically(r,c,word);
                if (solve(word_list, ind+1)) return true;
                removeVertically(r,c,placed);
            }
        }
    }
    return false;
}

int main()
{

    for (int i=0;i<N;i++)
    {
        string line;
        cin >>  line;
        result.push_back(line);
    }
  //  for (int i=0;i<N;i++) cout << result[i] << endl;


    string words;
    cin >> words;
    stringstream ss(words);
    string word;
    vector <string> word_list;
    while (getline(ss, word, ';'))
    {
        word_list.push_back(word);
      //  cout << word << endl;
    }

   if (solve(word_list, 0))
    {
        for (int i=0; i<N;i++)
            cout << result[i] << endl;
    }

    return 0;
}
