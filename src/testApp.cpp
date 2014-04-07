#include "testApp.h"
//#include "OVR.h"
//using namespace OVR;
using namespace std;
/*OVR::Ptr<OVR::DeviceManager>	pManager;
OVR::Ptr<OVR::HMDDevice>		pHMD;
OVR::Ptr<OVR::SensorDevice>		pSensor;
OVR::SensorFusion				FusionResult;
OVR::HMDInfo					Info;
bool							InfoLoaded;
*/
#include <iostream>
#include <conio.h>

//--------------------------------------------------------------
void testApp::setup(){	
	//tested with PS3Eye camera.
	x_offset = 42;
	y_offset = 144;
	camWidth = 640;
	camHeight = 480;	
	symmetry = false;
	layer_offset = camWidth*camHeight;
	ofSetFullscreen(true);
	vidGrabberLeft.setVerbose(true);
	vidGrabberLeft.setDeviceID(0);
	vidGrabberLeft.setDesiredFrameRate(60);
	vidGrabberLeft.initGrabber(camWidth,camHeight);
	

	ofSetVerticalSync(true);
	
	//System::Init();
	pitch = 0;
	yaw = 0;
	roll = 0;

	//init oculus headtracking
	/*pManager = *DeviceManager::Create();
	pHMD = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();
	if (pHMD){
       InfoLoaded = pHMD->GetDeviceInfo(&Info);
	   pSensor = *pHMD->GetSensor();
	}
	else{
	   pSensor = *pManager->EnumerateDevices<SensorDevice>().CreateDevice();
	}
	if (pSensor){
	   FusionResult.AttachToSensor(pSensor);
	}	
	sender.setup(HOST, PORT);*/
}

//--------------------------------------------------------------
void testApp::update(){	
	ofBackground(0,0,0);
	vidGrabberLeft.update();			
	/*
	if(pSensor)
	{
		Quatf quaternion = FusionResult.GetOrientation();
		float roll;
		quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);
	}
	*/
}

//--------------------------------------------------------------
void testApp::draw(){		
	/*output();*/		
	ofLine(640,0,640,800);
	ofLine(1,1,1,800);
	//send angles value over OSC to control the servos
	/*ofxOscMessage m;
	m.setAddress("/ori");
	m.addFloatArg(pitch);
	m.addFloatArg(yaw);	
	m.addFloatArg(roll);	
	sender.sendMessage(m);		
	ofSetHexColor(0xffffff);		
	*/
	//duplicate video stream. You can also draw videograbbers from 2 different cameras. WASD to adjust the position of image.
	ofPushMatrix();		
		ofTranslate(camWidth/2, camHeight/2, 0);//move pivot to centre
		ofRotate(90, 0, 0, 1);//rotate from centre
		ofPushMatrix();
			vidGrabberLeft.draw(y_offset-camWidth/2,-x_offset-camHeight/2);//move back by the centre offset
			vidGrabberLeft.draw(y_offset-camWidth/2,x_offset-880);			
		ofPopMatrix();		
	ofPopMatrix(); 
	
}

void testApp::clear()
{
	/*pSensor.Clear();
        pHMD.Clear();
	pManager.Clear();

	System::Destroy();
	*/
}


void testApp::output()
{
	/*if(pSensor)
	{
		Quatf quaternion = FusionResult.GetOrientation();

		float roll;
		quaternion.GetEulerAngles<Axis_Y, Axis_X, Axis_Z>(&yaw, &pitch, &roll);

		cout << " Yaw: " << RadToDegree(yaw) << 
			", Pitch: " << RadToDegree(pitch) << 
			", Roll: " << RadToDegree(roll) << endl;						

		Sleep(50);

		if (_kbhit()) exit();
	}*/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	
	if (key == 'o' || key == 'O'){
		layer_offset +=2;
		cout << layer_offset;		
	}

	if (key == 'i' || key == 'I'){
		layer_offset -=2;
		cout << layer_offset;		
	}

	if (key == 'w' || key == 'w'){
		y_offset -= 2;
		cout << y_offset;
		//5016
	}

	if (key == 's' || key == 'S'){
		y_offset += 2;
		cout << y_offset;
	}
	
	if (key == 'a' || key == 'A'){
		x_offset -= 2;
		//37
		cout << x_offset;
	}

	if (key == 'd' || key == 'D'){
		x_offset += 2;
		//37
		cout << x_offset;
	}

	if (key == 'p' || key == 'P'){
		symmetry?symmetry=false:symmetry=true;
	}
	cout << " ";
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


/*		int totalPixels = camWidth*camHeight;
		unsigned char * pixels = vidGrabber.getPixels();
		for (int layer=0; layer<3; layer++){
			layer_offset=camWidth*camHeight*layer;
			for (int x=0; x<camWidth/2; x++){
				for (int y=0; y<camHeight; y++){
					pixels[(y*camWidth+x)+layer_offset] = pixels[(y*camWidth+(camWidth-x))+layer_offset];
				}			
			}*/
		//}
	//}

/*	cout << "----- Oculus Console -----" << endl;

	if (pHMD)
	{
		cout << " [x] HMD Found" << endl;
	}
	else
	{
		cout << " [ ] HMD Not Found" << endl;
	}

	if (pSensor)
	{
		cout << " [x] Sensor Found" << endl;
	}
	else
	{
		cout << " [ ] Sensor Not Found" << endl;
	}

	cout << "--------------------------" << endl;

	if (InfoLoaded)
        {
		cout << " DisplayDeviceName: " << Info.DisplayDeviceName << endl;
		cout << " ProductName: " << Info.ProductName << endl;
		cout << " Manufacturer: " << Info.Manufacturer << endl;
		cout << " Version: " << Info.Version << endl;
		cout << " HResolution: " << Info.HResolution<< endl;
		cout << " VResolution: " << Info.VResolution<< endl;
		cout << " HScreenSize: " << Info.HScreenSize<< endl;
		cout << " VScreenSize: " << Info.VScreenSize<< endl;
		cout << " VScreenCenter: " << Info.VScreenCenter<< endl;
		cout << " EyeToScreenDistance: " << Info.EyeToScreenDistance << endl;
		cout << " LensSeparationDistance: " << Info.LensSeparationDistance << endl;
		cout << " InterpupillaryDistance: " << Info.InterpupillaryDistance << endl;
		cout << " DistortionK[0]: " << Info.DistortionK[0] << endl;
		cout << " DistortionK[1]: " << Info.DistortionK[1] << endl;
		cout << " DistortionK[2]: " << Info.DistortionK[2] << endl;
		cout << "--------------------------" << endl;
        }

	cout << endl << " Press ENTER to continue" << endl;

	cin.get();
*/
