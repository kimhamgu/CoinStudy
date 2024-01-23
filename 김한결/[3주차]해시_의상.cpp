#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    unordered_map<string, int> style;

    // 옷 종류별로 구별 
    for (auto clothe : clothes)
    {
        style[clothe[1]]++; // 두 번째 요소를 키로 
    }

    for (auto cases : style)
    {
        answer *= cases.second + 1; // 입지 않은 경우까지 포함
    }

    return answer - 1; // 다 안입은 경우 빼주기
}
