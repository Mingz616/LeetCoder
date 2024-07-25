/*
| 3. 无重复字符的最长子串
| 中等/相关标签/相关企业
| 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    bool has[128] = {}; // ASCII TABLE 0~127: A to Z = 41 to 90; a to z = 97 to 122; 
    int n = strlen(s);  // string length
    int win = 0;        // windows index
    int ans = 0;        // result

    for(int i = 0; i < n; i ++) {
        char c = s[i];
        // determine whether char (ASCII) is true in the boolean array
        while(has[c]) {
            has[s[win++]] = false;    // false the existed char (ASCII) in the array
        }
        // if not, make the char value (ASCII) as true in the boolean array
        has[c] = true;
        // calculate the repetitive length
        int len = i - win + 1;
        ans = len > ans ? len : ans;
    }
    return ans;
}

int main() {
    // char string[24] = "abcabcbb";
    // char string[24] = "bbbbb";
    char string[24] = "pwwkew";
    int rep = lengthOfLongestSubstring(string);

    printf("%d\n", rep);

    return 0;
}