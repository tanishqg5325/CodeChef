#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, int> coor;
int MAX_VALUE;
int tree[100001];

int find_cf(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val)
{
    while(idx <= MAX_VALUE)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

struct Mo
{
    ll current_answer;

public:
    Mo()
    {
        current_answer = 0;
    }

    ll get_answer() const
    {
        return current_answer;
    }

    void add1(int num)
    {
        num = coor[num];
        update(num, 1);
        current_answer += (find_cf(MAX_VALUE) - find_cf(num));
    }

    void add2(int num)
    {
        num = coor[num];
        update(num, 1);
        current_answer += find_cf(num-1);
    }

    void remove1(int num)
    {
        num = coor[num];
        update(num, -1);
        current_answer -= (find_cf(MAX_VALUE) - find_cf(num));
    }

    void remove2(int num)
    {
        num = coor[num];
        update(num, -1);
        current_answer -= find_cf(num-1);;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, Q, BLOCK_SIZE;
    cin >> N;
    BLOCK_SIZE = static_cast<int>(sqrt(N));
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];
    set<int> dict(arr.begin(), arr.end()); int k = 1;
    for(int a : dict) coor[a] = k++;
    MAX_VALUE = k;
    cin >> Q;
    vector<ll> answers(Q);
    vector< tuple<int, int, int> > queries;
    queries.reserve(Q);
    for(int i = 0; i < Q; i++)
    {
        int le, rg;
        cin >> le >> rg;
        queries.emplace_back(le - 1, rg - 1, i);
    }
    auto mo_cmp = [BLOCK_SIZE](const tuple<int, int, int> &x,
            const tuple<int, int, int> &y) -> bool
    {
        int block_x = get<0>(x) / BLOCK_SIZE;
        int block_y = get<0>(y) / BLOCK_SIZE;
        if(block_x != block_y)
            return block_x < block_y;
        return get<1>(x) < get<1>(y);
    };

    sort(queries.begin(), queries.end(), mo_cmp);

    Mo solver;
    int mo_left = 0, mo_right = -1;
    int left, right, answer_idx;
    for(const auto &q: queries)
    {
        tie(left, right, answer_idx) = q;
        while(mo_right < right) solver.add1(arr[++mo_right]);
        while(mo_right > right) solver.remove1(arr[mo_right--]);
        while(mo_left < left) solver.remove2(arr[mo_left++]);
        while(mo_left > left) solver.add2(arr[--mo_left]);
        answers[answer_idx] = solver.get_answer();
    }
    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}
