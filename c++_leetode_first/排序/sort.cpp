//
// Created by 11818 on 2024/10/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//冒泡排序算法
void BubbleSort(vector<int>& arr, int n){
    for(int i=0; i< n; i++){
        for(int j=0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}//这个是每一轮中选择出来一个最大的数，然后把它放到最后面，这样下一轮就只需要比较到倒数第二个数，直到最后一个数。

//2.选择排序算法
void SelectionSort(vector<int>& arr, int n) {//这个算法相当于提取出来最小值放在前面就可以了。
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);        //把最小值放到前面
    }
}
//  3.插入排序算法
void InsertionSort(vector<int>& arr, int n) {//这个算法是从第二个数开始，和前面的数比较，如果比前面的数小，就把前面的数往后移一位，然后把当前数插入到前面的空位。
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
//  4.希尔排序算法
void ShellSort(vector<int>& arr, int n) {//这个算法是先把数组分成若干个子序列，然后对子序列进行插入排序，这样可以使得子序列基本有序，然后再对全体数组进行插入排序。
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > temp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
}

//快排
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= pivot) {//这个是为了保证右边界的位置是大于pivot的
            --right;
        }
        //从右边开始，right 指针向左移动，直到找到一个小于基准值的元素。
        //这个元素不在正确的位置，因此需要放到基准值的左边
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) {//这个是为了保证左边界的位置是小于等于pivot的
            ++left;
        }
        arr[right] = arr[left];
    }//在while循环结束shift之后，left和right指向的位置是分割点，把pivot放到分割点的位置
    arr[left] = pivot;
    return left;
}//这个相对于获得了一个中间位置，然后把左边的数都放到左边，右边的数都放到右边，中间的数放到中间。
//然后把pivot放到分割点的位置。
//然后递归的对左右两个子序列进行排序。
void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);    //注意这里的+1和-1，因为pivotIndex是左边界，所以要减1，右边界要加1。
    }
}
//  7.堆排序算法

int main(){
    vector<int> arr = {5, 3, 8, 6, 2, 7, 1, 4};
    int n = arr.size();
//    BubbleSort(arr, n);
    SelectionSort(arr, n);
    for(int i=0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
