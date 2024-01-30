#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> temp;

    for (int i = 0; i < commands.size(); i++)
    {
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            temp.push_back(array[j]);                                       // temp에 i-j까지 넣어줌.

        sort(temp.begin(), temp.end());                                     // 정렬

        answer.push_back(temp[commands[i][2] - 1]);                         // answer에 k번째 수를 넣어줌.

        temp.clear();                                                       // temp 비워줌.
    }

    return answer;
}