#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    string answer = "";
    for(int i = 0; i < participant.size(); i++){
        m.insert({participant[i], 0});
    }
    for(int i = 0; i < participant.size(); i++){
        m[participant[i]]++;
    }
    for(int i = 0; i < completion.size(); i++){
        m[completion[i]]--;
    }
    for(int i = 0; i < participant.size(); i++){
        if(m[participant[i]] != 0){
            answer = participant[i];
        }
    }
    return answer;
}

// 깔끔한 풀이

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     string answer = "";
//     sort(participant.begin(), participant.end());
//     sort(completion.begin(), completion.end());
//     for(int i=0;i<completion.size();i++)
//     {
//         if(participant[i] != completion[i])
//             return participant[i];
//     }
//     return participant[participant.size() - 1];
//     //return answer;
// }



// Hashmap 이용 풀이
// #include <string>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     string answer = "";
//     unordered_multiset<string> names;

//     for(int i = 0; i < participant.size(); i++)
//     {
//         names.insert(participant[i]);
//     }

//     for(int i = 0; i < completion.size(); i++)
//     {
//         unordered_multiset<string>::iterator itr = names.find(completion[i]);
//         names.erase(itr);
//     }

//     return *names.begin();
// }
