used = set()
n = int(input())

p_names = {}

for i in range(n):
    cur_name, new_name = input().split()
    if new_name not in used:
        used.add(new_name)
        if cur_name in used:
            used.remove(cur_name)

        if cur_name in p_names:
            p_names[new_name] = p_names[cur_name]
        else:
            p_names[new_name] = cur_name

print(len(used))
for name in used:
    print(p_names[name], name)