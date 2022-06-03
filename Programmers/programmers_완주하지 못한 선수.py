def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    for idx in range(0,len(completion)):
        if participant[idx] != completion[idx]:
            answer = participant[idx]
            break
    if not answer :
        answer = participant[-1]
    return answer
