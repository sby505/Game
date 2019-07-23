# Game

I created a simple language learning game in C++ to help me learn German vocabulary quickly. 

The game will output the English word and prompt the user for the German translation.

If the user gets the word wrong, he/she is given two more chances and receives a small point deduction after each false attempt.

The user may also pass if he/she doesn't want to guess. This will result in a full point deduction and the word will be added to the "WORK ON:" list.

After the user has attempted all the words in the file, a score is outputted along with the vocab words the user may want to review.


Updated Version -----------------------------------------------------------------------------------------------------

In the updated version, the user has the ability to play again Angela Merkel (computer) and request and receive hints. The user can only request ONE hint per game.


TO RUN IN TERMINAL:

g++ main.cpp -std=c++11 -o main

./main
