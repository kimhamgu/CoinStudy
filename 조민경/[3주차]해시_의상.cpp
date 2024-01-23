#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> cony_clothes;
    int answer = 1;

    for(auto clothes_type : clothes)
    {
        cony_clothes[clothes_type[1]]++;
    }
    
    for(auto types : cony_clothes)
    {
        answer *= (types.second+1);
    }
    return answer-1;
}
