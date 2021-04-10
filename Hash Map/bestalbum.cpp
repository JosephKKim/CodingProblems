#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ids;
vector<map<int, int>> sep;
map<string, int> g;



bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	return a.second > b.second;
}

bool cmp2(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < genres.size(); i++){
        g.insert({genres[i],0});
    }
    for(int i = 0; i < genres.size(); i++){
        g[genres[i]] += plays[i];
    }

    vector<pair<string,int>> sortedmap(g.begin(), g.end());
    
    sort(sortedmap.begin(), sortedmap.end(), cmp);
    // cout << "sortedmap.size(): " << sortedmap.size() << endl;

    for(int i = 0; i < sortedmap.size(); i++){
        string genre = sortedmap[i].first;
        map<int, int> idplays;
        for(int j = 0; j < genres.size(); j++){
            if(genres[j] == genre){
                idplays.insert({j, plays[j]});
            }
        }  
        sep.push_back(idplays);
    }

    // error sep size
    // sep is a vector of maps
    for(int i = 0; i < sep.size(); i++){
        cout << sep.size() << endl;
        map<int, int> m = sep[i];
        vector<pair<int, int>> v(m.begin(), m.end()); // has genre i's id and plays
        sort(v.begin(), v.end(), cmp2); // sort by plays
        
        for(int j = 0; j < v.size(); j++){
            if(j > 1) break;
            answer.push_back(v[j].first);
        }
        cout << endl;
    }
    


    return answer;
}



// 좋아요 가장 많이 받은 코드

// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <utility>

// using namespace std;
// bool compare (pair<int, int> left, pair<int, int> right){
//     if(left.first > right.first){
//         return true;
//     }else if(left.first == right.first){
//         if(left.second < right.second){
//             return true;
//         }
//     }
//     return false;
// }

// vector<int> solution(vector<string> genres, vector<int> plays) {
//     vector<int> answer;
//     unordered_map<string, int> summap;
//     unordered_map<string, vector<pair<int, int>>> genmap;
//     for (int i = 0; i < genres.size(); i++) {
//         summap[genres[i]] += plays[i];
//         genmap[genres[i]].push_back(make_pair(plays[i], i));
//     }
//     vector<pair<int, string>> fororder;
//     for (auto x : summap) {
//         fororder.push_back(make_pair(x.second, x.first));
//     }
//     sort(fororder.begin(), fororder.end());
//     while (fororder.size() > 0) {
//         pair<int, string> temp= fororder.back();
//         fororder.pop_back();
//         vector<pair<int, int>> a = genmap[temp.second];
//         sort(a.begin(), a.end(), compare);
//         int lastn = 2;
//         if (a.size() < 2) {
//             lastn = a.size();
//         }
//         for (int i = 0; i < lastn; i++) {
//             answer.push_back(a[i].second);
//         }
//     }

//     return answer;
// }
