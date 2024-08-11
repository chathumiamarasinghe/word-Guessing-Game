#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to choose a random word from an array
string chooseRandomWord(const string words[], int numWords) {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % numWords;
    return words[randomIndex];
}

// Function to display the current state of the word with guessed letters
void displayWord(const string& word, const bool guessed[], int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void displayHangman(int attempts) {
     switch (attempts) {
        case 0:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 1:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 2:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|       |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 3:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 4:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 5:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|      / " << endl;
            cout << "|" << endl;
            break;
        case 6:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|      / \\" << endl;
            cout << "|" << endl;
            break;
    }
}

int main() {
    const int maxAttempts = 6;
    const int numWords = 10;
    const int maxWordLength = 20; // Maximum word length
    string block;
    int score = 0;

    string word_fruit[] = {"apple", "banana", "cherry", "grape", "orange", "avocado", "papaya", "strawberry", "mango", "guava","kiwi","pineapple","watermelon","Pomegranate","blueberry"};
    string word_animal[] = {"cat", "horse", "dog", "snake", "rabbit", "elephant", "Jaguar", "Panda", "scorpion", "sheep","Shark","Zebra","Gorilla","Leopard","Kangaroo"};
    string word_vehicle[] = {"boat", "bicycle", "ship", "tractor", "plane", "truck", "excavator", "ambulance", "helicopter", "scooter","spaceshuttle","skateboard","Crane","Airplane","tram"};
    string word_Movie[]={"titanic","jurassic","inception","tenet","oppenheimer"," interstellar","Avatar","Matrix","Gravity","Gladiator"};
    string word_Planet[]={"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Pluto","Eris"};
    string word_country[]={"usa","canada","france","japan","india","brazil","australia","russia","germany","china","newzealand","maldives","nepal","pakistan","finland"};

    string word_medium[]={"apple", "banana", "cherry", "grape", "orange", "avocado", "papaya", "strawberry", "mango", "guava","kiwi","pineapple","watermelon",
	"Pomegranate","blueberry","cat", "horse", "dog", "snake", "rabbit", "elephant", "Jaguar", "Panda", "scorpion", "sheep","Shark","Zebra","Gorilla","Leopard","Kangaroo",
	"boat", "bicycle", "ship", "tractor", "plane", "truck", "excavator", "ambulance", "helicopter", "scooter","spaceshuttle","skateboard","Crane","Airplane","tram",
	"titanic","jurassic","inception","tenet","oppenheimer"," interstellar","Avatar","Matrix","Gravity","Gladiator","Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Pluto","Eris",
	"usa","canada","france","japan","india","brazil","australia","russia","germany","china","newzealand","maldives","nepal","pakistan","finland"};
    string wordToGuess;
    bool guessed[maxWordLength];
    
    string game_level;
    

    cout << "Welcome to the word master Game!" << endl;
    cout << "Guess the word" << endl;
    cout<<"select game level(easy/medium/hard)"<<endl;
    cin>>game_level;
    

    char playAgain;
   if(game_level=="easy"){
   
    do {
        cout << "Choose your field (fruit/animal/vehicle/movie/planet): ";
        cin >> block;

        if (block == "fruit") {
            wordToGuess = chooseRandomWord(word_fruit, numWords);
        } else if (block == "animal") {
            wordToGuess = chooseRandomWord(word_animal, numWords);
        } else if (block == "vehicle") {
            wordToGuess = chooseRandomWord(word_vehicle, numWords);
        } else if (block == "movie") {
            wordToGuess = chooseRandomWord(word_Movie, numWords);
        } else if (block == "planet") {
            wordToGuess = chooseRandomWord(word_Planet, numWords);
        } else if (block == "country") {
            wordToGuess = chooseRandomWord(word_country, numWords);
        }

        int wordLength = wordToGuess.length();

        for (int i = 0; i < wordLength; i++) {
            guessed[i] = false;
        }
        int attempts = 0;

        while (attempts < maxAttempts) {
            cout << "Attempts remaining: " << maxAttempts - attempts << endl;
            displayHangman(attempts);
            displayWord(wordToGuess, guessed, wordLength);

            char guess;
            cout << "Guess a letter";

            if (attempts == maxAttempts - 1) {
                cout << " or enter 'R' for a reset power-up or 'L' for a letter reveal power-up: ";
                cin >> guess;

                if (guess == 'R') {
                    // Implement code for the reset power-up (reset attempts to 0)
                    attempts = 0;
                    cout << "Reset power-up used. Attempts reset to 0." << endl;
                    continue;
                } else if (guess == 'L') {
                    // Implement code for the letter reveal power-up (reveal a letter in the word)
                    // You can randomly choose a letter to reveal.
                    int randomIndex = rand() % wordLength;
                    guessed[randomIndex] = true;
                    cout << "Letter reveal power-up used. A letter in the word is revealed." << endl;
                    continue;
                }
            } else {
                cout << ": ";
                cin >> guess;
            }

            bool correctGuess = false;
            for (int i = 0; i < wordLength; i++) {
                if (!guessed[i] && wordToGuess[i] == guess) {
                    guessed[i] = true;
                    correctGuess = true;
                }
            }

            if (correctGuess) {
                cout << "Correct guess!" << endl;
            } else {
                cout << "Incorrect guess." << endl;
                attempts++;
            }

            bool wordGuessed = true;
            for (int i = 0; i < wordLength; i++) {
                if (!guessed[i]) {
                    wordGuessed = false;
                    break;
                }
            }

            if (wordGuessed) {
                int points = maxAttempts - attempts + 1; // Award points based on attempts left
                score += points;
                cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
                cout << "Points earned for this word: " << points << endl;
                cout << "Total Score: " << score << endl;

                // Ask if the player wants to go to the next level
                cout << "Go to the next level? (y/n): ";
                cin >> playAgain;
                break;
            }
        }

        if (attempts >= maxAttempts) {
            cout << "Sorry, you've run out of attempts. The word was: " << wordToGuess << endl;
            playAgain = 'n'; // Exit if the player fails to guess
        }
    } while (playAgain == 'y' || playAgain == 'Y');
}
else if(game_level=="medium"){
	do {

       
            wordToGuess = chooseRandomWord(word_medium, numWords);
        

        int wordLength = wordToGuess.length();

        for (int i = 0; i < wordLength; i++) {
            guessed[i] = false;
        }
        int attempts = 0;

        while (attempts < maxAttempts) {
            cout << "Attempts remaining: " << maxAttempts - attempts << endl;
            displayHangman(attempts);
            displayWord(wordToGuess, guessed, wordLength);

            char guess;
            cout << "Guess a letter";

            if (attempts == maxAttempts - 1) {
                cout << " or enter 'R' for a reset power-up or 'L' for a letter reveal power-up: ";
                cin >> guess;

                if (guess == 'R') {
                    // Implement code for the reset power-up (reset attempts to 0)
                    attempts = 0;
                    cout << "Reset power-up used. Attempts reset to 0." << endl;
                    continue;
                } else if (guess == 'L') {
                    // Implement code for the letter reveal power-up (reveal a letter in the word)
                    // You can randomly choose a letter to reveal.
                    int randomIndex = rand() % wordLength;
                    guessed[randomIndex] = true;
                    cout << "Letter reveal power-up used. A letter in the word is revealed." << endl;
                    continue;
                }
            } else {
                cout << ": ";
                cin >> guess;
            }

            bool correctGuess = false;
            for (int i = 0; i < wordLength; i++) {
                if (!guessed[i] && wordToGuess[i] == guess) {
                    guessed[i] = true;
                    correctGuess = true;
                }
            }

            if (correctGuess) {
                cout << "Correct guess!" << endl;
            } else {
                cout << "Incorrect guess." << endl;
                attempts++;
            }

            bool wordGuessed = true;
            for (int i = 0; i < wordLength; i++) {
                if (!guessed[i]) {
                    wordGuessed = false;
                    break;
                }
            }

            if (wordGuessed) {
                int points = maxAttempts - attempts + 1; // Award points based on attempts left
                score += points;
                cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
                cout << "Points earned for this word: " << points << endl;
                cout << "Total Score: " << score << endl;

                // Ask if the player wants to go to the next level
                cout << "Go to the next level? (y/n): ";
                cin >> playAgain;
                break;
            }
        }

        if (attempts >= maxAttempts) {
            cout << "Sorry, you've run out of attempts. The word was: " << wordToGuess << endl;
            playAgain = 'n'; // Exit if the player fails to guess
        }
    } while (playAgain == 'y' || playAgain == 'Y');
}
	

    cout << "Thanks for playing word master! Final Score: " << score << endl;

    return 0;
}

