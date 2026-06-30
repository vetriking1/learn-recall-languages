// ============================================================
// Topic:  Arrays / Lists  (FOCUS: methods & operations)
// Summary: Create, access, add, remove, slice, LINQ, sort.
// Run:     dotnet script csharp/09_arrays.cs
//
// KEY DIFFERENCE the user cares about:
//   C# List: l.Add(5), l.RemoveAt(0)   |   Python: l.append(5), l.pop(0)
//   C# List: l.Add(5)                  |   TS: l.push(5), l.shift()/l.unshift()
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;

// ----- 1. Create & access -----
var l = new List<int> { 10, 20, 30 };
Console.WriteLine(l[0]);                  // 10     | TS: l[0]   | Python: l[0]
Console.WriteLine(l[^1]);                 // 30     | TS: l.at(-1) | Python: l[-1]
Console.WriteLine(l.Count);               // 3      | TS: l.length | Python: len(l)

// ----- 2. Add to END -----
l.Add(40);                                // [10,20,30,40]   | TS: l.push(40)   | Python: l.append(40)
Console.WriteLine($"[{string.Join(", ", l)}]");
l.AddRange(new[] { 50, 60 });             // add many          | TS: l.push(...[50,60]) | Python: l.extend
Console.WriteLine($"[{string.Join(", ", l)}]"); // [10, 20, 30, 40, 50, 60]

// ----- 3. Add to FRONT -----
l.Insert(0, 5);                           // [5,10,...]        | TS: l.unshift(5) | Python: l.insert(0, 5)
Console.WriteLine($"[{string.Join(", ", l)}]"); // [5, 10, 20, 30, 40, 50, 60]

// ----- 4. Remove from END -----
int last = l[^1];
l.RemoveAt(l.Count - 1);                  // removes & returns last | TS/Python: l.pop()
Console.WriteLine($"{last} [{string.Join(", ", l)}]"); // 60 [5, 10, 20, 30, 40, 50]

// ----- 5. Remove from FRONT -----
int first = l[0];
l.RemoveAt(0);                            // removes index 0      | TS: l.shift() | Python: l.pop(0)
Console.WriteLine($"{first} [{string.Join(", ", l)}]"); // 5 [10, 20, 30, 40, 50]

// ----- 6. Remove by VALUE -----
l.Remove(30);                             // deletes first 30     | TS: splice after indexOf
Console.WriteLine($"[{string.Join(", ", l)}]"); // [10, 20, 40, 50]

// ----- 7. Slicing (Python: l[start:stop]; TS: l.slice(start, stop)) -----
Console.WriteLine($"[{string.Join(", ", l.GetRange(1, 2))}]"); // [20, 40]
Console.WriteLine($"[{string.Join(", ", l.AsEnumerable().Reverse())}]"); // [50, 40, 20, 10]

// ----- 8. Search / membership -----
Console.WriteLine(l.Contains(20));        // True   | TS: l.includes(20) | Python: 20 in l
Console.WriteLine(l.IndexOf(40));         // 2      | TS: l.indexOf(40)  | Python: l.index(40)

// ----- 9. Transform: Select / Where / Sum (Python: comprehensions; TS: map/filter/reduce) -----
var nums = new List<int> { 1, 2, 3, 4 };
Console.WriteLine($"[{string.Join(", ", nums.Select(x => x * 2))}]"); // [2, 4, 6, 8]
Console.WriteLine($"[{string.Join(", ", nums.Where(x => x % 2 == 0))}]"); // [2, 4]
Console.WriteLine(nums.Sum());            // 10     | TS: reduce | Python: sum(nums)

// ----- 10. Sort (C# Sort is numeric for int — unlike TS default string sort!) -----
var vals = new List<int> { 3, 1, 4, 1, 5, 10 };
var copy = new List<int>(vals);
copy.Sort();                              // in place, numeric for int
Console.WriteLine($"[{string.Join(", ", copy)}]"); // [1, 1, 3, 4, 5, 10]
vals.Sort((a, b) => b.CompareTo(a));      // descending
Console.WriteLine($"[{string.Join(", ", vals)}]"); // [10, 5, 4, 3, 1, 1]

// ----- Quick reference table (C# -> Python/TS) -----
// l.Count             -> len(l) / l.length
// l.Add(x)            -> l.append(x) / l.push(x)
// l.RemoveAt(last)    -> l.pop() / l.pop()           (remove from END)
// l.Insert(0, x)      -> l.insert(0, x) / l.unshift(x)
// l.RemoveAt(0)       -> l.pop(0) / l.shift()        (remove from FRONT)
// l.Remove(x)         -> l.remove(x) / l.splice(l.indexOf(x), 1)
// l.Contains(x)       -> x in l / l.includes(x)
// l.IndexOf(x)        -> l.index(x) / l.indexOf(x)
// l.Select(f)         -> [f(x) for x in l] / l.map(f)
// l.Where(f)          -> [x for x in l if ...] / l.filter(f)
// l.Sort()            -> l.sort() / l.sort((a,b)=>a-b)  (C# int sorts numerically by default)