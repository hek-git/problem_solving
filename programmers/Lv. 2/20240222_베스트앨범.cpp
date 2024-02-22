#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first) return a > b;
    return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer, genre_play(101, 0);
    map<string, int> genre_m;
    map<int, int> genre_num_m;
    vector<pair<int, int>> playlist[101];
    int idx = 0;
    for(int i = 0; i < genres.size(); i++){
        if(genre_m.find(genres[i]) == genre_m.end()) genre_m[genres[i]] = idx++;
        playlist[genre_m[genres[i]]].push_back(make_pair(plays[i], i));
        genre_play[genre_m[genres[i]]] += plays[i];
    }

    for(int i = 0; i < genre_m.size(); i++) genre_num_m[genre_play[i]] = i;
    for(int i = 0; genre_m.size(); i++) sort(playlist[i].begin(), playlist[i].end(), cmp);
    for(auto m : genre_num_m){
        if(playlist[m.second].size() == 1){
            answer.push_back();
        }
    }

    // for(auto a : genre_m){
    //     cout << a.first << " " << a.second <<endl;
    // }
    // cout << endl;

    // for(int i = 0; i < genre_m.size(); i++){
    //     cout << i << " : " << genre_play[i] << endl;
    // }
    // cout << endl;

    // for(int i = 0; i < genre_m.size(); i++){
    //     for(int j = 0; j < playlist[i].size(); j++){
    //         cout << playlist[i][j].first << " " << playlist[i][j].second << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(auto a : genre_num_m){
    //     cout << a.first << " " << a.second <<endl;
    // }
    // cout << endl;

    return answer;
}