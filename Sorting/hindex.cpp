#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    while(answer){
        int cnt = 0; 
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= answer){
                cnt++;    
            }
        }
        if(cnt < answer){
            answer--;
        }else{
            break;
        }
    }
    
    return answer;
}