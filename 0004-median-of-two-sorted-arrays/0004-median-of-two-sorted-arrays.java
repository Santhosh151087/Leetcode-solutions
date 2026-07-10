class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1=nums1.length;
        int len2=nums2.length;
        int[] arr = new int [len1+len2];
        int index=0;
        int i1=0;
        int i2=0;
        while(index<len1+len2 && i1<len1 && i2<len2){
            if(nums1[i1]==nums2[i2]){
                arr[index++]=nums1[i1++];
                arr[index++]=nums2[i2++];
            }
            else if(nums1[i1]<nums2[i2]){
                arr[index++]=nums1[i1++];
            }
            else{
                arr[index++]=nums2[i2++];
            }
        }
        while(i1<len1){
            arr[index++]=nums1[i1++];
        }
        while(i2<len2){
            arr[index++]=nums2[i2++];
        }

    
        if(arr.length%2==1){
            return arr[arr.length/2]*1.0;
        }

        return ((arr[arr.length/2]+arr[arr.length/2-1])/(2.0));
    }
}