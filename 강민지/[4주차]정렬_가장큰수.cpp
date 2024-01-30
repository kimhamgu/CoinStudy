#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(int i, int j)
{
    string tempI = to_string(i);
    string tempJ = to_string(j);
    
    string compareString1 = tempI+tempJ;
    string compareString2 = tempJ+tempI;
    
    return compareString1 > compareString2;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for(int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}
