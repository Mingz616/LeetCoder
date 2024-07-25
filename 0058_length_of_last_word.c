/*
* 58. 最后一个单词的长度
* 简单/相关标签/相关企业
* 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
* 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串
*/
#include <stdio.h>

int lengthOfLastWord(char* s) {
    
}

int main() {
    char string[] = "Hello World";
    char string[] = "   fly me   to   the moon  ";
    char string[] = "luffy is still joyboy";

    int ans = lengthOfLastWord(string);
    printf("%d\r\n", ans);

    return 0;
}