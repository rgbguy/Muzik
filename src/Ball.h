//
//  Ball.h
//  Muzik
//
//  Created by Sagar Kalbande on 01/09/21.
//

#ifndef Ball_h
#define Ball_h


#endif /* Ball_h */

class Ball
{
public:
    glm::vec2 position;
    glm::vec2 velocity;
    
    Ball(float x, float y)
    {
        position = glm::vec2(x,y);
        SetVelocity();
    }
    void Update()
    {
        if(position.x > ofGetWidth() || position.x < 0) velocity.x = - velocity.x;
        if(position.y > ofGetWidth() || position.y < 0) velocity.y = - velocity.y;

        position += velocity;
    }
    void SetVelocity()
    {
        velocity = glm::vec2(ofRandom(-1,1), ofRandom(-1,1));
    }
    
};
