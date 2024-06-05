import random

def get_computer_choice():
    return random.choice(['R', 'P', 'S'])

def get_user_choice():
    user_choice = input("Enter R for Rock, P for Paper, or S for Scissors: ").upper()
    return user_choice

def determine_winner(user_choice, computer_choice):
    choices = {'R': "Rock", 'P': "Paper", 'S': "Scissors"}
    print(f"You chose: {choices[user_choice]}")
    print(f"Computer chose: {choices[computer_choice]}")

    if user_choice == computer_choice:
        print("It's a tie!")
    elif (user_choice == 'R' and computer_choice == 'S') or \
         (user_choice == 'P' and computer_choice == 'R') or \
         (user_choice == 'S' and computer_choice == 'P'):
        print("You win!")
    else:
        print("You lose!")

def main():
    computer_choice = get_computer_choice()
    user_choice = get_user_choice()
    determine_winner(user_choice, computer_choice)

if __name__ == "__main__":
    main()
