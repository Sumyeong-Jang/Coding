import sys

m, h = 0, 0
for _ in range(5):
    work_time = sys.stdin.readline().rstrip().split()
    m_out = int(work_time[1][3]) * 10 + int(work_time[1][4])
    h_out = int(work_time[1][0]) * 10 + int(work_time[1][1])
    m_in = int(work_time[0][3]) * 10 + int(work_time[0][4])
    h_in = int(work_time[0][0]) * 10 + int(work_time[0][1])
    
    if m_out < m_in:
        h_out -= 1
        m_out += 60
    
    m += (m_out - m_in)
    h += (h_out - h_in)
    if m >= 60:
        h += 1
        m -= 60

print(h * 60 + m)
