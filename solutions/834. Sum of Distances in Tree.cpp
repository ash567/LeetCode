class Solution {
private:
    
    int fillNumChildren(int root, vector<bool>& marked, vector<int>& numChildren, vector<int>& sumDistance, const vector<list<int> >& adjList) {
        sumDistance[root] = 0;
        numChildren[root] = 1;
        marked[root] = true;
        for(int node : adjList[root]) {
            if(!marked[node]) {
                int numInSubtree = fillNumChildren(node, marked, numChildren, sumDistance, adjList);
                sumDistance[root] += (numInSubtree + sumDistance[node]); 
                numChildren[root] += numInSubtree;
            }
        }
        return numChildren[root];
    }
    
    void fillSumDistance(int root, int N, vector<bool>& marked, vector<int>& numChildren, vector<int>& sumDistance, const vector<list<int> >& adjList) {
        marked[root] = true;
        for(int node : adjList[root]) {
            if(!marked[node]) {
                sumDistance[node] = sumDistance[root] + N - 2 * numChildren[node];
                fillSumDistance(node, N, marked, numChildren, sumDistance, adjList);
            }
        }
        return;
    }
​
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> numChildren(N);
        vector<int> sumDistance(N);
        vector<list<int> > adjList(N);
        for(auto const& edg : edges) {
            adjList[edg[0]].push_back(edg[1]);
            adjList[edg[1]].push_back(edg[0]);
        }
        // WLG, assuming head to be 0
        vector<bool> marked(N, false);
        int rootNode = 0;
        fillNumChildren(rootNode, marked, numChildren, sumDistance, adjList);
        marked = vector<bool>(N, false);
        fillSumDistance(rootNode, N, marked, numChildren, sumDistance, adjList);
        return sumDistance;
    }
};
