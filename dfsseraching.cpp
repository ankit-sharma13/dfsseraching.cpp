#include<iostream>
using namespace std;
#define MAX 20

int main() {
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX];
    int st[MAX];
    int top = -1;

    cout << "Enter the no.of nodes:";
    cin >> n;
    cout << "Enter adjacent matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    cout << "Enter the starting node:";
    char s;
    cin >> s;
    start = s - 'A';
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    // Start DFS
    st[++top] = start;
    visited[start] = 1;
    cout << "DFS Traversal:";
    while (top != -1) {
        int node = st[top--];
        cout << char(node + 'A') << " ";
        // pushing neighbours in reverse for correct order
        for (int i = n - 1; i >= 0; i--) {
            if (adj[node][i] == 1 && !visited[i]) {
                st[++top] = i;
                visited[i] = 1;
            }
        }
    }
   return 0;
}
