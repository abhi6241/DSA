class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<bool>& visited) {
        // Index is outside the array
        if(i < 0 || i >= arr.size()) return false;

        // Already visited this index
        if(visited[i]) return false;

        // Mark current index as visited
        visited[i] = true;

        // Reached a position containing 0
        if(arr[i] == 0) return true;

        // Try jumping left or right
        return dfs(arr, i + arr[i], visited) ||
                dfs(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);

        return dfs(arr, start, visited);
    }
};