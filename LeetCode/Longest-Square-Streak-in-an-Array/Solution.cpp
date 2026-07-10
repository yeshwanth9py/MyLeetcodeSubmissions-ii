class Solution {
   public int longestSquareStreak(int[] nums) {
       Set<Long> set = new HashSet<>();
       for(int num : nums) set.add(num*1l);
       int max = -1;
       for(int num : nums) {
           int len = 1;
           while(set.contains(num*1l*num*1l)) {
               len++;
               num=num*num;
               max = Math.max(max, len);
           }
       }
       return max;
   }
}