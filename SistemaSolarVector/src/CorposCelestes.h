#pragma once
#include "ofMain.h"

class CorposCelestes {

public:

	ofVec2f m_position;
	ofImage m_img;
	float m_period, m_size;
	double m_mass, m_radius;
	ofVec2f m_anchor;


	CorposCelestes(ofVec2f Position, string path, float Time, double mass, double radius);

	void Draw();
	void Update(CorposCelestes* body);

	ofVec2f GetPosition();
	ofImage GetImage();

	void SetPosition(ofVec2f Position);


};