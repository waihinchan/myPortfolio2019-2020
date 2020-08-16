//
//  dot.cpp
//  tatetest
//
//  Created by waihin_chan on 2020/2/26.
//

#include <stdio.h>
#include "dot.h"
void dot::setup(float _x,float _y,float _radius,int _r, int _g, int _b,int _a){
    x = _x;
    y = _y;
    rad = _radius;
    r = _r;
    g = _g;
    b = _b;
    alpha = _a;
    scale = 0;
    
}
void dot::draw(){//这个应该是可以一直draw的
    
//    ofNoFill();
//    ofSetLineWidth(3);
    ofSetColor(r, g, b,alpha);
    ofDrawCircle(x, y, rad);
        
    

}
void dot::fade(float amplitude){
    rad -= 1*amplitude;
    if(rad<=0){
        rad = 5;
    }
}
void dot::ripple(float amplitude){//这个数，可能需要存一下，每一个都不同，到时候看怎么传递进来的
    //这里需要一个映射
    rad+=scale*amplitude;
    alpha-=scale*5;
    if(rad>50){
        rad = 15.0;
        scale = 0;
    }
    if(alpha<=0){alpha = 150;}
}
void dot::checkchange(){
    if(abs((ofGetMouseX()-x))<50& abs(ofGetMouseY()-y)<50){
        scale = 2.0;//这里留一个变量？
//        alpha = 0;
    }
}
