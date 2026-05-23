
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>


using namespace std;

void DFS(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

void BFS(int start, vector<vector<int>>& matrix) {
    vector<bool> visited(matrix.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < static_cast<int>(matrix.size()); i++) {
            if (matrix[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {

    ifstream matrixFile("adj_matrix.txt");

    if (!matrixFile) {
        cout << "Error opening adj_matrix.txt" << endl;
        return 1;
    }

    vector<vector<int>> matrix;
    int value;

    while (matrixFile >> value) {
        vector<int> row;
        row.push_back(value);

        for (int i = 1; i < 6; i++) {
            matrixFile >> value;
            row.push_back(value);
        }

        matrix.push_back(row);
    }

    matrixFile.close();

    cout << "BFS (Adjacency Matrix): ";
    BFS(0, matrix);
    cout << endl;

    ifstream listFile("adj_list.txt");

    if (!listFile) {
        cout << "Error opening adj_list.txt" << endl;
        return 1;
    }

    vector<vector<int>> adjList;
    string line;

    while (getline(listFile, line)) {
        vector<int> neighbors;

        for (int i = 3; i < static_cast<int>(line.length()); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                neighbors.push_back(line[i] - '0');
            }
        }

        adjList.push_back(neighbors);
    }

    listFile.close();

    cout << "DFS (Adjacency List): ";

    vector<bool> visited(adjList.size(), false);
    DFS(0, adjList, visited);

    cout << endl;

    return 0;
}
