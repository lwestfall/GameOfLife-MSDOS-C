# Game Of Life (MS-DOS - C)

This is another iteration of Conway's Game Of Life. This one is written for MS-DOS in C. I wrote it just for fun in the span of about 4 hours (most of that time spent reaquainting myself with C). This is my second implementation, the first was in vanilla Javascript and it can [be played here](https://lwestfall.github.io/GameOfLifeJS/), or the source code can [be viewed here](https://github.com/lwestfall/GameOfLifeJS).

For the extra challenge, I wrote and debugged the entire program in DOS using Borland Turbo C 2.01 (released in 1989 - a year before I was born). This constraint renewed my appreciation for modern IDEs.

There are a few improvements that could be made. Dynamic allocation of the game state arrays should allow for half the number of iterations. This might also increase the limitation of the array size for the game board. There is also no clean way to end the program once it's started. I plan to add interrupt handling to end the program and maybe other things like restarting from a new random state, etc.

I do hope to get the compiled executable runnable in browser via Dosbox. This isn't something I've done before so I need more time to learn how that's done and whether I can host it in Github pages or on my own server.

## Why do you do this? It's been done before

Because Game of Life is fun. It's more challenging and interesting than a lot of the other typical programming projects, but still completely doable in a few hours. Plus cellular automata are just cool.
