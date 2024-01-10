#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> map;

    sort(phone_book.begin(), phone_book.end());

    for (auto number : phone_book)
    {
        map.insert(make_pair(number, 1));
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j < phone_book[i].size(); j++)
        {
            string str = phone_book[i].substr(0, j);
            if (map.end() != map.find(str))
            {
                return false;
            }
        }
    }
    return true;
}
