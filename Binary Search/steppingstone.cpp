#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int lo, hi, mid;
    lo = 1;
    hi = distance;

    while(lo <= hi){
        int cnt = 0;
        mid = (lo + hi) / 2;
        
        if(rocks[0] >= mid) cnt++;
        for(int i = 1; i < rocks.size(); i++){
            int cur = rocks[i];
            if(cur-rocks[i-1] >= mid){
                cnt++;
            }
        }
        if(distance - rocks[rocks.size()-1] >= mid) cnt++;
   
        
        if(cnt >= rocks.size()-n){
            answer = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
        
    }
        return answer;
}
