#pragma once
class Operario
{
private:
	int num_Op;
	bool estado;
	float hs_finalizacion;
public:
	Operario();
	Operario(int);
	~Operario();
	int getnum_Op();
	bool getEstado();
	void setEstado(bool);
	void setfinalizacion(float);
	float getfinalizacion();
};

