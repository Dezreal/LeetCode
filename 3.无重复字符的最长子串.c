/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */
bool isRepeated(char * s, int len, char target);
int cont_str(char *s);

int lengthOfLongestSubstring(char * s){
    if(s[0] == '\0') {
        return 0;
    }
    int len = cont_str(s);
    int i, j, result = 1;
    for(i = 0; i < len - 1; i++) {
        for(j = 1; j < len - i; j++) {
            if(! isRepeated(s + i, j, s[i + j])) {
                if(j + 1 > result) {
                    result = j + 1;
                }
            } else {
                break;
            }
        }
    }
    return result;
}

bool isRepeated(char *s, int len, char target) {
    int i;
    for(i = 0; i < len; i++) {
        if(s[i] == target) {
            return true;
        }
    }
    return false;
}
int cont_str(char *s)
{
    int i = 0;
    while ( s[i++] != '\0')
        ;
    return i - 1;
}


