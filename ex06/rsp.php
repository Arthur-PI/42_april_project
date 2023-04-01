<?php

$choices = array('rock', 'paper', 'scissors');
$user_choice = '';
$computer_choice = $choices[array_rand($choices)];

// Display instructions
echo "Rock Paper Scissors\n";
echo "-------------------\n";
echo "Choose rock, paper, or scissors by typing r, p, or s.\n\n";

// Get user input
while (!in_array($user_choice, $choices)) {
    $input = strtolower(trim(readline('> ')));
    if ($input == 'r') {
        $user_choice = 'rock';
    } elseif ($input == 'p') {
        $user_choice = 'paper';
    } elseif ($input == 's') {
        $user_choice = 'scissors';
    } else {
        echo "Invalid input. Please try again.\n";
    }
}

// Display choices
echo "\nYou chose $user_choice.\n";
echo "The computer chose $computer_choice.\n\n";

// Determine winner
if ($user_choice == $computer_choice) {
    echo "It's a tie!\n";
} elseif ($user_choice == 'rock' && $computer_choice == 'scissors' ||
          $user_choice == 'paper' && $computer_choice == 'rock' ||
          $user_choice == 'scissors' && $computer_choice == 'paper') {
    echo "You win!\n";
} else {
    echo "The computer wins!\n";
}
