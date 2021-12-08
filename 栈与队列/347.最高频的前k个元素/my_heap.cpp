class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	class mycomparison {
	public:
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
			return lhs.second > rhs.second;
		}
	};//自己写的比较逻辑
	vector<int>result;
	unordered_map<int, int>m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison > little_q;//小顶堆
	for (auto u : nums)
	{
		
		if (m.find(u) != m.end())
		{
			m[u]++;
		}
		else {
			m[u] = 1;
		}
		
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		little_q.push(*it);
		if (little_q.size()>k)
		{
			little_q.pop();//推出的是频率最小的
		}
		
	}cout << "小顶堆的size" << little_q.size() << endl;
	while (!little_q.empty())
	{
		result.push_back(little_q.top().first);
		little_q.pop();
	}
	
	return result;

}
};
