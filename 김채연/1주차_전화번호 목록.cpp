#include <string>
#include <vector>
#include <unordered_map>

//해시[phone_book]마다 1 넣어줌.

bool solution(vector<string> phone_book) {

    unordered_map<string, int> m;

    string answer = "";

    for (int i = 0; i < phone_book.size(); i++)
    {
        m[phone_book[i]] = 1;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        answer = "";

        for (int j = 0; j < phone_book[i].size(); j++)
        {
            answer += phone_book[i][j];

            if (m[answer] && answer != phone_book[i])
            {
                //cout << "false" << endl;
                return false;
            }
        }
    }

    // cout << "true" << endl;
    return true;
}