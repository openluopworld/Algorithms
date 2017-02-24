/**
 * LeetCode: Power of Two
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * @author LuoPeng
 * @time 2015.8.3
 *
 */
public class PowerOfTwo {

    public boolean isPowerOfTwo(int n) {
        
        boolean result = false;
        if ( n == 1) {
            result = true;
        } else if ( n > 1) {
            while ( n % 2 == 0) {
                n = n/2;
            }
            result = (n==1)?true:false;
        }
        return result;
    }
    
}