#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode
{
	int unmatchedOpenParans, unmatchedClosedParans;

	void assignLeaf(char value)
	{
		if (value == '(') unmatchedOpenParans = 1, unmatchedClosedParans = 0;
        else unmatchedOpenParans = 0, unmatchedClosedParans = 1;
	}

	void merge(SegmentTreeNode& left, SegmentTreeNode& right)
	{
        int newMatches = min(left.unmatchedOpenParans, right.unmatchedClosedParans);
        unmatchedOpenParans = right.unmatchedOpenParans + left.unmatchedOpenParans - newMatches;
        unmatchedClosedParans = left.unmatchedClosedParans + right.unmatchedClosedParans - newMatches;
	}

	bool getValue()
	{
		return ((unmatchedOpenParans == 0) && (unmatchedClosedParans == 0));
	}
};

// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree
{
	SegmentTreeNode* nodes;
	int N;

public:
	SegmentTree(T arr[], int N)
	{
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}

	~SegmentTree() { delete[] nodes; }

	V getValue(int lo, int hi)
	{
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}

	void update(int index, T value)
	{
		update(1, 0, N-1, index, value);
	}

private:
    int getSegmentTreeSize(int N)
	{
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}

	void buildTree(T arr[], int stIndex, int lo, int hi)
	{
		if (lo == hi)
        {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}

	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
	{
		if (left == lo && right == hi) return nodes[stIndex];
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);

		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}

	void update(int stIndex, int lo, int hi, int index, T value)
	{
		if (lo == hi)
        {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid) update(left, lo, mid, index, value);
		else update(right, mid+1, hi, index, value);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N, M, k, t=10; char A[30005];
	for(int i=1;i<=t;i++)
    {
        cout<<"Test "<<i<<":\n";
        cin>>N;
        for (int j = 0; j < N; ++j) cin>>A[j];
        SegmentTree<char,bool> st(A, N);
        cin>>M;
        while(M--)
        {
            cin>>k;
            if(k == 0)
            {
                if(st.getValue(0,N-1)) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else
            {
                if(A[k-1] == '(') A[k-1] = ')', st.update(k-1,')');
                else A[k-1] = '(', st.update(k-1,'(');
            }
        }
    }
	return 0;
}
