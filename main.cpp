#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Class: BaseEmotion
class BaseEmotion {
public:
    // Pure virtual function for custom behavior
    virtual void customBehavior() = 0;

    // Pure virtual function for describing the emotion
    virtual void describe() const = 0;

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~BaseEmotion() {}
};

// Class 1: Emotion (Base class implementing BaseEmotion)
class Emotion : public BaseEmotion {
protected:
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

    // Override describe method
    void describe() const override {
        cout << "Emotion: " << name << ", Intensity: " << intensity << endl;
    }

    // Static function to get the total number of emotions created
    static int getTotalEmotions() {
        return totalEmotions;
    }

    // Overriding customBehavior from BaseEmotion
    void customBehavior() override {
        cout << "Generic Emotion Behavior: " << name << " at " << intensity << " intensity." << endl;
    }
};

// Initialize the static variable
int Emotion::totalEmotions = 0;

// Class 2: PositiveEmotion (derived from Emotion)
class PositiveEmotion : public Emotion {
private:
    string positivityMessage;

public:
    // Constructor
    PositiveEmotion(string name, string intensity, string positivityMessage)
        : Emotion(name, intensity), positivityMessage(positivityMessage) {}

    // Override describe
    void describe() const override {
        cout << "Positive Emotion: " << name << ", Intensity: " << intensity
             << ". Message: " << positivityMessage << endl;
    }

    // Overriding customBehavior
    void customBehavior() override {
        cout << "Expressing positivity through " << name << " with intensity " << intensity << endl;
    }
};

// Class 3: NegativeEmotion (derived from Emotion)
class NegativeEmotion : public Emotion {
private:
    string negativityCause;

public:
    // Constructor
    NegativeEmotion(string name, string intensity, string negativityCause)
        : Emotion(name, intensity), negativityCause(negativityCause) {}

    // Override describe
    void describe() const override {
        cout << "Negative Emotion: " << name << ", Intensity: " << intensity
             << ". Cause: " << negativityCause << endl;
    }

    // Overriding customBehavior
    void customBehavior() override {
        cout << "Dealing with negativity caused by " << negativityCause << " through " << name << endl;
    }
};

// Class 4: Person
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
    void expressEmotion(const BaseEmotion& emotion) const {
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

// Class 5: EmotionManager (SRP: Manages all emotions)
class EmotionManager {
private:
    vector<BaseEmotion*> emotions; // Store dynamic BaseEmotion objects

public:
    // Add a new emotion
    void addEmotion(BaseEmotion* emotion) {
        emotions.push_back(emotion);
    }

    // Display all emotions
    void displayAllEmotions() const {
        cout << "Emotions:" << endl;
        for (const auto& emotion : emotions) {
            emotion->describe();
        }
    }

    // Destructor to clean up memory
    ~EmotionManager() {
        for (auto& emotion : emotions) {
            delete emotion;
        }
    }
};

// Main Function
int main() {
    // Using EmotionManager to handle all emotions (SRP + OCP)
    EmotionManager emotionManager;

    // Create dynamic Emotion objects
    BaseEmotion* happiness = new PositiveEmotion("Happiness", "High", "Spread Joy");
    BaseEmotion* sadness = new NegativeEmotion("Sadness", "Low", "Lost Opportunities");

    // Add emotions to the manager
    emotionManager.addEmotion(happiness);
    emotionManager.addEmotion(sadness);

    // Display all emotions
    emotionManager.displayAllEmotions();

    // Show total emotions
    cout << "Total emotions created: " << Emotion::getTotalEmotions() << endl;

    // Create dynamic Person objects
    Person* person1 = new Person("Alice", 25);
    Person* person2 = new Person("Bob", 30);

    // Introduce people and express emotions
    person1->introduce();
    person1->expressEmotion(*happiness);

    person2->introduce();
    person2->expressEmotion(*sadness);

    // Show total people
    cout << "Total people created: " << Person::getTotalPeople() << endl;

    // Clean up memory
    delete person1;
    delete person2;

    return 0;
}

