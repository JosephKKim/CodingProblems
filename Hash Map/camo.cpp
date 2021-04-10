#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    for(int i = 0; i < clothes.size(); i++){
        vector<string> v = clothes[i];
        string category, name;
        for(int j = 0; j < 2; j++){
            if(j == 0){
                name = v[j];
            }else{
                category = v[j];
            }
        }
        m.insert({category, 0});
    }

    for(int i = 0; i < clothes.size(); i++){
        vector<string> v = clothes[i];
        m[v[1]]++; 
    }
    
    answer = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        answer *= (iter->second+1);
    }
    
    answer = answer - 1;

    return answer;
}

// 수학 공식.... 보면 이해가 되는데... 풀어내지 못함
// + map 사용법 아래처럼 하는 거 익힐것.

// #include <string>
// #include <vector>
// #include <map>

// using namespace std;

// int solution(vector<vector<string>> clothes) {
//     map<string,int> m; //옷의 종류를 key 해당 종류의 수를 value로 하는 map함수
//     vector<string> v; //옷의 종류를 저장해놓을 벡터함수
//     for(int i=0; i<clothes.size(); i++)
//     {
//         if(m[clothes[i][1]] == 0){ //처음 나오는 옷의 종류라면
//             m[clothes[i][1]] = 1;
//             v.push_back(clothes[i][1]);
//         }
//         else
//         {
//             m[clothes[i][1]]++;
//         }
//     }
//     int result = 1;
//     for(int i=0; i<v.size(); i++)
//     {
//         result *= (m[v[i]]+1);
//     }
//     return result-1;
// }