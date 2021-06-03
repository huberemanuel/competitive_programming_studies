# ref: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting

from bisect import bisect_left, insort_right

def calc_median(arr: list):
    
    if len(arr) % 2 != 0:
        return arr[int(len(arr)/2)]
    else:
        return (arr[int(len(arr)/2)-1]+arr[int(len(arr)/2)])/2

def activityNotifications(expenditure, d):
    m_l = sorted(expenditure[:d])
    alerts = 0
    
    for i in range(d, len(expenditure)):
        median = calc_median(m_l)
        
        if (2 * median) <= expenditure[i]:
            alerts += 1
            
        m_l.pop(bisect_left(m_l, expenditure[i-d]))
        insort_right(m_l, expenditure[i])
        
    return alerts

