def solution(lottos, win_nums):
    #1:6개 일치, 2:5개 일치, ,,, 5:2개 일치, 6:1개혹은 0개일치
    rank = [6, 6, 5, 4, 3, 2, 1] #rank[0]는 0개 일치 했을때 6등이라는 의미.
    same = 0
    zeros = lottos.count(0)
    for num in win_nums:
        if num in lottos :
            same += 1
    answer = []
    answer.append(rank[zeros+same])
    answer.append(rank[same])
    
    return answer
