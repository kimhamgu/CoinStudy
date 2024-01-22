#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int total = 1;
    
    unordered_map<string, int> map;
    
    for(int i = 0; i < clothes.size(); i++)
    {
        map[clothes[i][1]]++;
    }
    
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        total *= (iter->second) + 1; 
    }
    
    answer = total - 1;
    
    return answer;
}
