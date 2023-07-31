<h1>Snake Game in C</h1>
This is a simple Snake game implemented in C language using the console as the game interface. 
The game allows you to control a snake and eat food to grow longer.
The objective is to obtain the highest score possible without colliding with the walls or the snake's body.

<h2>How to Compile and Run</h2>
Requirements
<ul>

<li>C compiler (e.g., GCC, Visual Studio, etc.)</li>
		<li>Windows OS (for Windows users)</li>
</ul>

<h3>Steps to Compile and Run</h3>

<ol>
<li>Clone this repository to your local machine</li>
    git clone https://github.com/HAnjula/cobra-game.git <br>
    cd cobra-game.git<br>


<li>Compile the C code using a C compiler. Here are some examples:</li>

  
 For GCC (Linux/macOS):
		gcc snake.c -o snake

 
For Visual Studio (Windows):
			cl snake.c
	 
<li>After compiling successfully, run the executable:</li>
		For Linux/macOS:
		./snake
	
For Windows:
    snake.exe

  </ol>  
		
  <h3>How to Play</h3>
  Use the following keys to control the snake's movement:

<ul>
<li>'w' to move up <br></li>
<li>'d' to move right</li>
<li>'s' to move down</li>
<li>'a' to move left</li>
<li>'q' to quit the game</li>
</ul>
The objective is to eat the food ('@') to grow longer and increase your score.

The game ends if the snake collides with the walls or its own body.

<h4>Game Controls</h4>
Press 'q' to quit the game at any time.


<h5>Gameplay Tips</h5>

Try to eat as much food as possible to increase your score.
Be careful not to run into the walls or the snake's body, as this will end the game.
License
This Snake game is licensed under the MIT License.

Please make sure to replace "your-username" and "your-repo" with your actual GitHub username and repository name in the clone URL. Also, adjust the compilation commands if necessary, based on the compiler you are using.
