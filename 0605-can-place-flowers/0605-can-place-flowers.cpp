class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        int count = 0;
        int continuous = 0;
        for(int i=0;i<flowerbed.size();i++) {
            if(flowerbed[i] == 0) continuous ++;
            else {
                count += (continuous - 1) / 2;
                continuous = 0;
            }
        }
        count += (continuous - 1) / 2;
        if(n <= count) return true;
        else return false;
        
    }
};