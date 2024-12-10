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
    Emotion(string name, string intensity) {
        // Using `this` to access the current object's name and intensity
        this->name = name;
        this->intensity = intensity;
    }

    // Member function to describe the emotion
    void describe() {
        // Using `this` to access the current object's attributes
        cout << "Emotion: " << this->name << ", Intensity: " << this->intensity << endl;
    }

    // Member function to modify the emotion's intensity
    void changeIntensity(string newIntensity) {
        // Using `this` to modify the current object's intensity
        this->intensity = newIntensity;
        cout << "Changed " << this->name << " intensity to " << this->intensity << endl;
    }
};

// Class 2: Person
class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) {
        // Using `this` to access the current object's name and age
        this->name = name;
        this->age = age;
    }

    // Member function to introduce the person
    void introduce() {
        // Using `this` to refer to the current object (Person)
        cout << "Hello, my name is " << this->name << " and I am " << this->age << " years old." << endl;
    }

    // Member function to express an emotion
    void expressEmotion(Emotion emotion) {
        // Using `this` to refer to the current object (Person) when expressing emotion
        cout << this->name << " is feeling ";
        emotion.describe();
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
    Person alice("Alice", 25);
    Person bob("Bob", 30);

    // Call member functions of Person
    alice.introduce();
    bob.introduce();

    // Express emotions
    alice.expressEmotion(happiness);
    bob.expressEmotion(sadness);

    return 0;
}

