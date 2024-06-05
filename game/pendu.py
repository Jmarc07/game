def display_current_state(word, guessed_word):
    print("Current word:", " ".join(guessed_word))

def is_word_guessed(word, guessed_word):
    return word == "".join(guessed_word)

def update_guessed_word(word, guessed_word, guess):
    for i, letter in enumerate(word):
        if letter == guess:
            guessed_word[i] = guess

def get_guess():
    guess = input("Enter a letter: ").lower()
    return guess

def main():
    word = "programming"
    guessed_word = ['_' for _ in word]
    attempts = 6
    
    while attempts > 0 and not is_word_guessed(word, guessed_word):
        display_current_state(word, guessed_word)
        guess = get_guess()

        if guess in word:
            update_guessed_word(word, guessed_word, guess)
        else:
            attempts -= 1
            print(f"Wrong guess! Attempts left: {attempts}")

    if is_word_guessed(word, guessed_word):
        print(f"Congratulations! You've guessed the word: {word}")
    else:
        print(f"You've run out of attempts! The word was: {word}")

if __name__ == "__main__":
    main()
