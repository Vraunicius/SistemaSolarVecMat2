#include "CorposCelestes.h"

CorposCelestes::CorposCelestes(ofVec2f Position, string path, float Time, double mass, double radius){

	SetPosition(Position);
	m_img.load(path);
	m_period = Time;
	m_anchor.set(GetPosition());
	m_mass = mass;
	m_radius = radius;
	
}

void CorposCelestes::Draw(){

	ofImage imagem = GetImage();
	imagem.setAnchorPercent(0.5, 0.5);
	//imagem.resize(30, 30);
	ofPushMatrix();
	ofTranslate(GetPosition());
	imagem.draw(0, 0);
	ofPopMatrix();

}

void CorposCelestes::Update(CorposCelestes* body){
	m_anchor.rotate(m_period);
	m_position = m_anchor;
	m_position += body->GetPosition();
}

ofVec2f CorposCelestes::GetPosition(){
	return m_position;
}

ofImage CorposCelestes::GetImage(){
	return m_img;
}

void CorposCelestes::SetPosition(ofVec2f Position){
	m_position.set(Position);
}

