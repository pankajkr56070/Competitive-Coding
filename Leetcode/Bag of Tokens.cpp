// Link : https://leetcode.com/problems/bag-of-tokens/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Approach:  Greedy + Two Pointers + Sorting
int bagOfTokensScore(vector<int> &tokens, int power)
{
    if (tokens.size() == 0)
    {
        return 0;
    }
    sort(tokens.begin(), tokens.end());
    if (power < tokens[0])
    {
        return 0;
    }
    int score = 0;
    int max_score = 0;
    int left = 0;
    int right = tokens.size() - 1;

    while (left <= right)
    {
        if (power >= tokens[left])
        {
            power -= tokens[left];
            score++;
            left++;
            max_score = max(max_score, score);
        }
        else
        {
            if (score >= 1)
            {
                power += tokens[right];
                score--;
                right--;
            }
            else
            {
                break;
            }
        }
    }
    return max_score;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int power;
        cin >> power;

        cout << bagOfTokensScore(v, power) << endl;
    }

    return 0;
}