#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long long k;
    vector<long long> array = {};

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        long long b;
        cin >> b;
        array.push_back(b);
    }

    sort(array.begin(), array.end());

    int mid = n / 2;

    long long left = array[mid];
    long long right = array[mid] + k;
    long long answer = array[mid];

    while(left <= right){
        long long target = (left + right) / 2;
        long long count = 0;

        for(int i = mid; i < n; i++){
            if(array[i] < target){
                count += target - array[i];
            }
        }

        if(count <= k){
            answer = target;
            left = target + 1;
        }
        else{
            right = target - 1;
        }
    }

    cout << answer;

    return 0;
}
