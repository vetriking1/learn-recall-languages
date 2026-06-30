# ============================================================
# Topic:  Arrays / Lists  (FOCUS: methods & operations)
# Summary: create, access, add, remove, slice, map/filter, sort.
# Run:     python python/09_arrays.py
#
# KEY DIFFERENCE the user cares about:
#   Python: l.append(5), l.pop()   |   TS: l.push(5), l.pop()/l.shift()/l.unshift()
# ============================================================

# ----- 1. Create & access -----
l = [10, 20, 30]
print(l[0])                  # 10     | TS: l[0]
print(l[-1])                 # 30     | TS: l[l.length - 1]
print(len(l))                # 3      | TS: l.length

# ----- 2. Add to END -----
l.append(40)                 # [10,20,30,40]   | TS: l.push(40)
print(l)
l.extend([50, 60])           # add many         | TS: l.push(...[50,60])
print(l)                     # [10,20,30,40,50,60]

# ----- 3. Add to FRONT / specific index -----
l.insert(0, 5)               # [5,10,...]       | TS: l.unshift(5)
print(l)                     # [5, 10, 20, 30, 40, 50, 60]

# ----- 4. Remove from END -----
last = l.pop()               # removes & returns 60   | TS: l.pop()
print(last, l)               # 60 [5, 10, 20, 30, 40, 50]

# ----- 5. Remove from FRONT -----
first = l.pop(0)             # removes index 0        | TS: l.shift()
print(first, l)              # 5 [10, 20, 30, 40, 50]

# ----- 6. Remove by VALUE -----
l.remove(30)                 # deletes first 30       | TS: splice after indexOf
print(l)                     # [10, 20, 40, 50]

# ----- 7. Slicing (TS: l.slice(start, stop)) -----
print(l[1:3])                # [20, 40]
print(l[::-1])               # [50, 40, 20, 10]  (reversed)

# ----- 8. Search / membership -----
print(20 in l)               # True   | TS: l.includes(20)
print(l.index(40))           # 2      | TS: l.indexOf(40)
print(l.count(10))           # 1

# ----- 9. Transform: map / filter (TS: l.map / l.filter) -----
nums = [1, 2, 3, 4]
doubled = [x * 2 for x in nums]            # | TS: nums.map(x => x*2)
print(doubled)               # [2, 4, 6, 8]
evens = [x for x in nums if x % 2 == 0]    # | TS: nums.filter(x => x%2===0)
print(evens)                 # [2, 4]
# reduce-style:
total = sum(nums)            # | TS: nums.reduce((a,b)=>a+b, 0)
print(total)                 # 10

# ----- 10. Sort -----
vals = [3, 1, 4, 1, 5]
vals.sort()                  # in place             | TS: vals.sort((a,b)=>a-b)
print(vals)                  # [1, 1, 3, 4, 5]
print(sorted(vals, reverse=True))  # new list, desc  | TS: [...vals].sort((a,b)=>b-a)

# ----- Quick reference table (Python -> TS) -----
# len(l)            -> l.length
# l.append(x)       -> l.push(x)
# l.pop()           -> l.pop()          (both remove from END)
# l.insert(0, x)    -> l.unshift(x)     (add to FRONT)
# l.pop(0)          -> l.shift()        (remove from FRONT)
# l.remove(x)       -> l.splice(l.indexOf(x), 1)
# x in l            -> l.includes(x)
# l.index(x)        -> l.indexOf(x)
# [f(x) for x in l] -> l.map(f)
# [x for x in l if] -> l.filter(...)
# l.sort()          -> l.sort((a,b)=>a-b)   (TS sorts as strings by default!)
