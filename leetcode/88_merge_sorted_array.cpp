// merge two sorted arrays 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // иначе можно сделать idx = nums1.size()
        //если в петле не начинаем с idx-- то нужно сделать idx = nums1.size()-1;
        int idx = m+n; 
        m--;
        n--;        
        while(idx--){
            if (m < 0){
                nums1[idx] = nums2[n--];
            } 
            else if (n < 0) {
                nums1[idx] = nums1[m--];
            } 
            else {
                if(nums1[m] > nums2[n]){
                    nums1[idx] = nums1[m--];
                } 
                else {
                    nums1[idx] = nums2[n--];
                }
            }            
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;  
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums1[m]>=nums2[n]){
                nums1[idx--] = nums1[m--];
            }
            else {
                nums1[idx--] = nums2[n--];
            }
        }
        while(n>=0){
            nums1[idx--] = nums2[n--];
        }
    }
};

