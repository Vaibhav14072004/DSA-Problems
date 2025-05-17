class Solution {
public:

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left= low;
    int right= mid+1;

    vector<int> temp;

    while(left<= mid && right<= high)
    {
        if(arr[left] > arr[right])
        {
            temp.push_back(arr[right]);
            right++;
        }

        else{
            temp.push_back(arr[left]);
           left++;
        }
    }

        // if left subarray is greater than right subarray...
        while(left<= mid){
            temp.push_back(arr[left]);
           left++;
        }

        // if right subarray is greater than left subarray...
        while(right<= high){
            temp.push_back(arr[right]);
            right++;
        }

// copy elements from temp array to original array
for(int i= low; i<= high; i++){
    arr[i]= temp[i-low];
}
}
 
  void mergeSort(vector<int> &arr, int low, int high)
  {
      // base case
      if(low>= high){
          return;
      }
      int mid= low+ (high-low)/2;
      mergeSort(arr,low, mid);
      mergeSort(arr,mid+1, high);
      merge(arr,low,mid,high);
  }

    void sortColors(vector<int>& arr) {
    int n= arr.size();
     mergeSort(arr, 0, n-1);
    }
    };







/*

class Solution {
public:

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left= low;
    int right= mid+1;
    int index= 0;

    vector<int> temp(high-low+1);

    while(left<= mid && right<= high)
    {
        if(arr[left] > arr[right])
        {
            temp[index++]= arr[right++];
           // right++;
        }

        else{
            temp[index++]= arr[left++];
           // left++;
        }
    }

        // if left subarray is greater than right subarray...
        while(left<= mid){
            temp[index++]= arr[left++];
           // left++;
        }

        // if right subarray is greater than left subarray...
        while(right<= high){
            temp[index++]= arr[right++];
           //  right++;
        }

// copy elements from temp array to original array
for(int i= low; i<= high; i++){
    arr[i]= temp[i-low];
}
}
 
  void mergeSort(vector<int> &arr, int low, int high)
  {
      // base case
      if(low>= high){
          return;
      }
      int mid= low+ (high-low)/2;
      mergeSort(arr,low, mid);
      mergeSort(arr,mid+1, high);
      merge(arr,low,mid,high);
  }

    void sortColors(vector<int>& arr) {
    int n= arr.size();
     mergeSort(arr, 0, n-1);
    }
    };

*/













// // Ques =>> Sort array of 0 1 2 (Dutch National Flag Problem)

// //  Approach 3 (Dutch National Flag Algorithm) ... Three Pointers Approach
// //  TC= O(N) =>> Beats 100 % users in C++

// /*  low= 0 , mid= 0  , high= n-1 , while(mid<= high)

// From ( 0 to low-1 ) =>> All zeroes (0)
// From ( low to mid-1 ) => All ones (1)

// From ( mid to high ) => 0,1,2 (Unsorted) --- this space is to be sorted...

// From (high +1 to n-1) => All two (2)

// */


// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         int n= arr.size();

//     int low= 0;
//     int mid= 0;
//     int high= n-1;

//         while(mid<= high)
//         {
//           if(arr[mid]== 0)
//           {
//               swap(arr[low], arr[mid]);
//               low++;
//               mid++;
//           }

//           else if(arr[mid]== 1)
//           {
//               mid++;
//           }

//           else   // arr[mid]== 2
//           {
//             swap(arr[mid], arr[high]);
//             high--;
//           }
//         }
//     }
// };




// // Approach 2 =>> storing cnt of 0,1,2 and then acc to cnt make elements 0,1,2
// // Tc= O(N) => Beats 100 % users in C++

// /*

// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         int n= arr.size();
    
//     int count0= 0;
//     int count1= 0;
//     int count2= 0;

//     for(int i=0; i<n; i++)
//     {
//         if(arr[i]== 0){
//             count0++;
//         }
//         else if(arr[i]== 1){
//             count1++;
//         }
//         else{
//             count2++;
//         }
//     }

//     for(int i=0; i<count0; i++)
//     {
//         arr[i]= 0;
//     }

//     for(int i= count0; i< count0+ count1; i++)
//     {
//         arr[i]= 1;
//     }

//     for(int i= count0+ count1; i<n; i++)
//     {
//         arr[i]= 2;
//     }
//     }
// };

// */





// // ------ Approach 1 ( Using Sorting ) ------

// // Insertion Sort (0 ms) => Beats 100 % users in C++

// /*
// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
     
//      int n= arr.size();
     
//      for(int i=1; i<n; i++){
//          int temp= arr[i];
//          int j= i-1;

//          while(j>=0 && arr[j] > temp){
//              arr[j+1]= arr[j];
//              j--;
//          }
//          arr[j+1]= temp;
//      }
//     }
// };

// */


// // Selection Sort (5 ms) => Beats 9.84 % users in C++

// /*

// class Solution{
// public:
// void sortColors(vector<int> &arr){
//     int n= arr.size();

//     for(int i=0; i<n; i++){
//         int mini= i;

//         for(int j=i+1; j<n; j++){
             
//              if(arr[j] < arr[mini]){
//                  mini= j;
//              }
//         }

//         if(mini != i){
//            // swap(arr[i], arr[mini]);

//            int temp= arr[i];
//            arr[i]= arr[mini];
//            arr[mini]= temp;
//         }
//     }
// }
// };

// */



