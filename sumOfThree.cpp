#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> array;

    for(int i = 0; i < n; i++){
        int y;
        cin >> y;
        array.push_back({y, i + 1});
    }

    sort(array.begin(), array.end());

    for(int i = 0; i < n-2; i++){
        int left = i + 1;
        int right = n - 1;

        while(left < right){
            int sum = array[i].first + array[left].first + array[right].first;

            if(sum == x){
                cout << array[i].second << " "
                     << array[left].second << " "
                     << array[right].second << endl;
                return 0;
            }
            else if(sum < x){
                left++;
            }
            else{
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
