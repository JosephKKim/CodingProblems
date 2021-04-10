#include <string>
#include <vector>

using namespace std;
bool isFeasible(vector<int>& citations, int mid)
{
    int cnt = 0;
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] >=  mid)
            cnt++;
    }
    return cnt >= mid;
}

int solution(vector<int> citations) {
    int hi, lo, mid;
    hi = citations.size();
    lo = 0;
    int answer = 0;
    while(lo <= hi){
        mid = (hi + lo)/2;
        if(isFeasible(citations, mid)){
            // when possible
            lo = mid+1;
            answer = mid;
        }else{
            hi = mid-1;
        }
    }
    
    return answer;
}