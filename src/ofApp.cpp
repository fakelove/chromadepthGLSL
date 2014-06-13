#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCoordHandedness(OF_RIGHT_HANDED);
    sphere.setRadius(100);
    chroma.load("shaders/chromadepth_texture");
    
    ofFbo::Settings fboSettings;
    
    fboSettings.width = 1280;
    fboSettings.height = 800;
    fboSettings.internalformat = GL_RGBA32F_ARB;
    
    fbo.allocate(fboSettings);
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();
    
    // Setup box positions
    for (unsigned i = 0; i < 5; ++i)
    {
        posns.push_back(ofVec3f(ofRandom(-300, 300)*2, ofRandom(-300, 300)*2, ofRandom(-300, 300)*2));
        cols.push_back(ofColor::fromHsb(255 * i / (float)100, 255, 255, 255));
    }
    
    // Setup light
    
    // create our own box mesh as there is a bug with
    // normal scaling and ofDrawBox() at the moment

    
    vidcam.initGrabber(1280, 720);
    
    
    
    sphere.setRadius(200);
    sphere.mapTexCoordsFromTexture(vidcam.getTextureReference());
    
    mesh = sphere.getMesh();
}

//--------------------------------------------------------------
void ofApp::update(){
    vidcam.update();
    fbo.begin();
    ofClear(0, 0, 0);
    cam.begin();
    ofPushStyle();
    
    glEnable(GL_DEPTH_TEST);
    for (unsigned i = 0; i < posns.size(); ++i)
    {
        ofSetColor(cols[i]);
        ofPushMatrix();
        ofRotate(sin(ofGetElapsedTimef()*0.123)*360, 1, 1, 0);
        ofTranslate(posns[i]);
        mesh.draw();
        ofPopMatrix();
    }
    ofPopStyle();

    cam.end();
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofBackground(0, 0, 0);

    
    cam.begin();
    chroma.begin();
    chroma.setUniform1f("near", 0);
    chroma.setUniform1f("far", 2000);
    chroma.setUniformTexture("diffusemap", vidcam.getTextureReference(), 0);
    ofPushStyle();
    
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
    for (unsigned i = 0; i < posns.size(); ++i)
    {
        ofSetColor(cols[i]);
        ofPushMatrix();
        ofRotate(sin(ofGetElapsedTimef()*0.123)*360, 1, 1, 0);
        ofTranslate(posns[i]);
        mesh.draw();
        ofPopMatrix();
    }
    ofPopStyle();
    chroma.end();
    cam.end();

//    ofPushStyle();
//    ofSetColor(255, 255, 255);
//    vidcam.draw(0, 0, 640, 360);
//    ofPopStyle();

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
