def chkLen(length, s):
    res = 0
    substr = s[0:length]
    same = 1
    for sidx in range(length, len(s), length):
        if substr == s[sidx:sidx+length] :
            same += 1
            continue
        if same == 1:
            res += length
        else :
            res += length + len(str(same))
        substr = s[sidx:sidx+length]
        same = 1
    if same > 1:
        res += len(substr) + len(str(same))
    else :
        res += len(substr)
    return res
    
def solution(s):
    if len(s) == 1 : return 1
    answer = 1001
    #1개단위~문자열 길이/2 만큼 자르는 단위를 각각 검사
    tmpAns = 0
    for length in range(1,int(len(s)/2)+1):
        tmpAns = chkLen(length, s)
        if tmpAns < answer :
            answer = tmpAns
    return answer
