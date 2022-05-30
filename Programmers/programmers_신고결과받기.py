from collections import defaultdict
def solution(id_list, report, k):
    answer = [0] * len(id_list) 
    report = set(report) #신고내용 중복 제거
    
    #A가 신고한 목록 : reports
    #A를 신고한 목록 : reporteds
    reports = defaultdict(list)
    reporteds = defaultdict(list)
    for str in report :
        reporter, reported = str.split()
        if reported not in reports[reporter]:
            reports[reporter].append(reported)
            if reporter not in reporteds[reported]:
                reporteds[reported].append(reporter)
    for idx in range(0,len(id_list)) :
        if len(reporteds[id_list[idx]])>=k:
            for str in reporteds[id_list[idx]]:
                answer[id_list.index(str)]+=1;
     return answer
