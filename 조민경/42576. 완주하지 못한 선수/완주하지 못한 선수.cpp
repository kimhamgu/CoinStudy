#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> record;

    for(string completion_name : completion)
    {
        record[completion_name]++;

    }
    for(string name : participant)
    {
        if(record[name] > 0)
        {
            record[name]--;
        }
        else
        {
            return name;
        }
    }
  
}
