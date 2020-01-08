/*
 
 Chapter 2 Part 5 Task:
 User-Defined Types
 
 1) write 10 user-defined types, each with a random number of member variables
    try to make the member variables have names that are related to the user-defined type.
 
 2) give the member variables relevant data types
 
 3) add a couple member functions.  
    make the function parameter list for those member functions use some of your User-Defined Types
 
 4) make 2 of the 10 user-defined types be nested class
 
 5) One of your UDTs should only use UDTs for its member variable types.   
     No primitives allowed!
 
 6) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */

/*
 example:
 */
struct CarWash            //1) a U.D.T. with a random number of member variables
{
    int numSponges = 3;
    double amountOfSoapUsedPerCar = 2.6; //2) relevant data types
    unsigned int numCarsProcessed = 0;
    
    struct Car                             //4) nested class
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        //2) relevant data types
    };
    
    void washAndWaxCar( Car car );         //3) member function with a user-defined type as the parameter.  The user-defined type parameter happens to be the nested class.
    
    Car myCar;  //5) a member variable whose type is a UDT.
};

/*
 1)
 */
struct Kitchen
{
    unsigned int numberChefs = 1;
    unsigned int numberOfAssistants = 3;
    unsigned int numberOfStudents = 25;

    struct Chef 
    {
        bool isCooking = true;
        bool isTeaching = true;
        char codeName = 'C';
    };

    struct Recipe
    {
        bool completed = false;
        unsigned int currentStep = 0;
        bool requiresAssitant = true;
        char recipeID = 'A';
        float difficultyRating = 5.0f;
        Chef creator;
    };

    void startCookingClass (Chef chef, Recipe recipe);

    Recipe currentRecipe;
    Chef masterChef;
};

/*
 2)
 */
struct KioskLocator
{
    bool isOpen = true;
    float distance = 0.0f;
    int starRating = 5;
    char name = 'k';
    
    struct Kiosk 
    {
        float distance = 20.0f;
        char name = 'Z';
    };

    struct KList 
    {
        int initSize = 3;
        char prefix = 'K';
        Kiosk k;

        Kiosk getClosestKiosk();
    };

    Kiosk closestKiosk;

    void refreshList (KList k, int initSize);
    void getClosestKiosk (KList klist);
};

/*
 3)
 */
struct ADSR 
{
    bool isRunning = false;
    char timeScale = 'M';
    double duration = 1.0;
    
    struct Stage 
    { 
        char stage = 'A';
        double stageDur = 0.5;
    };

    Stage currentStage (ADSR env1);
};

/*
 4)
 */
struct Form 
{
    bool isVisible = true;
    char formID = 'f';
    int fields = 4;
    
    struct TextField 
    { 
        float x,y,w,h;
        int alpha = 32;
        char fieldID = 'a';
        bool hasCheckBox = true;
    };

    struct CheckBox
    {
        float size = 16.0f;
        char icon = '#';
        bool isChecked = false;

        void animateCheckBox (char fieldID, CheckBox c);
    };

    CheckBox checkBox;
    TextField fullName;

    bool mouseOver (TextField fullName);
    bool formIsVisible (char formID);
    void clearAllCheckBoxes (Form f);
};

/*
 5)
 */
struct PresetLibrary 
{
    char bank = 'A';
    int presetNumber = 1;
    char presetName;
    bool hasBeenEdited = false;
    float seed = 0.001f;

    struct PresetName 
    {
        char c;
        int numberOfChars;
        
        struct RandomName 
        {
            int keyX, keyY;
            
            char getCharAt (int keyX, int keyY);
        };

        RandomName rn;
    };

    PresetName generateRandomName (char bank, int presetNumber, float seed);
    bool updatePresets();
    PresetLibrary dumpBank (char bank);
};

/*
 6)
 */
struct FunkyBufferPlayer 
{
    int bufferID = 1;
    double defaultBufferSize = 60 * 5;
    int numberOfBuffers = 4;
    int loopCounter = 0;

    struct Buffer 
    {
        double sizeInSamples;
        double getSizeInSamples (int bufferID);
        
        struct SecondaryBuffer
        {
            int bufferID;
            bool isReversed = true;
            int loopCounter = 0;

            void reverse (int bufferID);
        };

        bool clearBuffer (int bufferID);
        bool copyToSecondaryBuffer (SecondaryBuffer bufferID);
    };
};

/*
 7)
 */
struct FlyingFaderBank
{
    int numberOfFaders = 3;

    struct Fader 
    {
        int id;
        bool physics = true;
        float friction, accel, velocity = 0.5f;

        void update (int id, float friction, float accel, float velocity);
        float getValue (int id);
    };

    Fader fader1, fader2, fader3;

    void updateFaders (int numberOfFaders);
};

/*
 8)
 */
struct ScaleGenerator
{
    char scaleName = 'a';
    int octaves = 8;
    double stepSize = 1.618;
    
    struct Scale 
    {
        Scale generateScaleForOctaves (int octaves, double stepSize);
    };

    Scale goldenRatio;
};

/*
 9)
 */
struct Meter
{
    int meterID = 1;
    bool peakHold = true;
    char colourPallette = 'a';
    float slewRise, slewFall = 0.1f;

    struct VerticalMeter 
    {   
        int w,h,x,y;
        float scaleFactor = 0.5f;
        int numberOfSegments = 256;

        struct Segment
        {
            int segmentIndex;
            float opacity;
            bool activeStatus;

            void destroy();
            void draw (int segmentIndex);
        };


        void updateSegment (int meterID, Segment s);
    };
};

/*
 10)
 */
struct StepSequencer
{
    bool isPlaying = true;
    int numberOfSteps = 8;
    double tempo = 120;
    unsigned int id = 1;
	
    struct StepData
    {
        struct PitchClass 
        {
            double frequency;
            double pitch;

            double calculatePitchFromFreq (double frequency );
        };

        PitchClass p;
        bool gateStatus = true;       
        double duration = 1.0;
    };

    int getCurrentStage (unsigned int id );
    void stepSequence (unsigned int id, bool isPlaying );
    
    StepData stepData;
    StepData getCurrentStepData();
};


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
