#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        int st = commands[i][0]-1;
        int ed = commands[i][1]-1;
        int k = commands[i][2]-1;
        vector<int> subarr;
        
        for(int j = st; j <= ed; j++){
            subarr.push_back(array[j]);
        }
        sort(subarr.begin(), subarr.end());
        answer.push_back(subarr[k]);
        subarr.clear();
    }
    
   
    return answer;
}


// example simple code + Review

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//     vector<int> answer;
//     vector<int> temp;

//     for(int i = 0; i < commands.size(); i++) {
//         temp = array;
//         sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]); // 연속된 부분을 보고 있다는 것에 주목하고 있는것 같다.
//         answer.push_back(temp[commands[i][0] + commands[i][2]-2]); // indexing을 훌륭하게 사용하고 있다.
//     }

//     return answer;
// }