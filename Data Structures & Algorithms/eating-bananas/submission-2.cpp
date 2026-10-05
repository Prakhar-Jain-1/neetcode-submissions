class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r =*max_element(piles.begin(), piles.end());
        int ans = 1000000001;
        while(l<=r){
            int mid = (l+r)/2;
            int hr = 0;
            for(int i:piles){
                // hr+=ceil((float)i/(float)mid);
                if(i%mid){
                    hr++;
                }
                hr+=(i/mid);
                // if(i%mid == )
            }
            cout<<hr<<" "<<mid<<endl;
            if(hr<=h){
                r = mid-1;
                ans = min(mid,ans);
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
