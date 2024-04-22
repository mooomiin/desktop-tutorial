#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int idx = 0;    // 차량 지목용 idx
    int sum = 0;    // 현재 다리에 올라와있는 차량 무게 총합
    queue<int> q;   // 현재 다리를 건너는 트럭 체크용 큐

    while (1) {
        // 마지막 트럭일 때
        if (idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }

        answer++; //시간초 증가
        int tmp = truck_weights[idx];

        //차가 다리를 다 건넜을 경우
        if (q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }

        if (sum + tmp <= weight) {
            sum += tmp;
            q.push(tmp);
            idx++;
        }
        else {
            q.push(0);
        } // Emd of if
    } // End of while()

    return answer;
} // End of while
