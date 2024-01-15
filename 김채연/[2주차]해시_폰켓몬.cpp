#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (answer >= nums.size() / 2)
            break;

        if (m[nums[i]] == 1)
        {
            m[nums[i]] = 0;

            answer++;
        }
    }

    //cout << answer;

    return answer;
}