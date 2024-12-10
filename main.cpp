#include <iostream>
#include <string>
using namespace std;

// Class 1: Emotion
class Emotion {
private:
    string name;
    string intensity;

    // Static variable to track the total number of Emotion objects
    static int totalEmotions;

public:
    // Member function to set emotion details
    void setEmotion(string name, string intensity) {
        this->name = name;
        this->intensity = intensity;
        totalEmotions++; // Increment the static variable
    }

    // Member function to describe the emotion
    void describe() {
        cout << "Emotion: " << name << ", Intensity: " << intensity << endl;
    }

    // Static function to get the total number of emotions created
    static int getTotalEmotions() {
        return totalEmotions;
    }
};

// Initialize the static variable
int Emotion::totalEmotions = 0;

// Class 2: Person
class Person {
private:
    string name;
    int age;

    // Static variable to track the total number of Person objects
    static int totalPeople;

public:
    // Member function to set person details
    void setPerson(string name, int age) {
        this->name = name;
        this->age = age;
        totalPeople++; // Increment the static variable
    }

    // Member function to introduce the person
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

    // Static function to get the total number of people created
    static int getTotalPeople() {
        return totalPeople;
    }
};

// Initialize the static variable
int Person::totalPeople = 0;

int main() {
    // Create an array of Emotion objects
    Emotion emotions[3];
    emotions[0].setEmotion("Happiness", "High");
    emotions[1].setEmotion("Sadness", "Low");
    emotions[2].setEmotion("Anger", "Moderate");

    // Display emotions
    for (int i = 0; i < 3; i++) {
        emotions[i].describe();
    }

    // Display total number of emotions
    cout << "Total emotions created: " << Emotion::getTotalEmotions() << endl;

    // Create an array of Person objects
    Person people[2];
    people[0].setPerson("Alice", 25);
    people[1].setPerson("Bob", 30);

    // Introduce people
    for (int i = 0; i < 2; i++) {
        people[i].introduce();
    }

    // Display total number of people
    cout << "Total people created: " << Person::getTotalPeople() << endl;

    return 0;
}

