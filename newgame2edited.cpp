#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>  
#include <vector>   

using namespace std;

// Function to choose a random word from an array
string chooseRandomWord(const string words[], int numWords) {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % numWords;
    return words[randomIndex];
}

// Function to choose a random word from a vector
string chooseRandomWordFromVector(const vector<string>& words) {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}


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


vector<string> loadWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename.c_str());  // Convert std::string to const char* using c_str()
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    return words;
}


string provideHint(const string& word) {
    
    return string(1, word[0]);
}


char getValidatedInput() {
    char input;
    while (true) {
        cin >> input;
        if (isalpha(input)) {
            input = tolower(input);  // Convert to lowercase
            break;
        } else {
            cout << "Invalid input. Please enter a letter: ";
        }
    }
    return input;
}

int main() {
    const int maxAttempts = 6;
    int score = 0;

    // Word categories
    string word_fruit[] = {"apple", "banana", "cherry", "grape", "orange", "avocado", "papaya", "strawberry", "mango", "guava"};
    string word_animal[] = {"cat", "horse", "dog", "snake", "rabbit", "elephant", "Jaguar", "Panda", "scorpion", "sheep"};
    string word_vehicle[] = {"boat", "bicycle", "ship", "tractor", "plane", "truck", "excavator", "ambulance", "helicopter", "scooter"};
    string word_movie[] = {"titanic", "jurassic", "inception", "tenet", "oppenheimer", "interstellar", "avatar", "matrix", "gravity", "gladiator"};
    string word_planet[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto", "eris"};
    string word_country[] = {"usa", "canada", "france", "japan", "india", "brazil", "australia", "russia", "germany", "china"};

    vector<string> dynamic_words = loadWordsFromFile("words.txt");  // Example of dynamic word list

    string wordToGuess;
    bool guessed[20];
    string game_level, category;
    char playAgain;

    cout << "Welcome to the Word Master Game!" << endl;
    cout << "Guess the word" << endl;
    cout << "Select game level (easy/medium/hard): ";
    cin >> game_level;

    do {
        if (game_level == "easy") {
            cout << "Choose your field (fruit/animal/vehicle/movie/planet/country): ";
            cin >> category;

            if (category == "fruit") {
                wordToGuess = chooseRandomWord(word_fruit, 10);
            } else if (category == "animal") {
                wordToGuess = chooseRandomWord(word_animal, 10);
            } else if (category == "vehicle") {
                wordToGuess = chooseRandomWord(word_vehicle, 10);
            } else if (category == "movie") {
                wordToGuess = chooseRandomWord(word_movie, 10);
            } else if (category == "planet") {
                wordToGuess = chooseRandomWord(word_planet, 10);
            } else if (category == "country") {
                wordToGuess = chooseRandomWord(word_country, 10);
            }

        } else if (game_level == "medium") {
            
            wordToGuess = chooseRandomWordFromVector(dynamic_words);
        } else if (game_level == "hard") {
            
            vector<string> hard_words = loadWordsFromFile("hard_words.txt");
            wordToGuess = chooseRandomWordFromVector(hard_words);
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

            char guess = getValidatedInput();

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

            if (attempts == maxAttempts - 1 && game_level != "hard") {
                cout << "Would you like a hint? (y/n): ";
                char hintOption;
                cin >> hintOption;
                if (hintOption == 'y' || hintOption == 'Y') {
                    cout << "Hint: The word starts with " << provideHint(wordToGuess) << endl;
                }
            }

            bool wordGuessed = true;
            for (int i = 0; i < wordLength; i++) {
                if (!guessed[i]) {
                    wordGuessed = false;
                    break;
                }
            }

            if (wordGuessed) {
                cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
                score++;
                break;
            }
        }

        if (attempts == maxAttempts) {
            cout << "Game over! The word was: " << wordToGuess << endl;
        }

        cout << "Your score: " << score << endl;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}