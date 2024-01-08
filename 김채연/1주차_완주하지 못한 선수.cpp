//C++ STL�� unordered_map�� ����ؼ� Ǯ�����ϴ�.���� ������ ��� �����մϴ�.
//key�� ���������� �̸�, value�� 1(����)�� insert�մϴ�.����, �ߺ��� �ִٸ� + 1 ���ݴϴ�.
//������ ������� ���ؼ� - 1�� ���ݴϴ�.
//�� ����� 0���� ũ�ٸ� �ش� ������ �������� ���� �����Դϴ�.

//�ؽø� ����ϰų� ���͸� ��Ʈ�ؼ� Ǯ�ų� 

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//�ؽ�
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> m;
    // ���� ���� 
    for (int i = 0; i < participant.size(); i++) {
        if (m.find(participant[i]) == m.end()) {
            m.insert(make_pair(participant[i], 1));
        }
        else {
            m[participant[i]]++;
        }
    }

    // ������ ����
    for (int i = 0; i < completion.size(); i++) {
        m[completion[i]]--;
    }

    // �������� ���� ����
    for (int i = 0; i < participant.size(); i++) {
        if (m[participant[i]] > 0) {
            answer = participant[i];
        }
    }

    return answer;
}

//���͸� ��Ʈ
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // ���� ���� �� ���� ���� ����
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // �߰��� ���� ã�Ҵ��� Ȯ���ϴ� Flag
    bool flag = false;

    // ���� ������ ���� ���� ���� ��, ��
    for (int i = 0; i < completion.size(); i++) {
        if (completion[i] != participant[i]) {
            answer = participant[i];
            flag = true;
            break;
        }
    }

    // �� for������ ��ã�Ҵٸ� participant�� ������ ���Ұ� ����
    if (flag == false) {
        int lastIndex = participant.size() - 1;
        answer = participant[lastIndex];
    }

    return answer;
}