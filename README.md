# TUIC

TUIC is an open source, backend agnostic Text-User-Interface rendering library written in C. TUIC can be used directly, but is designed for usage as a renderer by other libraries, such as those made for the creation of Roguelike games.

* Documentation site: https://journeyman-dev.github.io/TUIC/
* Discord chat: https://discord.gg/KbuMynmkRk

# Features


 * Highly customizable TUI tile based rendering, with support for multiple color, glyph, and layout modes using Opengl 3.3.
 * Tools for rendering TUI batches to framebuffers and rendering framebuffers to each other or to the screen.
 * A fully integrated windowing and input management system, with support for rendering to multiple windows at once.
 * PNG image loading, saving, and manipulation tools.
 * A system for creating and employing custom glyph atlases. 
 * Tools for the control of color palettes, including built in XTerm palette generation.
 * Built in tile data batching mechanism designed to pack the bytes in as little space as possible for extreme performance.
 * Modern object oriented design with well defined rules for creation and destruction of the included opaque C structs.
 * An included debug error callback system with verbose error descriptions.
 
# Showcase

 * [Matrix rain example video](https://youtu.be/XbBF8AwEcwg)
