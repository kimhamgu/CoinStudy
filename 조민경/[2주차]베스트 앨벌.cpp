#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, int> genresCount;
    unordered_map<string, vector<pair<int, int>>> genresNumber;

    for (int i = 0; i < genres.size(); i++)
    {
        genresCount[genres[i]] += plays[i];
        genresNumber[genres[i]].emplace_back(i, plays[i]);
    }

    vector<pair<string, int>> vec(genresCount.begin(), genresCount.end());
    sort(vec.begin(), vec.end(), cmp);

    int first[2] = {0, 0};
    int second[2] = {0, 0};

    for (auto pair : vec)
    {
        auto it = genresNumber.find(pair.first);

        if (it != genresNumber.end())
        {
            for (auto pair : it->second)
            {
                if (second[1] < pair.second && first[1] > pair.second)
                {
                    second[0] = pair.first;
                    second[1] = pair.second;
                }
                else if(second[1] == pair.second)
                {
                    if(second[0] > pair.first)
                    {
                        second[0] = pair.first;
                        second[1] = pair.second;
                    }
                }
                else if (first[1] < pair.second)
                {
                    second[0] = first[0];
                    second[1] = first[1];
                    first[0] = pair.first;
                    first[1] = pair.second;
                }
                else if (first[1] == pair.second)
                {
                    if (first[0] > pair.first)
                    {
                        second[0] = first[0];
                        second[1] = first[1];
                        first[0] = pair.first;
                        first[1] = pair.second;
                    }
                    else
                    {
                        second[0] = pair.first;
                        second[1] = pair.second;
                    }
                }
            }

            answer.push_back(first[0]);
            if (it->second.size() > 1)
            {
                answer.push_back(second[0]);
            }

            fill_n(first, 2, 0);
            fill_n(second, 2, 0);
        }
    }

    return answer;
}
