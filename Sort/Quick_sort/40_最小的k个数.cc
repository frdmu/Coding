// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// solution: pivot
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        quickSort(arr, 0, arr.size()-1);
        res.assign(arr.begin(), arr.begin()+k);
        return res;
    }
    void quickSort(vector<int> &arr, int start, int end) {
        if (start >= end)
            return;
        
        int i = start, j = end;
        while (i < j) {
            while (i < j && arr[j] > arr[start]) j--;
            while (i < j && arr[i] <= arr[start]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[start], arr[i]);
        
        quickSort(arr, start, i-1);
        quickSort(arr, i+1, end);
    }
};
