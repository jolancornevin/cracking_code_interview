
// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    // Min has the higest possible value.
    int min = (int) ((~((unsigned int) 0)) >> 1);
    // Max has the lowest possible value.
    int max = ~min;
    int swap = 0;

    for (int i = 0; i < a.size(); i++) {
        // We are sorting by increasing order. Thus minimum element is the first one.
        if (a[i] < min)
            min = a[i];
        // And max element is the last one.
        if (a[i] > max)
            max = a[i];

        for (int j = 0; j < a.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                // And increment the swap counter.
                swap++;
            }
        }
    }
    
    cout << "Array is sorted in " << swap << " swaps.\n";
    cout << "First Element: " << min << "\n";
    cout << "Last Element: " << max << "\n";

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
