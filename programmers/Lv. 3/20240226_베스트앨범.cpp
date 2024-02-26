#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer, genre_play(101, 0);
    map<string, int> genre_m;
    map<int, int> genre_num_m;
    vector<pair<int, int>> playlist[101];
    int idx = 0;
    for (int i = 0; i < genres.size(); i++) {
        if (genre_m.find(genres[i]) == genre_m.end()) genre_m[genres[i]] = idx++;
        playlist[genre_m[genres[i]]].push_back(make_pair(plays[i], i));
        genre_play[genre_m[genres[i]]] += plays[i];
    }

    for (int i = 0; i < genre_m.size(); i++) genre_num_m[genre_play[i]] = i;
    for (int i = 0; i < genre_m.size(); i++) sort(playlist[i].begin(), playlist[i].end(), cmp);
    for (auto a = genre_num_m.rbegin(); a != genre_num_m.rend(); a++){
        if(playlist[(*a).second].size() == 1) answer.push_back(playlist[(*a).second][0].second);
        else{
            answer.push_back(playlist[(*a).second][playlist[(*a).second].size() - 1].second);
            answer.push_back(playlist[(*a).second][playlist[(*a).second].size() - 2].second);
        }
    }
    return answer;
}