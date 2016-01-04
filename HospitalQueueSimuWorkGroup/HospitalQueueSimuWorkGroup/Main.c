#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Infinito 10000.0

#include "Queue.h"
#include "SimulationRoutines.h"

void main()
{
	int flag = 0,
		terminar = 0,
		MaximoClientes,
		NumClientes = 0,
		NumClientesSistema,
		EstadoAgente1,
		EstadoAgente2,
		TotalClientesFila,
		TipoEvento;

	float	TempoPrimeiraChegada,
		*FilaEventosChegada,
		Clock,
		TempoProximaChegada,
		TempoPartida1,
		TempoPartida2,
		TempoTotalEspera,
		TempoOcupacaoAgente1,
		TempoOcupacaoAgente2,
		TempoTotalPermanencia,
		TempoTotalSistema;
}