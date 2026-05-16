#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int left,right,mid,a=-1,b=-1;
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        left=0;
        right=len-1;
        if(nums.empty())return {-1,-1};
        while(left<right){
            mid=(left+right)/2;
            if(nums[mid]>=target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        if(nums[right]==target)a=right;
        else{
            a=-1;
        }
        left=0;
        right=len-1;
        while(left<right){
            mid=(left+right+1)/2;
            if(nums[mid]<=target){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        if(nums[right]==target)b=left;
        else{
            b=-1;
        }
        return {a,b};
    }
};





// int main(){
//     int n,nums[1000],target;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>temp;
//     }
//     cin>>target;
//     Solution a;
//     a.searchRange(nums,target);
// }