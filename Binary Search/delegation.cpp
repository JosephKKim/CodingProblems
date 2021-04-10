#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long lo, hi, mid;
    hi = (long long)((ll)n * times[0]);
    lo = 1;
    while(lo <= hi){
        mid = (hi + lo)/ 2;
        ll cnt = 0;
        for(int i = 0; i < times.size(); i++){
            cnt += mid/times[i];
        }
        if(cnt >= n){
            answer = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }


    return answer;
}


int main()
{  
    vector<int> times;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        times.push_back(t);
    }

    long long answer;
    answer = solution(m, times);

    cout << answer << endl;




    return 0;
}