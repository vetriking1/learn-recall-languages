// ============================================================
// Topic:  Arrays  (FOCUS: methods & operations)
// Summary: create, access, push/pop, shift/unshift, slice, map/filter, sort.
// Run:     npx ts-node typescript/09_arrays.ts
//
// KEY DIFFERENCE the user cares about:
//   TS: l.push(5), l.pop(), l.shift(), l.unshift()
//   Python: l.append(5), l.pop(), l.pop(0), l.insert(0, x)
// ============================================================

// ----- 1. Create & access -----
const l: number[] = [10, 20, 30];
console.log(l[0]); // 10     | Python: l[0]
console.log(l[l.length - 1]); // 30     | Python: l[-1]
console.log(l.at(-1)); // 30     (.at() allows negative index)
console.log(l.length); // 3      | Python: len(l)

// ----- 2. Add to END -----
l.push(40); // [10,20,30,40]   | Python: l.append(40)
l.push(50, 60); // push many        | Python: l.extend([50,60])
console.log(l); // [10,20,30,40,50,60]

// ----- 3. Add to FRONT -----
l.unshift(5); // [5,10,...]       | Python: l.insert(0, 5)
console.log(l); // [5,10,20,30,40,50,60]

// ----- 4. Remove from END -----
const last = l.pop(); // removes & returns 60   | Python: l.pop()
console.log(last, l); // 60 [5,10,20,30,40,50]

// ----- 5. Remove from FRONT -----
const first = l.shift(); // removes & returns 5    | Python: l.pop(0)
console.log(first, l); // 5 [10,20,30,40,50]

// ----- 6. Remove / insert at index -> splice(start, deleteCount, ...items) -----
l.splice(l.indexOf(30), 1); // remove value 30    | Python: l.remove(30)
console.log(l); // [10,20,40,50]

// ----- 7. Slicing -> slice(start, stop)  (Python: l[start:stop]) -----
console.log(l.slice(1, 3)); // [20,40]
console.log([...l].reverse()); // [50,40,20,10]  (Python: l[::-1])

// ----- 8. Search / membership -----
console.log(l.includes(20)); // true   | Python: 20 in l
console.log(l.indexOf(40)); // 2      | Python: l.index(40)

// ----- 9. Transform: map / filter / reduce (Python: comprehensions) -----
const nums = [1, 2, 3, 4];
console.log(nums.map((x) => x * 2)); // [2,4,6,8]  | Python: [x*2 for x in nums]
console.log(nums.filter((x) => x % 2 === 0)); // [2,4]  | Python: [x for x in nums if ...]
console.log(nums.reduce((a, b) => a + b, 0)); // 10     | Python: sum(nums)

// ----- 10. Sort (⚠ default sort is ALPHABETICAL, even for numbers!) -----
const vals = [3, 1, 4, 1, 5, 10];
console.log([...vals].sort()); // [1,1,10,3,4,5]  ⚠ wrong for numbers!
console.log([...vals].sort((a, b) => a - b)); // [1,1,3,4,5,10] correct asc
console.log([...vals].sort((a, b) => b - a)); // [10,5,4,3,1,1] desc
// Python's l.sort() is numeric by default — TS needs a comparator.

// ----- Quick reference table (TS -> Python) -----
// l.length            -> len(l)
// l.push(x)           -> l.append(x)
// l.pop()             -> l.pop()           (both remove from END)
// l.unshift(x)        -> l.insert(0, x)    (add to FRONT)
// l.shift()           -> l.pop(0)          (remove from FRONT)
// l.splice(i, 1)      -> del l[i] / l.remove(x)
// l.includes(x)       -> x in l
// l.indexOf(x)        -> l.index(x)
// l.map(f)            -> [f(x) for x in l]
// l.filter(f)         -> [x for x in l if ...]
// l.sort((a,b)=>a-b)  -> l.sort()          (TS needs comparator for numbers!)
