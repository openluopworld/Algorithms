
/*
 * Problem 242 : Valid Anagram
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * 
 * Time: O(n) + O(m), suppose n is the length of s, m is the length of t
 * Space: O(1), needs 26 int number
 */
bool isAnagram(char* s, char* t) {
	int a[26] = {0};
	char* tempS = s;
	char* tempT = t;
	while ( *s != '\0') {
		a[(*s-'A')%32]++;
		s++;
	}
	while ( *t != '\0') {
		a[(*t-'A')%32]--;
		t++;
	}
	
	int i;
	for (i = 0; i < 26; i++) {
		if ( a[i] != 0) {
			break;
		}
	}
	return i==26;
}