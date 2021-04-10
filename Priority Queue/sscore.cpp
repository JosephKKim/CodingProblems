#include <bits/stdc++.h>

using namespace std;
int s_score(int a, int b){
    return min(a, b) + 2*max(a,b);
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }

    while(pq.size()!=1){
        int f,s, new_score;
        f = pq.top(); 
        pq.pop();
        s = pq.top();
        pq.pop();
        new_score = s_score(f,s);
        pq.push(new_score); 
        answer++;
        if(pq.top()>= K)
            break;
    }

    if(pq.top() < K){
        answer = -1;
    }
    return answer;
}



/* 논리는 비슷하지만 매우매우 깔끔한 code*/

// #include <vector>
// #include <queue>

// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer = 0;
//     int needHot;
//     priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

//     while(pq.top()<K) {
//         if(pq.size()==1) return answer = -1;
//         needHot=pq.top(); pq.pop();
//         pq.push(needHot+pq.top()*2);
//         pq.pop(); answer++;
//     }

//     return answer;
// }