#include "head.hpp"
#include <utility>

class Solution {
public:
    void buildMaxHeap(vector<int>&nums, int heapSize){
        //对于每个非叶子节点，做堆化调整
        for (int i = heapSize/2 - 1; i >= 0; i--) {
            maxHeapify(i, nums, heapSize);
        }
    }

    void maxHeapify(int i, vector<int>&nums, int heapSize) {
        // 可以理解为，最大堆就是把小非叶子沉底
        int largest = i;
        int l = 2*i;
        int r = 2*i + 1;
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[largest], nums[i]);
            // 将非叶子继续沉底
            maxHeapify(largest, nums, heapSize);
        }
        
    }

    int findKthLargest(vector<int>& nums, int k) {
        // 首先构建最大堆
        int n = nums.size();
        buildMaxHeap(nums, n);
        // 其次移除最大堆的根，到树尾，维护最大堆
        for (int i = nums.size() - 1; i > nums.size() - k; i --) {
            swap(nums[i], nums[0]);
            n--;
            maxHeapify(0, nums, n);
        }
        return nums[0];
    }
};
