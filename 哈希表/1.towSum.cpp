vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); i++) {
		if (hashtable.find(nums[i]) != hashtable.end())//如果找到了
		{
			return { hashtable.find(nums[i])->second,i };//哈希表需要用迭代器来访问第二个参数；
		}
		else {
			hashtable[target - nums[i]] = i;
		}
	}

	return {};//特别要注意这边要返回空；
}
