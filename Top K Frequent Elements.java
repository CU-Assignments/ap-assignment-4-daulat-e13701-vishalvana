class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int maxValue = 0;
        for (int num : nums) {
            maxValue = Math.max(maxValue, num);
        }
        int[] freq = new int[maxValue + 1];
        for (int num : nums) {
            freq[num]++;
        }
        List<List<Integer>> buckets = new ArrayList<>(nums.length + 1);
        for (int i = 0; i <= nums.length; i++) {
            buckets.add(new ArrayList<>());
        }
        for (int num = 0; num <= maxValue; num++) {
            if (freq[num] > 0) {
                buckets.get(freq[num]).add(num);
            }
        }
        int[] result = new int[k];
        int index = 0;
        for (int i = buckets.size() - 1; i >= 0 && index < k; i--) {
            for (int num : buckets.get(i)) {
                result[index++] = num;
                if (index == k) break;
            }
        }
        
        return result;
    }
}
