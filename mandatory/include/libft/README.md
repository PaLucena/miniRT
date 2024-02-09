# Lib

As a 42 student, I can't use some standard libraries in C, so I have to create my own in an excercise of further comprehension of the functions which I utilise daily in my advances through the 42 Cursus.

Following that note, the goal of this repository is to create exacly that, my own version of those Standard C Library functions and some more that I find useful so I can have access to them in the future.

For the moment, the library includes `libft`, `printf`, `get_next_line` and some of my own homemade functions that I've found useful during my growth.

## How does it work?

It creates a library called **libft.a** with all those functions I might need in my projects.

If you want to use the library, first you have to download the files by cloning the git repository:
```
git clone git@github.com:PaLucena/lib.git lib
```

To create that library, all you need to do (if you have it installed) is to enter the project and call `make`;

```
cd lib
make
```

That should create a libftprintf.a file and some object files.

To remove all those files once you're finished just call `make fclean`
