// ============================================================
// Topic:  Language-Specific Features  (FOCUS: TS/JS idioms)
// Summary: union narrowing, ?., ??, keyof/typeof, satisfies, template literal types.
// Run:     npx ts-node typescript/21_language_features.ts
//
// KEY DIFFERENCES:
//   Python:  Union via typing.Union / | ; no ?. or ?? (use getattr / or)
//   TS/JS:   structural types, compile-time checks, erased at runtime
//   Rust:    enums + match for narrowing; Option<T> instead of ?. / ??
//   Java:    no union types; Optional.orElse for null coalescing
//   C++:     std::variant / std::optional; no keyof/typeof type operators
// ============================================================

// ----- Union + narrowing helper -----
type Scalar = string | number;

function asNumber(value: Scalar): number | null {
  if (typeof value === "number") {
    return value;
  }
  return null;
}

// ----- Optional chaining demo shape -----
type Profile = { nickname?: string };
type Account = { profile?: Profile };

// ----- keyof / typeof demo object -----
const sample = { name: "Ada", age: 36 } as const;
type Sample = typeof sample;
type SampleKey = keyof Sample;

// ----- Interface + satisfies -----
interface ServiceConfig {
  readonly label: string;
  readonly retries: number;
}

// ----- Template literal type + const enum -----
type HttpVerb = "GET" | "POST" | "PUT";
type ApiPath = `/api/${string}`;
type ApiRequest = `${HttpVerb} ${ApiPath}`;

const enum Method {
  Get = "GET",
  Post = "POST",
}

// ----- 1. Union + type narrowing -----
const id: Scalar = 42;
const narrowed = asNumber(id);
if (narrowed !== null) {
  console.log(`narrow: ${typeof narrowed}`); // Output: narrow: number
}

// ----- 2. Optional chaining ?. -----
const account: Account = {};
const nickname = account.profile?.nickname ?? "none";
console.log(`chain: ${nickname}`); // Output: chain: none

// ----- 3. Nullish coalescing ?? -----
const missing: string | null | undefined = null;
const fallback = missing ?? "default";
console.log(`coalesce: ${fallback}`); // Output: coalesce: default

// ----- 4. keyof / typeof -----
const field: SampleKey = "name";
console.log(`key: ${typeof sample[field]}`); // Output: key: string

// ----- 5. Interface + satisfies -----
const service = {
  label: "ok",
  retries: 3,
} satisfies ServiceConfig;
console.log(`typed: ${service.label}`); // Output: typed: ok

// ----- 6. Template literal type or const enum -----
const request: ApiRequest = "GET /api/users";
void request;
console.log(`literal: ${Method.Get}`); // Output: literal: GET

// Cross-language note:
//   string | number + typeof guard  == Python isinstance(x, int) narrowing
//   obj?.a?.b                     == Python getattr chain with None checks
//   x ?? "default"                == only null/undefined; unlike Python `or` (falsy)
//   keyof typeof obj              == no direct Python equivalent at type-check time
//   satisfies Config              == validate shape without widening inferred literals
//   `GET /api/${string}`          == compile-time string pattern; const enum inlines values