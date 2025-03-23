# Bowling Game Console Application

This is a C++ console application that implements a bowling game scoring system. It handles strikes, spares, and bonus rolls, providing real-time frame scoring.

## How to Run
1. Clone the repository:
    git clone https://github.com/<username>/BowlingGameConsoleApp.git
2. Navigate to the project directory and compile the code:
    g++ -o BowlingGame BowlingGame.cpp
3. Run the application:
   ./BowlingGame
   
## Example Gameplay
Welcome to the Bowling Game!
Enter the number of pins knocked down for each roll (0-10):
Roll for Frame 1: 4

Live Frame Scores:
Frame 1: Roll1=4, Score=0
Roll for Frame 1: 6

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=10
Frame 2: No rolls yet, Score=0
Roll for Frame 2: 5

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Score=0
Roll for Frame 2: 5

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=25
Frame 3: No rolls yet, Score=0
Roll for Frame 3: 4

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Score=0
Roll for Frame 3: 3

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: No rolls yet, Score=0
Roll for Frame 4: 10

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=46
Frame 5: No rolls yet, Score=0
Roll for Frame 5: 11
Invalid input! Please enter a number between 0 and 10.
Roll for Frame 5: 5

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=46
Frame 5: Roll1=5, Score=0
Roll for Frame 5: 7
Invalid input, Total pins in a frame cannot exceed 10.
Roll for Frame 5: 5

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=66
Frame 6: No rolls yet, Score=0
Roll for Frame 6: 10

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=86
Frame 7: No rolls yet, Score=0
Roll for Frame 7: 10

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=86
Frame 7: Roll1=10, Score=96
Frame 8: No rolls yet, Score=0
Roll for Frame 8: 10

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=96
Frame 8: Roll1=10, Score=106
Frame 9: No rolls yet, Score=0
Roll for Frame 9: 0

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=126
Frame 8: Roll1=10, Score=106
Frame 9: Roll1=0, Score=0
Roll for Frame 9: 1

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=126
Frame 8: Roll1=10, Score=137
Frame 9: Roll1=0, Roll2=1, Score=138
Frame 10: No rolls yet, Score=0
Roll for Frame 10: 5

Live Frame Scores:
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=126
Frame 8: Roll1=10, Score=137
Frame 9: Roll1=0, Roll2=1, Score=138
Frame 10: Roll1=5, Score=143
Roll for Frame 10: 7
Invalid input, Total pins in first two rolls cannot exceed 10.
Roll for Frame 10: 5

Live Frame Scores:
Frame 10: Waiting for bonus rolls...
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=126
Frame 8: Roll1=10, Score=137
Frame 9: Roll1=0, Roll2=1, Score=138
Frame 10: Roll1=5, Roll2=5, Score=148
Roll for Frame 10: 11
Invalid input! Please enter a number between 0 and 10.
Roll for Frame 10: 10

Live Frame Scores:
Frame 10: Bonus rolls complete.
Frame 1: Roll1=4, Roll2=6, Score=15
Frame 2: Roll1=5, Roll2=5, Score=29
Frame 3: Roll1=4, Roll2=3, Score=36
Frame 4: Roll1=10, Score=56
Frame 5: Roll1=5, Roll2=5, Score=76
Frame 6: Roll1=10, Score=106
Frame 7: Roll1=10, Score=126
Frame 8: Roll1=10, Score=137
Frame 9: Roll1=0, Roll2=1, Score=138
Frame 10: Roll1=5, Roll2=5, Roll3=10, Score=158

Final Score: 158
