int find_center(vector<pair<int, int>>&nums, int low, int high)
{
	auto temp = nums[low];
	auto center= nums[low].second;
	while (low < high)
	{
		while (low<high&&nums[high].second<=center)
		{
			high--;
		}
		nums[low] = nums[high];
		while (low<high&&nums[low].second>=center)
		{
			low++;
		}
		nums[high] = nums[low];
	}
	nums[low] = temp;
	return low;
}
void my_qsort(vector<pair<int,int>>&nums,int low,int high)
{
	if (low < high)
	{
		int center = find_center(nums, low, high);//每次循环都找
		my_qsort(nums, low, center - 1);
		my_qsort(nums, center + 1, high);
	}
}
vector<int> topKFrequent(vector<int>& nums, int k) {
	if (nums.size() == 1) return nums;
	unordered_map<int, int>hashmap;
	for (auto u : nums)
	{
		hashmap[u]++;
	}
	vector<pair<int, int>>temp;//数组里面装的都是哈希表
	for (auto x : hashmap)
	{
		temp.push_back(x);
	}
	//下面堆hash表的第二个元素快排
	my_qsort(temp, 0, temp.size()-1);
	
	vector<int>ans;
	for (int i = 0; i < k; i++)
	{
		ans.push_back(temp[i].first);
	}
	return ans;
}
