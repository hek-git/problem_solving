#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string lower_case(string& s){
    int diff = 'A' - 'a';
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] -= diff;
    }
    return s;
}

void p(queue<string>& cache){
    queue<string> q = cache;
    while(!q.empty()){
        cout << q.front()<< " ";
        q.pop();
    }
    cout << endl;
}

bool caching(queue<string>& cache, string& s){
    bool hit = false;
    int cache_size = cache.size();
    if(cache.empty()) return hit;
    for(int i = 0; i < cache_size; i++){
        string tmp = cache.front();
        if(!tmp.compare(s)){
            hit = true;
            cache.pop();
        } else{
            cache.push(tmp);
            cache.pop();
        }
    }
    if(hit) cache.push(s);
    // cout << s <<"! ";
    // p(cache);
    return hit;
}

void cache_change(queue<string>& cache, string& s){
    cache.pop();
    cache.push(s);
    // p(cache);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> cache;

    for(int i = 0; i < cities.size(); i++){
        string city = lower_case(cities[i]);
        
        if(caching(cache, city)) answer++;
        else{
            answer += 5;
            if(cache.size() < cacheSize) cache.push(city);
            else if(cacheSize) cache_change(cache, city);
        }       
        // p(cache);
    }
    return answer;
}