def solution(record):
    mac = {"Enter":"님이 들어왔습니다.", "Leave":"님이 나갔습니다."}
    answer = []
    nickname = {}
    for rc in record:
        w = ""
        uid = ""
        n = ""
        if rc[0] == 'L' :
            w, uid = rc.split()
        else :
            w, uid, n = rc.split()
        if uid not in nickname and w[0] != 'L':
            nickname[uid] = n
        if uid in nickname and w[0] != 'L' :
            nickname[uid] = n
    for rc in record :
        w =""
        uid=""
        n=""
        if rc[0] == 'L' :
            w, uid = rc.split()
        else :
            w, uid, n = rc.split()
        if w[0] == 'C' : 
            continue
        answer.append(nickname[uid]+mac[w])
    return answer
