#include <bits/stdc++.h>
#include <map>

using namespace std;

vector<string> split_string(string);

/* First brute force solution.
void whatFlavors(vector<int> cost, int money) {
    for (int iter = 0; iter < cost.size(); ++iter) {
        int target = money - cost[iter];
        for (int contrary = iter + 1; contrary < cost.size(); ++contrary) {
            if (cost[contrary] == target) {
                cout << iter + 1 << ' ' << contrary + 1 << '\n';
                return;
            }
        }
    }
}
*/

typedef struct element element;
struct element
{
    vector<int> indexs = {};
};

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    map<int, element> cost_map;

    for (int iterMap = 0; iterMap < cost.size(); ++iterMap) {
        cost_map[cost[iterMap]].indexs.push_back(iterMap + 1);
        
        int divider = cost[iterMap];
        int target = money - divider;
        
        if (divider == target) {
            if (cost_map[divider].indexs.size() == 2) {
                cout << cost_map[target].indexs[0] << ' ' << cost_map[divider].indexs[1] << '\n';
                return;
            }
        } else if (cost_map.count(divider) > 0 && cost_map.count(target) > 0) {
            cout << cost_map[target].indexs[0] << ' ' << cost_map[divider].indexs[0] << '\n';
            return;
        }
    }
}


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
