#include <bits/stdc++.h>
using namespace std;

struct Mo
{
    static constexpr int MAX_VALUE = 1000001;
    vector<int> cnt;
    int current_answer;

    void process(int number, int delta)
    {
        current_answer -= (cnt[number] > 0);
        cnt[number] += delta;
        current_answer += (cnt[number] > 0);
    }
public:
    Mo()
    {
        cnt = vector<int>(MAX_VALUE, 0);
        current_answer = 0;
    }

    int get_answer() const
    {
        return current_answer;
    }

    void add(int number)
    {
        process(number, 1);
    }

    void remove(int number)
    {
        process(number, -1);
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
    cin >> Q;
    vector<int> answers(Q);
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
        while(mo_right < right) solver.add(arr[++mo_right]);
        while(mo_right > right) solver.remove(arr[mo_right--]);
        while(mo_left < left) solver.remove(arr[mo_left++]);
        while(mo_left > left) solver.add(arr[--mo_left]);
        answers[answer_idx] = solver.get_answer();
    }
    for(int i = 0; i < Q; i++)
        cout << answers[i] << "\n";
    return 0;
}
