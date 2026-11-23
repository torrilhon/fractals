# Fractals from linear mappings

An interactive designer for fractals built from iterated affine maps, in a single
self-contained HTML file. Live version: **https://torrilhon.github.io/fractals/**

![Binary tree preset](docs/screenshot.png)

## Idea

A thin seed triangle is drawn, then every map is applied to it, then every map is applied
to each of those copies, and so on down to a chosen depth. Two or more contracting maps
produce the familiar fractal trees, dragons and ferns; the presets cover the classics.

## Using it

* Open `index.html` in any browser, offline is fine. There are no dependencies.
* Map 0 is the seed triangle. Every other map is a linear map applied to it, shown as a
  coloured outline. Tap an outline to select it, drag inside to move it.
* On the selected frame, the two square corners scale proportionally (Shift for free
  scaling), the two curved corners rotate about the centre (Shift snaps to 15°), the bars on
  the top and right edges stretch in one direction, and the slanted handles on the bottom and
  left edges shear along that edge.
* Add, duplicate, remove and reset maps in the panel, or type the matrix entries directly.
* Drag empty space to pan, use the mouse wheel or pinch to zoom, press *Fit* to frame the drawing.
* The address bar always holds a link that reproduces the current figure. *Save PNG* exports the drawing.

## Publishing

The workflow in `.github/workflows/pages.yml` deploys the repository root to GitHub Pages on
every push to `main`. In the repository settings under *Pages*, set *Source* to *GitHub Actions* once.

## History

The `legacy/` folder holds the original 1998 Borland C++ Builder program this is based on.
