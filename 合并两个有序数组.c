class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        //声明引用的数组（nums1和nums2都是声明引用数组的别名）
        int i = m - 1;      // nums1 有效部分的最后一个元素
        int j = n - 1;      // nums2 的最后一个元素
        int k = m + n - 1;  // 合并后数组的最后一个位置

        while (j >= 0) {                        // 当 nums2 还有元素未合并时，继续循环
            if (i >= 0 && nums1[i] > nums2[j]) {// 如果 nums1 还有未合并的元素且确保nums1 的当前元素大于 nums2 的当前元素
                nums1[k--] = nums1[i--];        // 将 nums1 的当前元素放到合并后数组的最后一个位置，并将 i 和 k 向前移动
            } else {                            // 如果 nums2 的当前元素大于或等于 nums1 的当前元素
                nums1[k--] = nums2[j--];        // 将 nums2 的当前元素放到合并后数组的最后一个位置，并将 j 和 k 向前移动
            }
        }
    }
};
//这段代码的思路是“从后往前归并”：先设 i 指向 nums1 有效部分的最后一个元素，
//j 指向 nums2 的最后一个元素，k 指向合并后结果的最后一个位置；
//循环只要 nums2 还有元素没处理，就比较 nums1[i] 和 nums2[j]，
//把较大的那个放到 nums1[k] 位置上，然后对应的指针向前移动，
//这样就能在不额外开辟新数组的情况下，把 nums2 的元素安全地合并进 nums1，
//并始终保持结果有序；因为 nums1 后面有足够的空位，
//采用从后往前填充可以避免覆盖未处理的数据，最终时间复杂度是 O(m+n)。