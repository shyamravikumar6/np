### Kodak BLack
![](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcS4oco66xya8abfiIZ3KnU7AOQ00hDXz9y5HW9F9O0siQtgIuFC&usqp=CAU)

---
  ```
  static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = A[0];
        int mx = A[0];
        int acc = A[0];
        for (int i = 1; i < A.size(); ++i) {
            sum += A[i];
            acc = max(0, acc)+A[i];
            mx = max(mx, acc);
        }
        int mn = A[0];
        acc = A[0];
        for (int i = 1; i < A.size(); ++i) {
            acc = min(0, acc)+A[i];
            mn = min(mn, acc);
        }
        if (sum == mn) {
            return mx;    
        }
        return max(sum-mn, mx);
    }
};
 ```
 
