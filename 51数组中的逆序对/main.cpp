#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // 归并排序的变形题目
    int reversePairs(vector<int>& nums) {
        count = 0;
        merge(nums, 0, nums.size() - 1);
        return count;
    }
private:
    int count;
    void merge(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        // 先拆分，后合并
        if (left < right) { // 这里不应该有等号
            merge(nums, left, mid);
            merge(nums, mid+1, right);
            merge_sort(nums, left, mid, right);
        }
    }
    void merge_sort(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int index = 0;
        // 分成两部分，左侧[l,mid]，右侧[mid+1, r]。
        int leftIndex = left, rightIndex = mid + 1;
        while (leftIndex <= mid && rightIndex <= right) {
            // 左侧元素比右侧大，说明左侧所有元素都比右侧当前元素大，则count += (左侧剩余元素的数量)
            if (nums[leftIndex] > nums[rightIndex]) {
                // 把右侧当前元素放入tmp中
                tmp[index++] = nums[rightIndex++];
                count += (mid - leftIndex + 1); // mid - leftIndex + 1
            } else {
                // 左侧当前元素小于右侧当前元素，把左侧当前元素放到tmp中
                tmp[index++] = nums[leftIndex++];
            }
        }
        // 把左侧剩余部分放到tmp中
        while (leftIndex <= mid) {
            tmp[index++] = nums[leftIndex++];
        }
        // 把右侧剩余部分放到tmp中
        while (rightIndex <= right) {
            tmp[index++] = nums[rightIndex++];
        }
        // 给nums排好顺序
        for (int i = 0; i < tmp.size(); ++i) {
            nums[left + i] = tmp[i];
        }
    }
};
int main() {
    Solution s;
    vector<int> v{7,5,6,4};
    cout << s.reversePairs(v) << endl;
    return 0;
}
