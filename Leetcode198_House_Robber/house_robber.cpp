class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();   
        if(n == 1)
            return nums[0];
        int p2=0;    //highest money till house(i-2) 
        int p1=0;    //highest money till house(i-1)
        for(int i=0;i<n;i++){
            int rob = p2 + nums[i];//rob current house
            int skip = p1;          //skip current house
            int curr = max(rob,skip);//best till current house
            p2 = p1;    
            p1 = curr; //current best
        }

        return p1;//maximum money that can rob 
    }
};