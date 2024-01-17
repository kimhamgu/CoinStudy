#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

bool genlistSort(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool playslistSort(pair<int, int> a, pair<int, int> b)
{
    //어차피 기본정렬이 오름차순이여서 필요가 없었다.
    //if(a.first > b.first)
    //{
    //    return a.first > b.first;
    //}
    //else if(a.first == b.first)
    //{
    //    return a.second < b.second;
    //}

    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genlist;   //값 받는용
    vector<pair<string, int>> genlistv;

    for (int i = 0; i < genres.size(); i++)   //값을 받아온다.
        genlist[genres[i]] += plays[i];

    genlistv.assign(genlist.begin(), genlist.end()); //vector에 복사
    sort(genlistv.begin(), genlistv.end(), genlistSort);    //값기준 정렬

    for (int i = 0; i < genlistv.size(); i++)    //장르순으로 높은 값
    {
        vector<pair<int, int>> playslist;   //노래 정렬용
        string currGenres = genlistv[i].first;

        for (int j = 0; j < genres.size(); j++)
        {
            if (genres[j] == currGenres)    //장르가 같다면
                playslist.push_back({ plays[j], j });
        }

        sort(playslist.begin(), playslist.end(), playslistSort);

        for (int j = 0; j < playslist.size() && j < 2; j++)  //상위 두개만 넣는다.
        {
            answer.push_back(playslist[j].second);
        }
    }

    return answer;
}