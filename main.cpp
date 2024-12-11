#include <iostream>
#include <string>
using namespace std;

// Class 1: Emotion (Base Class)
class Emotion {
private:
    string name;         // Name of the emotion (e.g., Happiness, Sadness)
    string intensity;    // Intensity level of the emotion (e.g., High, Low)

    // Static variable to track the total number of Emotion objects
    static int totalEmotions;

public:
    // Default constructor
    Emotion() {
        name = "Unknown";
        intensity = "Neutral";
        totalEmotions++;
        cout << "Emotion object created with default constructor." << endl;
    }

    // Parameterized constructor
    Emotion(string name, string intensity) {
        this->name = name;
        this->intensity = intensity;
        totalEmotions++;
        cout << "Emotion object created with parameterized constructor." << endl;
    }

    // Destructor
    ~Emotion() {
        totalEmotions--;
        cout << "Emotion object destroyed." << endl;
    }

    // Accessor and mutator for name
    string getName() { return name; }
    void setName(string newName) { name = newName; }

    // Accessor and mutator for intensity
    string getIntensity() { return intensity; }
    void setIntensity(string newIntensity) { intensity = newIntensity; }

    // Member function to describe the emotion
    void describe() {
        cout << "Emotion: " << name << ", Intensity: " << intensity << endl;
    }

    // Static function to get the total number of Emotion objects created
    static int getTotalEmotions() {
        return totalEmotions;
    }
};

// Initialize the static variable
int Emotion::totalEmotions = 0;

// Derived Class (Single Inheritance): HappyEmotion inherits Emotion
class HappyEmotion : public Emotion {
private:
    string causeOfHappiness; // Additional property specific to HappyEmotion

public:
    // Constructor
    HappyEmotion(string name, string intensity, string cause) : Emotion(name, intensity) {
        causeOfHappiness = cause;
        cout << "HappyEmotion object created." << endl;
    }

    // Destructor
    ~HappyEmotion() {
        cout << "HappyEmotion object destroyed." << endl;
    }

    // Member function to describe happiness specifically
    void describeHappiness() {
        cout << "Happiness caused by: " << causeOfHappiness << endl;
    }
};

// Class 2: Person (Base Class)
class Person {
private:
    string name; // Name of the person
    int age;     // Age of the person

    // Static variable to track the total number of Person objects
    static int totalPeople;

public:
    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
        totalPeople++;
        cout << "Person object created with default constructor." << endl;
    }

    // Parameterized constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
        totalPeople++;
        cout << "Person object created with parameterized constructor." << endl;
    }

    // Destructor
    ~Person() {
        totalPeople--;
        cout << "Person object destroyed." << endl;
    }

    // Accessor and mutator for name
    string getName() { return name; }
    void setName(string newName) { name = newName; }

    // Accessor and mutator for age
    int getAge() { return age; }
    void setAge(int newAge) {
        if (newAge > 0)
            age = newAge;
        else
            cout << "Invalid age!" << endl;
    }

    // Member function to introduce the person
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

    // Static function to get the total number of people
    static int getTotalPeople() {
        return totalPeople;
    }
};

// Initialize the static variable
int Person::totalPeople = 0;

// Derived Class (Composition): SpecialPerson combines Person and Emotion
class SpecialPerson : public Person {
private:
    Emotion emotion; // Composition: Every SpecialPerson has an associated Emotion

public:
    // Parameterized constructor
    SpecialPerson(string name, int age, Emotion emotion) : Person(name, age), emotion(emotion) {
        cout << "SpecialPerson object created." << endl;
    }

    // Destructor
    ~SpecialPerson() {
        cout << "SpecialPerson object destroyed." << endl;
    }

    // Member function to describe the SpecialPerson's emotion
    void expressEmotion() {
        cout << "SpecialPerson " << getName() << " is feeling: ";
        emotion.describe();
    }
};

int main() {
    // Demonstrating Single Inheritance with HappyEmotion
    HappyEmotion happiness("Happiness", "High", "Achieving goals");
    happiness.describe();
    happiness.describeHappiness();

    // Demonstrating Multiple Inheritance using Composition
    Emotion sadness("Sadness", "Low");
    SpecialPerson alice("Alice", 25, sadness);

    alice.introduce();
    alice.expressEmotion();

    // Display total objects
    cout << "\nTotal emotions created: " << Emotion::getTotalEmotions() << endl;
    cout << "Total people created: " << Person::getTotalPeople() << endl;

    // Objects go out of scope, and destructors will be called automatically
    return 0;
}

