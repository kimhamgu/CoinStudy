#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> totalMusic; // 장르별 총 플레이 횟수
    map<string, map<int, int>> musicList; // 장르별 {순서, 플레이 횟수}
    
    for(int i = 0; i < genres.size(); i++)
    {
        totalMusic[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }
    
    while(totalMusic.size() > 0)
    {
        string genre = "";
        int max = 0;
        
        // 재생횟수가 제일 큰 장르 찾기
        for(auto iter = totalMusic.begin(); iter != totalMusic.end(); iter++)
        {
            if(max < iter->second)
            {
                max = iter->second;
                genre = iter->first;
            }
        }
        
        // 2회 반복
        for(int i = 0; i < 2; i++)
        {
            int val = 0;
            int index = -1;
            
            // 장르 중 재생횟수가 제일 많은 노래 찾기
            for(auto iter = musicList[genre].begin(); iter != musicList[genre].end(); iter++)
            {
                if(val < iter->second)
                {
                    val = iter->second;
                    index = iter->first;
                }
            }
            
            // 장르에 속한 곡이 1곡 이하일때
            if(index == -1) break;
            
            answer.push_back(index);        // 답에 index 기록
            musicList[genre].erase(index);  // 찾은 노래는 지우기
        }
        
        totalMusic.erase(genre); // 2곡 찾은 장르는 지우기
    }

    
    return answer;
}
