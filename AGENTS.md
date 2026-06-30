# AGENTS.md — how to maintain & extend this workspace

This file is the contract for anyone (human or AI agent) adding to
**AllLanguages**. The goal of the repo: a place to **learn** a programming
concept and **recall** the exact syntax/method that differs across languages,
backed by files you can actually run.

Read this before adding files so everything stays consistent.

## Mental model

- One **topic** (e.g. "strings") = one source file per language + one
  comparison page in `docs/`.
- Source files are **runnable, self-contained, dependency-free** demos — not
  libraries. Every interesting line prints something and shows its expected
  output in a comment.
- `docs/*.html` are the "good view": side-by-side comparison tables a learner
  scans to recall a method name.

## Directory & naming conventions

```
<language>/NN_topic.ext        e.g. python/08_strings.py, typescript/08_strings.ts
docs/topic.html                e.g. docs/strings.html
```

- `NN` is a two-digit order prefix (`01`–`09` for basics). Keep the same number
  for the same topic across every language.
- Topic slug is identical across languages and matches the `docs/` page name.
- Languages live in their own top-level folder: `python/`, `typescript/`,
  `csharp/`, `rust/`, `cpp/`, `java/`.

Current topic order: `01 variables · 02 datatypes · 03 operators ·
04 conditions · 05 loops · 06 io · 07 functions · 08 strings · 09 arrays`.
OOP topics: `10 classes · 11 encapsulation · 12 inheritance · 13 polymorphism ·
14 abstraction`. Data structures: `15 data_structures` (maps, sets, stack,
queue, heap, tuples — one file per language, not split by type). Async:
`16 async_await` (async/await or language equivalent — one file per language).
Concurrency: `17 threads_and_processes` (multithreading + multiprocessing in one
file per language). Higher concepts: `18 error_handling`, `19 generics`,
`20 modules` (one file per topic per language). Language spotlight:
`21 language_features` (six idioms unique to each language — sections differ
per file; docs use thematic rows, not 1:1 method recall). Rust has no
classes/inheritance — those files use `struct`+`impl`, module privacy, and
`trait`s (with a cross-language note explaining why).

## Source file conventions (every code file)

1. **Header block** with: topic name, one-line summary, and the exact run
   command. Use the language's comment syntax.
2. **Numbered sections** (`----- 1. Thing -----`) each teaching one idea.
3. **Runnable examples** that print real output, with the expected result on the
   same/next line as a comment: `# Output: ...` (Python) or `// Output: ...` (TS).
4. **Cross-language notes** at the bottom — call out where the method name or
   behavior differs (this is the whole point of the repo).
5. No external dependencies. Files reading stdin must document a pipe example
   (e.g. `echo "x" | python python/06_io.py`).

## Comparison page conventions (`docs/*.html`)

- Copy an existing topic page (e.g. `docs/loops.html`) as the template.
- Use `style.css` — never inline a new theme. Shared classes:
  `table.cmp`, `td.op`, `.badge.py`, `.badge.ts`, `.note`, `.note.warn`,
  `.files`.
- Structure: sticky `header.topbar` → `<h1>` + `.subtitle` → `.files` links to
  the source files → one or more `table.cmp` → `.note` / `.note.warn` callouts.
- Table columns: **Operation** | **Python** | **TypeScript** (add a new column
  per language — see below). Put real, copy-pasteable snippets in `<code>`.
- Add a card for any new topic to the grid in `docs/index.html`.
- Escape HTML in code: `&lt; &gt; &amp;`.

## How to add a new LANGUAGE (e.g. Rust)

1. Create `rust/NN_topic.rs` for each existing topic, following the source file
   conventions. Match the section structure of the Python/TS files so they line
   up conceptually.
2. Add a `<th><span class="badge rust">Rust</span></th>` column header and a
   `<td><code>…</code></td>` cell to every row in each `docs/*.html` table.
   (Add a `.badge.rust` color in `style.css`.)
3. Add the run command to `README.md` and `docs/index.html`'s cheatsheet.
4. **Verify** (see below) before considering it done.

## How to add a new TOPIC (e.g. classes/OOP)

1. Pick the next `NN`. Create the source file in every language folder.
2. Create `docs/<topic>.html` from the template; add its card to
   `docs/index.html` and a row to the table in `README.md`.

## Verification — REQUIRED before claiming done

Run the files; outputs must match the `Output:` comments with no errors.

```bash
# Python — run each non-interactive file
python python/NN_topic.py

# TypeScript — install once, then run (and type-check) each file
cd typescript && npm install
npx ts-node NN_topic.ts

# Interactive (io) files — pipe input
echo "Vetri" | python python/06_io.py
```

TypeScript runs under **strict** mode (`typescript/tsconfig.json`, target
ES2022). Notes from this codebase:

- Avoid top-level `const name` / `const status` if you ever add the DOM lib —
  they collide with browser globals. (We currently use `lib: ["ES2022"]` only.)
- To *demonstrate* deliberately "wrong" code (e.g. loose `==`, comparing a
  string to a number), route it through an `any`-typed helper or variable so it
  compiles while still teaching the point. See `typescript/03_operators.ts`.
- `.at(-1)` needs ES2022; `replaceAll` needs ES2021+.

Open `docs/index.html` in a browser and click through to confirm new
pages/links render.

## Style principles

- Comments teach; prefer one clear idea per section over dense cleverness.
- Keep both languages' files in the same section order so a learner can read
  them side-by-side.
- When languages diverge, **say so explicitly** in a cross-language note — that
  divergence is the most valuable content here.
