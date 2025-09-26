# Rock-Paper-Scissors-Spock-Lizard

This is a basic C program made for the DTU course 62712. It is based on the game RPSSL from the popular TV show The Bing Bang Theory.

It allows the user to play RPSSL against the computer by letting them input a move key and randomly generating a move for the computer to play.
It also allows the user to specify how many points should be required to win.


## Explanation for buffer clearer

Every time getchar() is called it advances the buffer by 1. The while loop keeps ckecking the condition and doing nothing in its body, clearing everything in the buffer until it reaches a newline or EOF (already having cleare \n), clearing the buffer.