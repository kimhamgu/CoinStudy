#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;

    for (auto number : nums)
    {
        if (map.find(number) == map.end())
        {
            map.insert({ number, 1 });
        }
    }

    if (map.size() > nums.size() / 2)
    {
        return nums.size() / 2;
    }

    return map.size();
}
