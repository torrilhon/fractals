# Original 1998/99 Windows program

These are the unmodified sources of the original `Fraktal.exe`, a Borland C++ Builder 1.0
(VCL) project written in October 1998 – January 1999. The compiled executable is not
included here.

| File | Purpose |
|---|---|
| `Fraktal.cpp`, `Fraktal.mak`, `Fraktal.res` | `WinMain`, the C++ Builder 1 project makefile, icon resource |
| `Frak1.h/.cpp` | The maths: a point class, an affine frame (`DrehKoord`) and the six user parameters of a map (`Trafo`) |
| `FrakMain.h/.cpp/.dfm` | Main window: recursive drawing (`ZeichneEbene`), buttons *Los !*, *Trafo*, *Fest*, right-click depth menu |
| `FrakTrans.h/.cpp/.dfm` | "Der Transformator": arrow buttons that change translation, rotation, scale, shear and x-scale of the active map |

The program draws a two-map iterated function system. The seed is the thin triangle with
corners (-0.1,-0.4), (0.1,-0.4), (0,0.6). Two affine maps T1 and T2 are applied recursively
to the seed down to a chosen depth and every triangle outline is drawn. `index.html` in the
repository root is the modern re-implementation of the same idea.

The `.dfm` files are binary Delphi form files; the `.res` file is the application icon.
