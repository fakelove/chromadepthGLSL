#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCoordHandedness(OF_RIGHT_HANDED);
    sphere.setRadius(100);
    chroma.load("shaders/chromadepth");
    
    ofFbo::Settings fboSettings;
    
    fboSettings.useDepth = true;
    fboSettings.useStencil = true;
    fboSettings.depthStencilAsTexture = true;
    fboSettings.width = 1280;
    fboSettings.height = 800;
    fboSettings.internalformat = GL_RGB32F_ARB;
    
    fbo.allocate(fboSettings);
    
    fbo.begin();
    ofClear(0, 0, 0, 0);
    fbo.end();
    
    // Setup box positions
    for (unsigned i = 0; i < 100; ++i)
    {
        posns.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), ofRandom(-300, 300)));
        cols.push_back(ofColor::fromHsb(255 * i / (float)100, 255, 255, 255));
    }
    
    // Setup light
    
    // create our own box mesh as there is a bug with
    // normal scaling and ofDrawBox() at the moment
    boxMesh = ofMesh::box(20, 20, 20);
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofBackground(0, 0, 0);

    
    cam.begin();
    chroma.begin();
    chroma.setUniform1f("near", 0);
    chroma.setUniform1f("far", 1000);
    glPushAttrib(GL_ENABLE_BIT);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    for (unsigned i = 0; i < posns.size(); ++i)
    {
        ofSetColor(cols[i]);
        ofPushMatrix();
        ofRotate(sin(ofGetElapsedTimef()*0.123)*360, 1, 1, 0);
        ofTranslate(posns[i]);
        boxMesh.draw();
        ofPopMatrix();
    }
    glPopAttrib();
    chroma.end();
    cam.end();


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
