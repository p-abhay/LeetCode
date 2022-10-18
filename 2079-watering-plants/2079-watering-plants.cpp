class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0,steps1=0;
        int org = capacity;
        for(int i = 0; i < plants.size(); i++) {
            
            if(plants[i] <= capacity) {
                capacity -= plants[i];
                steps += 1;
            }
            else {
                steps1 += steps + steps;
                capacity = org;
                i -= 1;
            }
        }
        return steps + steps1;
    }
};