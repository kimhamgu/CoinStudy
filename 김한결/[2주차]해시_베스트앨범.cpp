#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    map<string, int> musicPlay; // 장르의 총 재생 수
    map<string, map<int, int>> musicList; // 각 장르 별 노래 재생 수

    for (int i = 0; i < genres.size(); i++)
    {
        musicPlay[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }

    while (musicPlay.size() > 0)
    {
        int max = 0;
        string genre;
        for (auto mp : musicPlay)
        {
            if (max < mp.second)
            {
                max = mp.second;
                genre = mp.first;
            }
        }

        for (int j = 0; j < 2; j++)
        {
            int play = 0, index = -1;
            for (auto ml : musicList[genre])
            {
                if (play < ml.second)
                {
                    play = ml.second;
                    index = ml.first;
                }
            }
            if (index == -1) break;

            answer.push_back(index);
            musicList[genre].erase(index);
        }
        musicPlay.erase(genre);
    }
    return answer;
}
