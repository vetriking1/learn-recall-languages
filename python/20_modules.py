# ============================================================
# Topic:  Modules & Imports  (FOCUS: import, from-import, alias, __name__)
# Summary: Organize code into modules; stdlib import patterns.
# Run:     python python/20_modules.py
#
# KEY DIFFERENCES:
#   Python:  import / from … import / as alias + sys.path
#   TS/JS:   import / export (ES modules) | require (CommonJS)
#   Rust:    mod + use + crate system
#   Java:    package + import
#   C++:     #include + namespaces
# ============================================================

import json
import math
import sys
import types
from math import sqrt
import math as m


# ----- Package layout (multi-file) -----
# mypkg/
#   __init__.py      def greet(): return "Hi"
#   utils.py         helper functions
# from mypkg import greet


# ----- 1. Import module — use math and json -----
def demo_import_module():
    data = json.dumps({"pi": round(math.pi, 2)})
    parsed = json.loads(data)
    print(f"pi: {parsed['pi']:.2f}", flush=True)  # Output: pi: 3.14


# ----- 2. from-import — pull a name from a module -----
_demo_pkg = types.ModuleType("demo_pkg")
_demo_pkg.greet = lambda: "Hi"
sys.modules["demo_pkg"] = _demo_pkg


def demo_from_import():
    from demo_pkg import greet

    print(f"greet: {greet()}", flush=True)  # Output: greet: Hi


# ----- 3. Alias — import math as m; from math import sqrt -----
def demo_alias():
    print(f"sqrt: {sqrt(25)}", flush=True)  # Output: sqrt: 5.0
    print(f"alias: {int(m.pow(5, 2))}", flush=True)  # Output: alias: 25


# ----- 4. __name__ — script vs imported module -----
def demo_name():
    if __name__ == "__main__":
        print("main module", flush=True)  # Output: main module


# ----- 5. sys.path note -----
# sys.path lists directories Python searches for modules (cwd, stdlib, site-packages).
# Add a path with sys.path.insert(0, "/my/project") or set PYTHONPATH.


def main():
    # ----- 1. Import module -----
    demo_import_module()

    # ----- 2. from-import -----
    demo_from_import()

    # ----- 3. Alias -----
    demo_alias()

    # ----- 4. __name__ -----
    demo_name()


if __name__ == "__main__":
    main()

# Cross-language note:
#   Python modules are .py files; packages are folders with __init__.py.
#   __name__ == "__main__" guards script-only code (like Java public static void main).
#   JS/TS use export/import; Rust uses mod/use; Java uses package/import; C++ uses #include.