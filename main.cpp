#include <iostream>
#include <string>
using namespace std;

// Abstract Class: BaseEmotion
class BaseEmotion {
public:
    // Pure virtual function for custom behavior
    virtual void customBehavior() = 0;

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~BaseEmotion() {}
};

// Class 1: Emotion (derived from BaseEmotion)
class Emotion : public BaseEmotion {
private:
    string name;
    string intensity;

    // Static variable to track the total number of Emotion objects
    static int totalEmotions;

public:
    // Default constructor
    Emotion() : name("Unknown"), intensity("Unknown") { totalEmotions++; }

    // Parameterized constructor
    Emotion(string name, string intensity) : name(name), intensity(intensity) { totalEmotions++; }

    // Destructor
    ~Emotion() {
        totalEmotions--; // Decrement static count when an Emotion object is destroyed
    }

    // Accessor and Mutator for name
    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    // Accessor and Mutator for intensity
    string getIntensity() const { return intensity; }
    void setIntensity(string intensity) { this->intensity = intensity; }

    // Member function to describe the emotion
    void describe() const {
        cout << "Emotion: " << name << ", Intensity: " << intensity << endl;
    }

    // Static function to get the total number of emotions created
    static int getTotalEmotions() {
        return totalEmotions;
    }

    // Overriding customBehavior from BaseEmotion
    void customBehavior() override {
        cout << "Custom behavior of " << name << ": Expressing at " << intensity << " intensity." << endl;
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
    // Default constructor
    Person() : name("Unknown"), age(0) { totalPeople++; }

    // Parameterized constructor
    Person(string name, int age) : name(name), age(age) { totalPeople++; }

    // Destructor
    ~Person() {
        totalPeople--; // Decrement static count when a Person object is destroyed
    }

    // Accessor and Mutator for name
    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    // Accessor and Mutator for age
    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    // Member function to introduce the person
    void introduce() const {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }

    // Member function to express an emotion
    void expressEmotion(const Emotion& emotion) const {
        cout << name << " is feeling ";
        emotion.describe();
    }

    // Static function to get the total number of people created
    static int getTotalPeople() {
        return totalPeople;
    }
};

// Initialize the static variable
int Person::totalPeople = 0;

// Main Function
int main() {
    // Using dynamic memory allocation
    Emotion* emotions[2];
    emotions[0] = new Emotion("Happiness", "High");
    emotions[1] = new Emotion("Sadness", "Low");

    // Using polymorphism with the BaseEmotion class
    BaseEmotion* baseEmotion = emotions[0];
    baseEmotion->customBehavior();

    // Display all emotions
    for (int i = 0; i < 2; i++) {
        emotions[i]->describe();
    }

    // Display total emotions
    cout << "Total emotions created: " << Emotion::getTotalEmotions() << endl;

    // Dynamic allocation for Person objects
    Person* person1 = new Person("Alice", 25);
    Person* person2 = new Person("Bob", 30);

    // Introduce people and express emotions
    person1->introduce();
    person1->expressEmotion(*emotions[0]);

    person2->introduce();
    person2->expressEmotion(*emotions[1]);

    // Display total people
    cout << "Total people created: " << Person::getTotalPeople() << endl;

    // Clean up memory
    delete emotions[0];
    delete emotions[1];
    delete person1;
    delete person2;

    // Final count after destruction
    cout << "Final total emotions: " << Emotion::getTotalEmotions() << endl;
    cout << "Final total people: " << Person::getTotalPeople() << endl;

    return 0;
}

