import sys

m, h = 0, 0
for _ in range(5):
    work_time = sys.stdin.readline().rstrip().split()
    h_in, m_in = map(int, work_time[0].split(':'))
    h_out, m_out = map(int, work_time[1].split(':'))
    
    if m_out < m_in:
        h_out -= 1
        m_out += 60
    
    m += (m_out - m_in)
    h += (h_out - h_in)

print(h * 60 + m)
