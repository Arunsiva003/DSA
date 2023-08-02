//linear search?
#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& array, int value) {
  int index = 0;

  for(int index=0;index<array.size();index++) {
    if (array[index] == value) {
      return index;
    }
    
  }
  return -1;

}

int binarySearch(vector<int>& arr, int value) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int middle = (left + right) / 2;

    if (arr[middle] == value) {
      return middle;
    } else if (arr[middle] < value) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return -1;
}

int main(){
    vector<int> arr={2,5,7,9,10};
    int bans = binarySearch(arr,9);
    if(bans==-1){
        cout<<"element not found\n";
    }
    else{
        cout<<"element found at index "<<bans<<endl;
    }
    int lans = linearSearch(arr,10);
    if(lans==-1){
        cout<<"element not found\n";
    }
    else{
        cout<<"element found at index "<<lans<<endl;
    }
}