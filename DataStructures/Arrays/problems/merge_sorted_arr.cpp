#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    vector<int>ans(nums1.size(), 0);

        int i =0, j=0, k=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
            ans[k] = nums1[i];
            i++;
            k++;
        }else{
            ans[k] = nums2[j];
            j++;
            k++;
            }
        }

        while(i < m){
            ans[k++] = nums1[i];
            i++;
        }

        while(j< n){
            ans[k++] = nums2[j++];
        }

        for(int i=0; i< nums1.size(); i++){
            nums1[i] = ans[i];
        }

    }

    void merge_optimized(vector<int>& nums1, int m, vector<int>& nums2, int n){





    }