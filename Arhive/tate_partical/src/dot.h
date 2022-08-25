//
//  dot.h
//  tatetest
//
//  Created by waihin_chan on 2020/2/26.
//

#ifndef dot_h
#define dot_h
#include "ofMain.h"

class dot{
public:
    float x;//collect from pixel x
    float y;//collect from pixel y
    float rad;
    int r;
    int b;
    int g;
    int alpha;
    bool starttocount;
    float scale;
    void setup(float _x,float _y,float _radius,int _r, int _g, int _b, int _a);
    void draw();
    void fade(float duration);
    void timecounter();
    void ripple(float amplitude);//这里到底返回了一个啥float还是int
    void checkchange();
};























#endif /* dot_h */
