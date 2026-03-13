#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for(int num : nums){
        if(count == 0){
            candidate = num;
        }
        if(num == candidate){
            count++;
        }else{
            count--;
        }
    }
    return candidate;
}


int main() {
    vector<int> testCase1 = {3, 2, 3};
    vector<int> testCase2 = {2, 2, 1, 1, 1, 2, 2};
    vector<int> testCase3 = {1000000000, 1000000000, -1000000000, 1000000000};

    cout << "Test Case 1 Result: " << majorityElement(testCase1) << " (Expected: 3)" << endl;
    cout << "Test Case 2 Result: " << majorityElement(testCase2) << " (Expected: 2)" << endl;
    cout << "Test Case 3 Result: " << majorityElement(testCase3) << " (Expected: 1000000000)" << endl;

    return 0;
}