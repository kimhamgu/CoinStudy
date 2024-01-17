#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, string>> genreNum;
    map<string, int> genreMap;
    map<int, int, greater<int>> playMap;
    vector<pair<int, int>> playNum;

    for (int i = 0; i < genres.size(); i++)
    {
        genreMap[genres[i]] += plays[i];
    }

    for (auto m : genreMap)
    {
        genreNum.push_back({ m.second, m.first });
    }

    sort(genreNum.rbegin(), genreNum.rend());

    for (auto v : genreNum)
    {
        for (int i = 0; i < genres.size(); i++)
        {
            if (v.second == genres[i])
            {
                //playMap.insert({ plays[i], i });
                playNum.push_back({ plays[i], i });
            }
        }

        sort(playNum.rbegin(), playNum.rend());

        if (playNum.size() > 1)
        {
            auto itFirst = playNum.begin();
            auto itSecond = itFirst;
            itSecond++;

            if (itFirst->first == itSecond->first && itFirst->second > itSecond->second)
            {
                answer.push_back(itSecond->second);
                answer.push_back(itFirst->second);
            }
            else
            {
                answer.push_back(itFirst->second);
                answer.push_back(itSecond->second);
            }
        }
        else
        {
            answer.push_back(playNum.begin()->second);
        }
        playNum.clear();
    }
    return answer;
}
