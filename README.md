Gnomish
=======

Open Source Local or Networked, Single or Multi-player Game Engine. Engine made so that anyone can develop a game with it. Uses scripting for advanced game creation.


**Developer Information**

Moved implementation over to C from Java. Current implementation is in *Gnomish/cimpl* instead of *Gnomish/src*.

Project requires gcc, OpenGL:
```sh
$ sudo apt-get install freeglut3-dev
```

To build and run the project:
```sh
Gnomish/cimpl/src$ make && ./gnomish.out
```

