//
//  Platform.hpp
//  BunnyJump
//
//  Created by Antoni Remeseiro on 2/20/17.
//
//

#ifndef Platform_hpp
#define Platform_hpp

#include "cocos2d.h"
#include "Constants.h"

using namespace cocos2d;

// Type references the graphics if its grass or metal or what.
enum class type: char
{
    cake='c',
    grass='g',
    stone='m',
    sand='S',
    snow='s', // C++11 allows the extra comma
    wood='w',
};

//Two sizes only. big or small.
enum class size: char
    {
        small='b',
        normal='s',
    };
//Normal or broken its for graphics but also broken will fall down once you jamp ut of it or on it
enum class state: char
    {
        normal='n',
        broken='b',
    };

class Platform : public cocos2d::Sprite
{
public:
    //Variables
    //Boolean to know if the platform contains traps or enemies in which case do not add bonuses , coins or other stuff
    bool containsTraps = false;
    
    //Setters
    //Setter for type
    void setType(type t) {
        _type = t;
    }
    
    //Setter for size
    void setSize(size s) {
        _size = s;
    }
    
    //Setter for state
    void setState(state st) {
        _state = st;
    }
    
    //Methods
    Platform();
    ~Platform();
    
    //Create method with options to setup our object
    static Platform* create(type t,size s,state st);
    
    //Init with settag, physics body , etc
    void initOptions();

    //Add decorations to ths platform if suitable
    void AddDecorations();
    
    //Iv platform is broen on steping will break and fall down
    void PlatformBroke();
    
    //This will add Spikes to the platform
    void AddSpikes();
    
    //This will add an enemy to the platform (this enemy will walk on top of the platform)
    void AddWalkingEnemy();
    
    //This will add a sprint to the platform
    void AddSpring();

    //This will destroy the platform and delete it from the scene
    void DestroyPlatform();
    
    //Returns the state of the platform
    state getState();
    
    //Asks the latform if its a broken platform or not if it is after this jump will get destroyed
    bool isBroken();
    
    
private:
    //Variables
    type _type;
    size _size;
    state _state;
    
    //Methods
    
};


#endif /* Platform_hpp */
