#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int count_swaps(vector<int> sorted,vector<int> arr){  //create a function to count swaps needs to be done compared to a sorted array.
    int swap_count = 0;
    map<int, int> arrMap; //create map to easily access the index of elements
    for(int j=0;j<arr.size(); j++){ //copy all the elements to the map
        arrMap[arr[j]] = j; 
    }
    for (int i=0; i<arr.size(); i++){
        if (arr[i] != sorted[i]){  //check whether the the element needs to be swaped or not
            int a = arr[i];
            int s = sorted[i];
            int index = arrMap[sorted[i]];  //get the position of the ith element in the sorted array in the array.
            swap(arr[i],arr[index]); //swap two elements in the array using inbuilt swap method.
            arrMap[a] = index; //update the new positions in the map
            arrMap[s] = i;
            swap_count += 1;    //increase the swap count
        }
        
    }
    return swap_count;
}

int lilysHomework(vector<int> arr) {
    
    vector<int> sorted = arr; // create a copy of the original vector
    sort(sorted.begin(), sorted.end()); // sort the copy
    int swap_count_1 = count_swaps(sorted, arr);
    
    vector<int> reverse_sorted = arr; // create a copy of the original vector
    sort(reverse_sorted.begin(), reverse_sorted.end(), greater<int>());// sort the copy in reverse order
    //reverse(reverse_sorted.begin(), reverse_sorted.end());
    int swap_count_2 = count_swaps(reverse_sorted, arr);
    return min(swap_count_1,swap_count_2); //get the minimum count of swaps
}

int main() {
    // Write C++ code here
    vector<int> vec = {3,4,2,5,1};
    cout << lilysHomework(vec);
    return 0;
}