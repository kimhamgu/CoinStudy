#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> cmdArray;

    for (int i = 0; i < commands.size(); i++)
    {
        for (int j = commands[i][0]; j <= commands[i][1]; j++)
        {
            cmdArray.push_back(array[j - 1]);
        }

        sort(cmdArray.begin(), cmdArray.end());
        answer.push_back(cmdArray[commands[i][2] - 1]);
        cmdArray.clear();
    }

    return answer;
}
