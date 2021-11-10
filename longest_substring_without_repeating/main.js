/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
	repeatedChars = []
	repeatedCharsLength = []
	for(var i = 0; i < s.length; i++) {
		if(repeatedChars.includes(s.charAt(i))) {
			repeatedChars = repeatedChars.slice(repeatedChars.indexOf(s.charAt(i)) + 1, repeatedChars.length);
			repeatedChars.push(s.charAt(i));
			repeatedCharsLength.push(repeatedChars.length);
		} else {
			repeatedChars.push(s.charAt(i));
			repeatedCharsLength.push(repeatedChars.length);
		}
	}
	return repeatedCharsLength.length !== 0 ? Math.max.apply(null, repeatedCharsLength): 0;
}

console.log(lengthOfLongestSubstring("pwwkew"));

