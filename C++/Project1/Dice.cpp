#include <iostream>
#include <random>

using namespace std;

int roll_dice(int num_dice, mt19937 &rng) {
    uniform_int_distribution<int> dist(1, 6); //ensures each die gives a random value between 1 and 6.
    int sum = 0;
    for (int i = 0; i < num_dice; ++i) {
        sum += dist(rng);
    }
    return sum;
}

int main() {
    const int num_dice = 10; // Number of dice to roll is 10.
    int desired_sum; // Desired sum of outputs to check against.
    int num_trials; // How many times to simulate rolling the 10 dice

    cout << "Enter desired sum (10 to 60): ";
    cin >> desired_sum;
    cout << "Enter number of trials: ";
    cin >> num_trials;

    int count = 0; //Sets up a counter to check how many times the desired sum appears.
    random_device randomNumber; // Random device to seed the random number generator(like a variable that holds the random number).
    mt19937 rng(randomNumber()); // random number generator.

    for (int i = 0; i < num_trials; ++i) {
        if (roll_dice(num_dice, rng) == desired_sum) { // if the rolled sum equals the desired sum the count is incresed by 1.
            ++count;
        }
    }

    double probability = static_cast<double>(count) / num_trials;
    cout << "Number of times " << desired_sum << " was rolled: " << count << "\n";
    cout << "Probability of rolling " << desired_sum << ": " << probability << "\n";

    return 0;
}