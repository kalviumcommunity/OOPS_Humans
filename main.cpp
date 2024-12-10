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
        this->name = name;
        this->intensity = intensity;
    }

    // Member function to describe the emotion
    void describe() {
        cout << "Emotion: " << this->name << ", Intensity: " << this->intensity << endl;
    }

    // Member function to modify the emotion's intensity
    void changeIntensity(string newIntensity) {
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
        this->name = name;
        this->age = age;
    }

    // Member function to introduce the person
    void introduce() {
        cout << "Hello, my name is " << this->name << " and I am " << this->age << " years old." << endl;
    }

    // Member function to express an emotion
    void expressEmotion(Emotion* emotion) {
        cout << this->name << " is feeling ";
        emotion->describe();  // Access the describe method using pointer (dynamic memory allocation)
    }
};

int main() {
    // Dynamically create an array of Emotion objects
    Emotion* emotions[3];
    emotions[0] = new Emotion("Happiness", "High");
    emotions[1] = new Emotion("Sadness", "Low");
    emotions[2] = new Emotion("Anger", "Moderate");

    // Call member functions of Emotion using the array
    for (int i = 0; i < 3; i++) {
        emotions[i]->describe();
    }

    // Change intensity of an emotion in the array
    emotions[1]->changeIntensity("High");

    // Dynamically create an array of Person objects
    Person* people[2];
    people[0] = new Person("Alice", 25);
    people[1] = new Person("Bob", 30);

    // Call member functions of Person using the array
    for (int i = 0; i < 2; i++) {
        people[i]->introduce();
    }

    // Express emotions using the array of objects
    people[0]->expressEmotion(emotions[0]); // Alice feels Happiness
    people[1]->expressEmotion(emotions[1]); // Bob feels Sadness

    // Delete dynamically allocated Emotion objects
    for (int i = 0; i < 3; i++) {
        delete emotions[i];
    }

    // Delete dynamically allocated Person objects
    for (int i = 0; i < 2; i++) {
        delete people[i];
    }

    return 0;
}

