/**
 * LeetCode: Summary Ranges
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 * 
 * If the next value is equal to the current value+1, then the next value should be merged together.
 * Input:[0, 1, 5, 7, 8]; output:["0->1", "5", "7->8"
 * Input:[3, 5, 6, 7, 9]; output:["3", "5->7", "9"] 
 * 
 * @author LuoPeng
 * @time 2015.8.4
 *
 */
public class SummaryRanges {

    /**
     * 
     * @param nums
     * @return
     */
    public List<String> summaryRanges(int[] nums) {
        
        if ( nums == null) {return null;}
        
        List<String> result = new ArrayList<String>();
        if ( nums.length != 0) {
            String temp = null;
            int length = nums.length;
            int start = 0;
            for ( int i = 1; i < length; i++) {
                if ( nums[i] - nums[i-1] != 1) {
                    if ( i == start+1) {
                        // the value should be itself
                        temp = "" + nums[start];
                    }  else {
                        temp = nums[start] + "->" + nums[i-1];
                    }
                    result.add(temp);
                    start = i;
                }
            }
            
            // the last element
            if ( length == start+1) {
                temp = "" + nums[start];
            }  else {
                temp = nums[start] + "->" + nums[length-1];
            }
            result.add(temp);
        }
        
        return result;
        
    }
    
}