#include <iostream>
#include <string>
using namespace std;

// Class 1: Emotion
class Emotion {
private:
    string name;
    string intensity;

public:
    // Constructor
    Emotion(string name, string intensity) : name(name), intensity(intensity) {}

    // Member function to describe the emotion
    void describe() {
        cout << "Emotion: " << name << ", Intensity: " << intensity << endl;
    }

    // Member function to modify the emotion's intensity
    void changeIntensity(string newIntensity) {
        intensity = newIntensity;
        cout << "Changed " << name << " intensity to " << intensity << endl;
    }
};

// Class 2: Person
class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) : name(name), age(age) {}

    // Member function to introduce the person
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

    // Member function to express an emotion
    void expressEmotion(Emotion emotion) {
        cout << name << " is feeling ";
        emotion.describe(); // Call the describe method of the Emotion object
    }
};

int main() {
    // Instantiate Emotion objects
    Emotion happiness("Happiness", "High");
    Emotion sadness("Sadness", "Low");

    // Call member functions of Emotion
    happiness.describe();
    sadness.describe();
    sadness.changeIntensity("Moderate");

    // Instantiate Person objects
    Person nitin("Nitin", 19);
    Person dhruv("Dhruv", 55);

    // Call member functions of Person
    nitin.introduce();
    dhruv.introduce();

    // Express emotions
    nitin.expressEmotion(happiness);
    dhruv.expressEmotion(sadness);

    return 0;
}

