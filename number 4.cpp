 
#4. Median of Two Sorted Arrays
#考虑先实现求第k大的值的函数
#主要是边界情况比较恶心
class Solution {
public:
    int findTopK(vector<int> nums1,vector<int> nums2,int k)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        #加入头和尾
        nums1.insert(nums1.begin(),INT_MIN);
        nums2.insert(nums2.begin(),INT_MIN);
        nums1.insert(nums1.end(),INT_MAX);
        nums2.insert(nums2.end(),INT_MAX);
        
        int low = 1,high = k > size1?size1:k;
        int i = (low + high) / 2;
        int j = k - i;
        #防止越界
        if(j > size2)
        {
            j = size2;
            i = k - j;
            low = i;
        }
        if(j < 0)
        {
            j = 0;
            i = k - j;
            high = i;
        }
        while(nums1[i] > nums2[j + 1] || nums2[j] > nums1[i + 1])
        {
            if(nums1[i] > nums2[j + 1])//i 向后移动
            {
                high = i- 1;
            }
            
            if(nums2[j] > nums1[i + 1])
            {
                low = i + 1;
            }
            
            i = (low + high) / 2;
            j = k - i;
            if(j > size2)
            {
                j = size2;
                i = k - j;
                low = i;
            }
            if(j < 0)
            {
                j = 0;
                i = k - j;
                high = i;
            }
        }
        return nums1[i] > nums2[j]? nums1[i] : nums2[j];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int k = (size1 + size2 + 1)/2;
        if((size1 + size2) % 2 == 0)
            return double(findTopK(nums1,nums2,k) + findTopK(nums1,nums2,k+1)) / 2; 
        else
            return findTopK(nums1,nums2,k);
        }
};
