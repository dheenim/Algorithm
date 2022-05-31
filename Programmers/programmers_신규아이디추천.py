import string
def solution(new_id):
    answer = ""
    #1단계 소문자로 치환
    new_id = new_id.lower()
    #2단계 소문자, 숫자, -, _, .제외한 문자 제거
    for ch in new_id :
        if ch.isalnum() or ch in ['-','_','.']:
            answer += ch
    #3단계 마침표 2번이상 연속된 곳을 하나로 치환
    while '..' in answer:
        answer = answer.replace('..','.')
    #4단계 마침표 처음 or 끝에서 제거
    if answer[0] == '.' and len(answer)>1 :
        answer = answer[1:]
    if answer[-1] == '.':
        answer = answer[:-1]
    #5단계 빈 문자열이면 "a" 대입
    if answer == '':
        answer = 'a'
    #6단계 길이가 16자 이상이면 첫 15개 문자 제외한 나머지 모두 제거. 제거후 4단계 검사
    if len(answer) >= 16 :
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]
    #7단계 길이가 2자 이하라면 마지막 문자를 길이가 3될때까지 반복해서 끝에 붙임
    while len(answer) < 3:
        answer += answer[-1]
    return answer
