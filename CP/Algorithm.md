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
```
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
```
---
```
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
```
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return 0;
        }

        vector<int> m1(26,0), m2(26,0);
        int same = 0;
        int cnt = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (m1[i] == m2[i]) {
                same++;        
            }
        }
        
    
        for (int i = s1.size(); i < s2.size(); i++) {
            if (same == 26) {
                return true;
            }
                   //abdef fe
            char l = s2[i - s1.size()] - 'a';
            char r = s2[i] - 'a';
            
            m2[l]--;
            if (m1[l] == m2[l]) {
                same++;
            } else if (m1[l] == m2[l] + 1) {
                same--;
            }
            
            m2[r]++;
            if (m1[r] == m2[r]) {
                same++;
            } else if (m1[r] == m2[r] - 1) {
                same--;
            }
        }    
         
        return same == 26;
    }
}
```
public class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length())
            return false;
        int[] s1map = new int[26];
        int[] s2map = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1map[s1.charAt(i) - 'a']++;
            s2map[s2.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (matches(s1map, s2map))
                return true;
            s2map[s2.charAt(i + s1.length()) - 'a']++;
            s2map[s2.charAt(i) - 'a']--;
        }
        return matches(s1map, s2map);
    }
    public boolean matches(int[] s1map, int[] s2map) {
        for (int i = 0; i < 26; i++) {
            if (s1map[i] != s2map[i])
                return false;
        }
        return true;
    }
}
```

 - [ ] ybn nahmir (bail out my nigga free out mf fuckers  u sad bitch)
 - [x] bad bitch
 - [ ] small pretty face .

 