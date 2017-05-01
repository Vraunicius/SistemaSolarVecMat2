#include "Meteoro.h"

Meteoro::Meteoro(int x, int y, double mass, double radius, float VelX, float VelY, string path){
	SetPosition(x, y);
	m_mass = mass;
	m_radius = radius;
	m_velocity.set(VelX, VelY);
	m_img.load(path);
	
}

void Meteoro::Draw(){
	ofImage imagem = GetImage();
	imagem.setAnchorPercent(0.5, 0.5);
	imagem.resize(75,75);
	ofPushMatrix();
	ofTranslate(GetPosition());
	imagem.draw(0, 0);
	ofPopMatrix();
}

void Meteoro::Update(CorposCelestes * body){
	Update(body->m_position, body->m_mass, body->m_radius);
}

void Meteoro::Update(Meteoro * body){
	Update(body->m_position, body->m_mass, body->m_radius);
}

void Meteoro::Update(ofVec2f position, double mass, double radius){
	double distance = sqrt(pow(position.x - m_position.x, 2) + pow(position.y - m_position.y, 2));

	if (distance > (m_radius + radius))
		m_velocity += 0.00667408 * mass / pow(distance, 2) * ((position - m_position) / distance);

	m_position += m_velocity;
}



ofImage Meteoro::GetImage()
{
	return m_img;
}

ofVec2f Meteoro::GetPosition()
{
	return m_position;
}

void Meteoro::SetPosition(int x, int y){
	m_position.set(x, y);
}
