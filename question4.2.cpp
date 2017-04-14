#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


vector<pair<int, int>> setGraph(vector<vector<int>>& matrix) {
    vector<pair<int, int>> graph;
    for(int i = 0; i < matrix.size(); i++) {
        graph.push_back({matrix[i][0], matrix[i][1]});
        cout << matrix[i][0] << " " << matrix[i][1] << endl;
    }
    return graph;
}


bool findPath(vector<pair<int, int>>& graph, int start, int end) {
    queue<pair<int, int>> visit;
    set<int> visited;
    visit.push({INT_MAX, start});
    visited.insert(start);
    while(!visit.empty()) {
        pair<int, int> pre = visit.front();
        visit.pop();
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].first == pre.second && visited.find(graph[i].second) == visited.end()) {
                if(graph[i].second == end) return true;
                visited.insert(graph[i].second);
                visit.push(graph[i]);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> input = {{1, 2}, {1, 4}, {2, 3}, {2, 5}, {2, 6}, {3, 6}, {4, 7}, {6, 2}, {7, 1}};
    vector<pair<int, int>> graph = setGraph(input); // directed map
    
    int start = 6;
    int end = 5;
    bool index = findPath(graph, start, end);
    if(index) cout << "True" << endl;
    else cout << "False" << endl;
    
    return 1;
}


