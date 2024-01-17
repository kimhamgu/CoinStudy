#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size() / 2;
    unordered_map<int, int> record;
    
    for(int num : nums)
    {
        record[num]++;
    }
    
    if(n>record.size())
    {
        answer = record.size();
    }
    else 
    {
        answer = n;
    }

    return answer;
}
