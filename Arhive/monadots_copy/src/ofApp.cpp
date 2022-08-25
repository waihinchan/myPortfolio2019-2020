#include "ofApp.h"
float rad = 0;

ofTexture MyTexture;
int size = 5;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofLoadImage(MyPixel, "mona.png");
    MyPixel.setImageType(OF_IMAGE_GRAYSCALE);
    MyPixel.allocate(MyPixel.getWidth(), MyPixel.getHeight(), OF_IMAGE_GRAYSCALE);
    std::cout<<MyPixel.getWidth()<<endl;
    std::cout<<MyPixel.getHeight()<<endl;
    std::cout<<MyPixel.size()<<endl;


    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,20,10);
    ofSetCircleResolution(36);

    for(int i = 0;i<MyPixel.getHeight();i+=3){
        for(int j = 0;j<MyPixel.getWidth();j+=3){
            ofFill();
            int index = j*MyPixel.getWidth()+i;
            float phase = MyPixel.getData()[index]*PI*0.5/255;
            ofPushMatrix();
            float x = cos(rad+phase)*30;
            float y = sin(rad+phase)*30;
            ofTranslate(i, j);
            ofDrawCircle(x, y, 1);
            ofPopMatrix();
        }
    }
    rad+=0.01;
    if(rad == TWO_PI){
        rad = 0;
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
