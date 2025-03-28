// https://leetcode.com/problems/minimum-index-of-a-valid-split/?envType=daily-question&envId=2025-03-27
// left right max count check krte jao jahaa mil jaye vahee return index
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int,int> mp;
    
            int largest = nums[0];
            int largestCnt = 0;
            for(auto x : nums) {
               mp[x]++;
               if(mp[x] >= largestCnt) {
                largestCnt = mp[x];
                largest = x;
               }
            }
    
            int size = nums.size();
    
            // if(largest < size / 2) return -1;
            int cnt = 0;
    
            cout<<largest<<" "<<largestCnt<<endl;
    
            for(int i = 0;i < size -1 ; i++) {
                int left = i+1;
                int right = size - i - 1;
    
                if(nums[i] == largest){
                    cnt++;
                }
    
                if(cnt > left/2 and  (largestCnt - cnt) > right / 2) {
                    return i;
                }
                
            }
            return -1;
    
        }
    };