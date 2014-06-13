chromadepthGLSL
===============

a chromadepth shader in openFrameworks


This is a GLSL example for using [Chromadepth 3D glasses](http://en.wikipedia.org/wiki/ChromaDepth).

The base of the shader was taken from [this site](http://eclecti.cc/computergraphics/cheap-3d-in-opengl-with-a-chromadepth-glsl-shader) and hacked to work the way I wanted it to.

There are two different shaders:

- chromadepth_texture.frag/vert uses a texture mapped to the 3D shape and correctly colors the the shape and texture based on the depth.
![1](https://raw.githubusercontent.com/fakelove/chromadepthGLSL/master/screenshots/Screenshot%202014-06-13%2016.41.11.png)
- chromadepth.frag/vert simply colors the shape based on the shapes depth
![2](https://raw.githubusercontent.com/fakelove/chromadepthGLSL/master/screenshots/Screenshot%202014-06-13%2017.02.02.png)


