class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int days = 1, load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] + load > cap){
                days++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& wts, int days) {
        int maxi=*max_element(wts.begin(),wts.end());
        int sum = accumulate(wts.begin(),wts.end(),0);
        while(maxi<=sum){
            int mid = maxi+(sum-maxi)/2;
            int dds = findDays(wts,mid);
            if(dds<=days){
                sum=mid-1;
            }else{
                maxi=mid+1;
            }
        }
        return maxi;
        
    }
};