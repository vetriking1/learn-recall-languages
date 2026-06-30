// ============================================================
// Topic:  Generics  (FOCUS: generic functions, classes, constraints)
// Summary: Generic functions, generic class, extends constraint, multiple T/U, generic array fn.
// Run:     npx ts-node typescript/19_generics.ts
//
// KEY DIFFERENCES:
//   Python:  typing.TypeVar / Generic (runtime erasure — no true generics)
//   TS/JS:   generics compile-time only; erased at runtime
//   Rust:    monomorphized generics (zero-cost, no erasure)
//   Java:    type erasure; bounded wildcards <? extends T>, <? super T>
//   C++:     templates (compile-time instantiation)
// ============================================================

// ----- Generic class -----
class Box<T> {
  constructor(private readonly value: T) {}

  get(): T {
    return this.value;
  }
}

// ----- Generic pair class (multiple type params T, U) -----
class Pair<K, V> {
  constructor(
    private readonly key: K,
    private readonly value: V
  ) {}

  toString(): string {
    return `${this.key} ${this.value}`;
  }
}

// ----- Generic function — swap two elements -----
function swap<T>(arr: T[], i: number, j: number): void {
  const temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// ----- Bounded type parameter <T extends number> -----
function max<T extends number>(a: T, b: T): T {
  return (a >= b ? a : b) as T;
}

// ----- Generic array function — count items -----
function countItems<T>(items: T[]): number {
  return items.length;
}

// ----- 1. Generic method — swap -----
const nums = [1, 2];
swap(nums, 0, 1);
console.log(`swap: ${nums[0]} ${nums[1]}`); // Output: swap: 2 1

// ----- 2. Generic class — Box<string> -----
const box = new Box("hello");
console.log(`box: ${box.get()}`); // Output: box: hello

// ----- 3. Bounded type param — max -----
console.log(`max: ${max(9, 3)}`); // Output: max: 9

// ----- 4. Generic pair -----
const pair = new Pair(1, "two");
console.log(`pair: ${pair}`); // Output: pair: 1 two

// ----- 5. Generic array function — count items -----
const items = [10, 5, 10];
console.log(`items: ${countItems(items)}`); // Output: items: 3

// Cross-language note:
//   TS <T> on functions/classes mirrors Java generics; erased at runtime like Java.
//   extends constraint (T extends number) == Java <T extends Number>.
//   Pair<K,V> with two type params == Java Map.Entry-style multi-param generics.