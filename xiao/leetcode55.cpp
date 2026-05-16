#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 0) {
                bool canPass = false;

                int left = i - 1;
                int cnt = 1;   

                while (left >= 0) {
                    if (nums[left] > cnt) {
                        canPass = true;
                        break;
                    }

                    left--;
                    cnt++;
                }

                if (!canPass) {
                    return false;
                }
            }
        }

        return true;
    }
};

/*
    学习学长思路的复现
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dis=0;
        int len=nums.size();
        int i=0;
        while(i<len){
            if(i<=dis){
                dis=max(dis,i+nums[i]);
            }//记录最远可以跳到哪里
            if(dis>=len-1){return true;}
            i++;//更新i去遍历
        }
        return false;
    }
};
