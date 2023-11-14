#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<double,int>> buildTuples(vector<pair<double,double>> values)
{
    vector<pair<double,int>> res;
    for(size_t i = 0; i < values.size(); ++i)
    {
        if(values[i].second < values[i].first)
        {
            throw std::runtime_error("Second value should be less than the first.");
        }
        res.push_back(make_pair(values[i].first,-1));
        res.push_back(make_pair(values[i].second,1));
    }
    return res;
}

vector<pair<double,int>> sortTuples(vector<pair<double,int>> tuples)
{
    std::sort(tuples.begin(), tuples.end(), [](pair<double,int> first, pair<double,int> second)
    {
            return first.first < second.first;
    });
    return tuples;
}

void marzullo(vector<pair<double,double>> values)
{
    auto tuples = sortTuples(buildTuples(values));
    for( auto t : tuples)
    {
        cout << t.first << " " << t.second << endl;
    }
    int best = 0, cnt = 0;
    double beststart, bestend;
    for(size_t i = 0; i < tuples.size()-1; ++i)
    {
        auto offset = tuples[i].first;
        auto nextOffset = tuples[i+1].first;
        auto type = tuples[i].second;

        cnt = cnt - type;
        if(cnt > best)
        {
            best = cnt;
            beststart = offset;
            bestend = nextOffset;
        }
        cout << cnt << endl;
        cout << beststart << endl;
        cout << bestend << endl;
        cout << endl;
    }
}


int main()
{
    vector<pair<double,double>> values;
    // values.push_back(make_pair(2,3));
    // values.push_back(make_pair(4,6));
    // values.push_back(make_pair(4,6));
    // values.push_back(make_pair(2,5));
    // values.push_back(make_pair(10,16));

    values.push_back(make_pair(8,9));
    values.push_back(make_pair(11,13));
    values.push_back(make_pair(10,12));

    marzullo(values);

}