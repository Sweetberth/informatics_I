#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> prefix(n + 1, 0);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    multiset<long long> values;

    long long max_sum = numeric_limits<long long>::min();

    for(int r = a; r <= n; r++){

        values.insert(prefix[r - a]);

        if(r - b - 1 >= 0){
            values.erase(values.find(prefix[r - b - 1]));
        }

        long long sum = prefix[r] - *values.begin();

        if(sum > max_sum){
            max_sum = sum;
        }
    }

    cout << max_sum << endl;

    return 0;
}
