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


The code in this repository is available under the [MIT License](https://secure.wikimedia.org/wikipedia/en/wiki/Mit_license).

The MIT License (MIT) Copyright (c) 2016 Fake Love Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
