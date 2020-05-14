## Brute Force solution for Longest palindromic 
-class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        int mxlen = 0, start = 0;
        
        for (int i = 0; i < n; i++) {
            
            int j = i;
            int k = i;
            
            while (k+1 < n && s[k] == s[k+1]) k++;
            
            while (j-1 >= 0 && k+1 < n && s[j-1] == s[k+1]) {
                j--; k++;
            }
            
            if (mxlen < k-j+1) {
                mxlen = k-j+1;
                start = j;
            }
        }
        
        return s.substr(start, mxlen);
    }
};

## Manchar's algorithm

## number of island

Best solution so far;

- static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
    void fillLand(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        fillLand(grid, i + 1, j);
        fillLand(grid, i - 1, j);
        fillLand(grid, i, j + 1);
        fillLand(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans(0);
        for(auto i = 0; i < grid.size(); ++i)
            for(auto j = 0; j < grid[i].size(); ++j)
                if(grid[i][j] == '1'){
                    ans++;
                    fillLand(grid, i, j);
                }
        return ans;
    }
};

BFS solutions for NUM of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size(), y = 0, numIslands = 0;
        if(x) y = grid[0].size();
        
        // iterate through grid 
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(grid[i][j] == '1'){
                    numIslands++;
                    
                    // bfs
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    
                    while(!q.empty()){
                        pair<int,int> top = q.front();
                        q.pop();
                        int a = top.first; int b = top.second;
                        
                        // if out of bounds or not equal to 1
                        if( a < 0 or b < 0 or a >= x or b >= y or grid[a][b] != '1') continue;
                        else{
                            // set current position to '0' and add all 4 directions to queue
                            grid[a][b] = '0';
                            int changeX[4] = {0,-1,1,0}, changeY[4] = {-1,0,0,1};
                            for(int i = 0; i < 4; i++)  
                                q.push(make_pair(a + changeX[i], b + changeY[i]));
                        }
                    }
                    
                    
                }
            }
        }
        return numIslands;
    }

};