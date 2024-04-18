#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 입국심사를 기다리는 사람수 n
// 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열 times
long long solution(int n, vector<int> times) {
    // 모든 사람이 심사를 받는데 걸리는 시간의 최솟값
    long long answer = 0;
    
    // 시간에 대해 오름차순 정렬
    sort(times.begin(), times.end());
    
    long long left = 1;     // 최소 시간
    long long right = n * (long long)times.back();  // 최대 시간
    
    while(left <= right){
        long long mid = (left + right) / 2;
        long long passed_cnt= 0;   // 지나간 사람의 수
        
        for(int i = 0; i < times.size(); i++){
            passed_cnt += (mid / (long long)times[i]);
        } // End of for()
        
        if(passed_cnt >= n){
            right = mid - 1;
            answer = mid;
        }else{
            left = mid + 1;
        } // End of if()
    } // End of while()
    
    return answer;
} // End of solution()
