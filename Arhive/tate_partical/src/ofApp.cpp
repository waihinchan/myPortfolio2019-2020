//这里是思路：
//我们大概是有一个pitch 一个duration
//normal 状态下 现阶段是会随机地找一些点进行ripple效果
//pitch 对应的是位置 我目前用的是鼠标
//思路基本上就是 横坐标和纵坐标
//这里有一个是我们需要键位对应的pitch，因为它是有横坐标和纵坐标的，所以我建议是12345对应第一行，678910对应d第二行，以此类推
//因为键位映射肯定没有鼠标对应的这么多的，至于触发的范围可以后面调节，这个对应的函数是checkchange
//这里为了统一效果统一200毫秒所有的图形会更新一次
//至于不同的更新速度，也就是每次半径扩散的范围则base在duration或者是amplitude？这两者我建议选一个就可以
//考虑到性能因素和时间，做简单一点完事了
//注意这里每一个圆形对应的alpha和扩散的半径都是独立的，所以push进来的amplitude也是需要独立的
//比如一个范围内的，是由一个键统一控制的
//当然我们可以把触发范围设置成duration，这样我们按的久一点的话，触发范围会变得很大（要设置一个max数值）




#include "ofApp.h"
#include "dot.h"
//#include <math.h>
int imgw;
int imgh;
int samplelength;
int scl = 5; //remain to use maybe no use
std::vector<int> sample;//sampling dots dynamic array
int timecontrol = 0;
std::vector<dot> dots;
int lastupdate = 0;
//--------------------------------------------------------------
void ofApp::setup(){
//    ofEnableSmoothing();//非常非常非常影响性能
    myImage.load("color2.jpg");
    myImage.setImageType(OF_IMAGE_COLOR_ALPHA);
    ofLoadImage(pxdata, "color2.jpg");//load the pixel value into pxdata
    ofLoadImage(pxempty, "color2.jpg");
    imgw = myImage.getWidth();//width
    imgh = myImage.getHeight();//height
    int precision = 200;
    samplelength = imgw * imgh / precision;
    for(int i = 0; i < samplelength; i++){//sampling process this array is for draw
        sample.push_back(int(ofRandom(imgw*imgh)));
        //pick pixel index randomly
    }
    
//    for(int i = 0; i< imgh; i++){//这个是所有像素点都建立类，为了性能没有必要了
//        for(int j = 0; j<imgw;j++){
//            int r =pxdata.getData()[(imgw*i+j)*3];
//            int g = pxdata.getData()[(imgw*i+j)*3+1];
//            int b = pxdata.getData()[(imgw*i+j)*3+2];
////            int a = pxdata.getData()[(imgw*i+j)*3+3];
////            std::cout << "value: " << a << endl;
//            dots.push_back(dot());
//            dots[imgw*i+j].setup(i,j,10.0,r,g,b,255);
//
//        }
//    }
    
    for(int i = 0;i<samplelength;i++){
        int index = sample[i];
        int x = floor(index/imgw);
        int y = index - x*imgw;
        dots.push_back(dot());
        int r =pxdata.getData()[index*3];
        int g = pxdata.getData()[index*3+1];
        int b = pxdata.getData()[index*3+2];
        dots[i].setup(x, y, 15, r, g, b,150);//xy是画圆的位置，15是半径，255是alpha
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if(ofGetElapsedTimeMillis()-timecontrol>50){//时间还需要调整
        for(int i = 0; i< dots.size();i++){
            dots[i].ripple(ofRandom(1));
        }
        timecontrol = ofGetElapsedTimeMillis();
    }
        if(ofGetElapsedTimeMillis()-lastupdate>2000){//这里是更新参数
            for(int i = 0; i< 50;i++){
                int index = ofRandom(dots.size());
                if(dots[index].scale==0){
                    dots[index].scale = ofRandom(5);//这里留一个是随机的变量
                    
                }
            }
            lastupdate = ofGetElapsedTimeMillis();
            }


        
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255, 255, 255);//背景色到时候根据场地看深色还是浅色吧
    
    if(ofGetMousePressed()){//这里换成midi信号输入事件
       for(int i = 0; i< dots.size();i++){
           dots[i].checkchange();
           }
       }
    for(int i = 0;i<dots.size();i++){
    //这里的绘画顺序好像有点问题，不是很明显 到时候看看要把这个调整一下，可能是写在class里面的类要看看如何集成了。
        dots[i].draw();

    }
        

}
    

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

