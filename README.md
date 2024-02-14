# cpPong

This is an simple Pong game clone made with SFML. The objective of this project was to practice C++ and the SFML framework.

## Game Logic

The game logic is much simple and will be:
	- The player moves the left paddle up and down with 'W' and 'S' key.
	- The ball starts moving within a random angle and will bounce within the 'red box' in the screen.
	- The enemy paddle follows automaticaly the ball's position.
	- The player scores if the enemy cannot hit the ball.
	- The player loses an score point if he cant hit the ball.
	- If the player scores, the ball gains velocity.
	- If the player loses an score, the ball loses velocity.
	- The game continues while the player has >= 0 score points.