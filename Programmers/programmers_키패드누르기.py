def solution(numbers, hand):
    answer = ''
    left = [1,4,7]
    right = [3,6,9]
    pos = {1:[0,0],2:[0,1],3:[0,2],4:[1,0],5:[1,1],6:[1,2],7:[2,0],8:[2,1],9:[2,2],"*":[3,0],0:[3,1],"#":[3,2]}
    l_pos = pos["*"]
    r_pos = pos["#"]
    for num in numbers:
        if num in left:
            l_pos = pos[num]
            answer+='L'
        elif num in right:
            r_pos = pos[num]
            answer+='R'
        else:
            l_dist = abs(l_pos[0]-pos[num][0]) + abs(l_pos[1]-pos[num][1])
            r_dist = abs(r_pos[0]-pos[num][0]) + abs(r_pos[1]-pos[num][1])
            if l_dist<r_dist:
                l_pos = pos[num]
                answer+='L'
            elif l_dist>r_dist:
                r_pos = pos[num]
                answer+='R'
            else:
                if hand[0] == 'r':
                    r_pos = pos[num]
                    answer+='R'
                else:
                    l_pos = pos[num]
                    answer+='L'
        
    return answer
