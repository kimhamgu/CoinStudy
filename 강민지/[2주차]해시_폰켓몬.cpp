#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;
    
    for(int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    
    int numSize = nums.size()/2;
    
    if(map.size() >= numSize)
        return numSize;
    else
        return map.size();
}
