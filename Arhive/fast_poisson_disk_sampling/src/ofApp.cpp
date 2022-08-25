#include "ofApp.h"
#include "Sampler.hpp"
Sampler fast_poission_disk_sampler;

//ofVec2f orginalarray [3] = {ofVec2f(-1, -1),ofVec2f(-2, -1),ofVec2f(-3, -1)};

int scl;

//--------------------------------------------------------------
void ofApp::setup(){
//--------------------------------------------------------------测试智能指针
//    active = std::unique_ptr<ofVec2f[]>(new ofVec2f[3]{ofVec2f(-1, -1),ofVec2f(-2, -1),ofVec2f(-3, -1)});
//    active = new ofVec2f[3]{ofVec2f(-1, -1),ofVec2f(-2, -1),ofVec2f(-3, -1)};
//    active = orginalarray;
//--------------------------------------------------------------

    ofBackground(0);
    fast_poission_disk_sampler.init();
    fast_poission_disk_sampler.sampling();

    
    ofLoadImage(pxdata, "bbb.jpg");
    pxdata.allocate(pxdata.getWidth(), pxdata.getHeight(), OF_IMAGE_COLOR);
    std::cout<<"width"<<pxdata.getWidth()<<endl;
    std::cout<<"width"<<pxdata.getHeight()<<endl;
    for(int i = 0;i<fast_poission_disk_sampler.samples.size();i++){
        std::cout<<fast_poission_disk_sampler.samples[i]<<endl;
    }

 
//    std::cout<<fast_poission_disk_sampler.samples.size()<<endl;
//    std::cout<<pxdata.size()<<endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//--------------------------------------------------------------测试智能指针
//    for(int i = 0 ; i<3;i++){
//        std::cout<<active[i].getNormalized() <<endl;
//    }
//--------------------------------------------------------------
//    fast_poission_disk_sampler.sampling();
//    fast_poission_disk_sampler.visualization();
//--------------------------------------------------------------
        for(int i = 0;i<pxdata.size()/50;i++){
            int x = int(ofRandom(pxdata.getWidth()));
            int y = int(ofRandom(pxdata.getHeight()));
            int index = y*pxdata.getWidth()+x;
            int r = pxdata.getData()[index*3];
            int g = pxdata.getData()[index*3+1];
            int b = pxdata.getData()[index*3+2];
            ofSetColor(r, g, b);
            ofDrawCircle(x, y, 3);
        }


    
//    for(int i = 0;i<fast_poission_disk_sampler.samples.size();i++){
//
//        float xscl = pxdata.getWidth()/ofGetWidth();
//        float yscl = pxdata.getHeight()/ofGetHeight();
//        float orginalxpos =floor(fast_poission_disk_sampler.samples[i].x);
//        float orginalypos =floor(fast_poission_disk_sampler.samples[i].y);
//
//        int xpos = floor(orginalxpos*xscl);
//        int ypos = floor(orginalypos*yscl);
//        int index = ypos*pxdata.getWidth()+xpos;
//
//        int r = pxdata.getData()[index*3+0];
//        int g = pxdata.getData()[index*3+1];
//        int b = pxdata.getData()[index*3+2];
//
//        ofSetColor(r, g, b);
//        ofDrawCircle(orginalxpos, orginalypos, 8);
//
//    }
    
    
    
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
