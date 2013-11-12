#!/usr/bin/python3

def minhops_dfs(lst):
    sz = len(lst)
    min_hop = [0] * sz
    def dfs(index,s,hops,min_hop):
        if index >= sz:
            if len(min_hop) > s:
                min_hop[:] = hops
                #min_hop.extend(hops)
        elif s > len(min_hop):
            pass
        else:
            hops.append(index)
            for i in range(1,lst[index] + 1):
                dfs(index + i, s + 1,hops,min_hop)
            hops.pop()
    dfs(0,0,[],min_hop)
    return min_hop

print(minhops_dfs([5, 6, 0, 4, 2, 4, 1, 0, 0, 4]))

def min_hops_dp(lst):
    sz = len(lst)
    min_hops = [0] * sz
    for l in range(sz - 1,-1,-1):
        if lst[l] + l >= sz:
            min_hops[l] = 1
        else:
            end = min(lst[l] + l,sz)
            min_hops[l] = 1 + min(min_hops[l+1:end+1])
    return min_hops

print(min_hops_dp([5, 6, 0, 4, 2, 4, 1, 0, 0, 4]))
