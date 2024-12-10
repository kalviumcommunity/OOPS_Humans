#include <iostream>
#include <string>
using namespace std;

// Class 1: Emotion
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
        totalEmotions++; // Increment the static variable
        cout << "Emotion object created with default constructor." << endl;
    }

    // Parameterized constructor
    Emotion(string name, string intensity) {
        this->name = name;
        this->intensity = intensity;
        totalEmotions++; // Increment the static variable
        cout << "Emotion object created with parameterized constructor." << endl;
    }

    // Destructor
    ~Emotion() {
        totalEmotions--; // Decrement the static variable
        cout << "Emotion object destroyed." << endl;
    }

    // Accessor (Getter) for name
    string getName() {
        return name;
    }

    // Mutator (Setter) for name
    void setName(string newName) {
        name = newName;
    }

    // Accessor (Getter) for intensity
    string getIntensity() {
        return intensity;
    }

    // Mutator (Setter) for intensity
    void setIntensity(string newIntensity) {
        intensity = newIntensity;
    }

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

// Class 2: Person
class Person {
private:
    string name;   // Name of the person
    int age;       // Age of the person

    // Static variable to track the total number of Person objects
    static int totalPeople;

public:
    // Default constructor
    Person() {
        name = "Unknown";
        age = 0;
        totalPeople++; // Increment the static variable
        cout << "Person object created with default constructor." << endl;
    }

    // Parameterized constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
        totalPeople++; // Increment the static variable
        cout << "Person object created with parameterized constructor." << endl;
    }

    // Destructor
    ~Person() {
        totalPeople--; // Decrement the static variable
        cout << "Person object destroyed." << endl;
    }

    // Accessor (Getter) for name
    string getName() {
        return name;
    }

    // Mutator (Setter) for name
    void setName(string newName) {
        name = newName;
    }

    // Accessor (Getter) for age
    int getAge() {
        return age;
    }

    // Mutator (Setter) for age
    void setAge(int newAge) {
        if (newAge > 0) { // Validation: Age must be positive
            age = newAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    // Member function to introduce the person
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

    // Static function to get the total number of Person objects created
    static int getTotalPeople() {
        return totalPeople;
    }
};

// Initialize the static variable
int Person::totalPeople = 0;

int main() {
    // Demonstrating default constructors
    Emotion defaultEmotion;
    Person defaultPerson;

    // Using parameterized constructors
    Emotion happiness("Happiness", "High");
    Emotion sadness("Sadness", "Low");
    Person alice("Alice", 25);
    Person bob("Bob", 30);

    // Modify default objects using mutators
    defaultEmotion.setName("Curiosity");
    defaultEmotion.setIntensity("Moderate");
    defaultPerson.setName("John Doe");
    defaultPerson.setAge(40);

    // Display emotions
    cout << "\nDisplaying emotions:" << endl;
    defaultEmotion.describe();
    happiness.describe();
    sadness.describe();

    // Display total number of emotions
    cout << "\nTotal emotions created: " << Emotion::getTotalEmotions() << endl;

    // Introduce people
    cout << "\nIntroducing people:" << endl;
    defaultPerson.introduce();
    alice.introduce();
    bob.introduce();

    // Display total number of people
    cout << "\nTotal people created: " << Person::getTotalPeople() << endl;

    // Objects go out of scope here, and destructors are called automatically
    return 0;
}

