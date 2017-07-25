from collections import defaultdict
from config import get_feat_prefix
f = open('dataset/pt_sub/' + 'DivAll-Problems-tags.txt', 'r')

tag_set = set()
contest_set = set()
tag_count = defaultdict(int)
problem_counts = defaultdict(int)
num_problems = 0

while True:
    contest_line = f.readline()
    if not contest_line:
        break
    contest_num = contest_line.split(":")[1].strip()
    # print(contest_line)
    # break
    contest_set.add(contest_num)
    index = f.readline().split(':')[1]
    # print(index)
    problem_counts[index]+=1
    name = f.readline()
    tags = f.readline()
    for tag in tags.split(':')[-1].strip().split(','):
        tag_set.add(tag.strip())
        tag_count[tag.strip()]+=1
    f.readline()
    f.readline()
    num_problems += 1

print('Number of tags', len(tag_set), sorted(list(tag_set)))
print('Contests', len(contest_set))
print('Problems', problem_counts)
print(num_problems)
for tag, val in sorted(tag_count.items(), key = (lambda x : x[1]), reverse=True):
    if tag == '':
        continue
    print('\\task', tag)