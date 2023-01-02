// https://leetcode.com/problems/bulls-and-cows/
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char, pair<int, set<int>>> mp;
        int n = secret.size();
        for (int i = 0; i < n; i++)
        {
            mp[secret[i]].second.insert(i);
            mp[secret[i]].first++;
        }
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(guess[i]))
            {
                if (mp[guess[i]].second.count(i))
                {
                    bulls++;
                    mp[guess[i]].second.erase(i);
                    mp[guess[i]].first--;
                    guess[i] = 'a';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (guess[i] == 'a')
                continue;
            if (mp.count(guess[i]) && mp[guess[i]].first)
                mp[guess[i]].first--, cows++;
        }
        return (to_string(bulls) + "A" + to_string(cows) + "B");
    }
};