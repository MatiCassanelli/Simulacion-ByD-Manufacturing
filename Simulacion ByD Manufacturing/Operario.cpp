#include "stdafx.h"
#include "Operario.h"


Operario::Operario(int i)
{
	num_Op = i;
	estado = true;
}


Operario::Operario()
{
}

Operario::~Operario()
{
}

int Operario::getnum_Op()
{
	return num_Op;
}

bool Operario::getEstado()
{
	return estado;
}

void Operario::setEstado(bool sestado)
{
	estado = sestado;
}

void Operario::setfinalizacion(float sfin)
{
	hs_finalizacion = sfin;
}

float Operario::getfinalizacion()
{
	return hs_finalizacion;
}
