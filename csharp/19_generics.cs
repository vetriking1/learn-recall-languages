// ============================================================
// Topic:  Generics
// Summary: Generic methods, generic class, where constraints, multiple type params.
// Run:     dotnet script csharp/19_generics.cs
//
// KEY DIFFERENCES:
//   C#:     <T>, where constraints, reified generics at runtime (value types)
//   Python: typing.TypeVar, Generic[T] — erased at runtime
//   TS:     <T>, extends constraint — erased at compile time
//   Rust:   <T>, trait bounds (where T: Ord)
//   Java:   <T>, bounded wildcards (? extends T) — type erasure
// ============================================================

using System;
using System.Collections.Generic;

// ----- 1. Generic method — Swap<T> with ref params -----
void Swap<T>(ref T a, ref T b) => (a, b) = (b, a);   // swap      | works for any T

int x = 1, y = 2;
Swap(ref x, ref y);
Console.WriteLine($"swap: {x} {y}");                 // swap: 2 1

// ----- 2. Generic class — Box<T> holds one value -----
class Box<T>
{
    public T Value { get; }
    public Box(T value) => Value = value;
}

var box = new Box<string>("hello");
Console.WriteLine($"box: {box.Value}");              // box: hello

// ----- 3. Generic method + where constraint — IComparable<T> -----
T Max<T>(T a, T b) where T : IComparable<T>          // where     | T must be comparable
    => a.CompareTo(b) >= 0 ? a : b;

Console.WriteLine($"max: {Max(9, 3)}");              // max: 9

// ----- 4. Multiple type parameters — Pair<TFirst, TSecond> -----
class Pair<TFirst, TSecond>
{
    public TFirst First { get; }
    public TSecond Second { get; }
    public Pair(TFirst first, TSecond second)
    {
        First = first;
        Second = second;
    }
    public override string ToString() => $"{First} {Second}";
}

var pair = new Pair<int, string>(1, "two");
Console.WriteLine($"pair: {pair}");                  // pair: 1 two

// ----- 5. Generic class with collection — count items -----
class Container<T>
{
    private readonly List<T> items = new();
    public void Add(T item) => items.Add(item);
    public int Count => items.Count;
}

var container = new Container<int>();
container.Add(10);
container.Add(20);
container.Add(30);
Console.WriteLine($"items: {container.Count}");      // items: 3

// Cross-language note:
//   where T : class — reference type only; where T : struct — value type only.
//   where T : new() — T must have parameterless constructor (factory patterns).
//   C# generics are reified — List<int> and List<string> are distinct at runtime.
//   Covariance (IEnumerable<out T>) and contravariance (Action<in T>) apply to interfaces/delegates.