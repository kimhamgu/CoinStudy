//C++ STL인 unordered_map을 사용해서 풀었습니다.참가 선수를 모두 삽입합니다.
//key는 참가선수의 이름, value는 1(정수)로 insert합니다.만약, 중복이 있다면 + 1 해줍니다.
//완주한 선수들과 비교해서 - 1을 해줍니다.
//이 결과가 0보다 크다면 해당 선수가 완주하지 못한 선수입니다.

//해시를 사용하거나 벡터를 소트해서 풀거나 

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//해시
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> m;
    // 참가 선수 
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            m.insert(make_pair(participant[i], 1));
        }
        else {
            m[participant[i]]++;
        }
    }

    // 완주한 선수
    for (int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }

    // 완주하지 못한 선수
    for (int i = 0; i < participant.size(); i++) {
        if (m[participant[i]] > 0) {
            answer = participant[i];
        }
    }

    return answer;
}

//벡터를 소트
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 참가 선수 및 완주 선수 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 중간에 답을 찾았는지 확인하는 Flag
    bool flag = false;

    // 참가 선수와 완주 선수 정렬 후, 비교
    for (int i = 0; i < completion.size(); i++) {
        if (completion[i] != participant[i]) {
            answer = participant[i];
            flag = true;
            break;
        }
    }

    // 위 for문에서 못찾았다면 participant의 마지막 원소가 정답
    if (flag == false) {
        int lastIndex = participant.size() - 1;
        answer = participant[lastIndex];
    }

    return answer;
}