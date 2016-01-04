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
		EstadoSAtend1,
		EstadoSAtend2,
		TotalClientesFilaSAtend,
		EstadoSTriag1,
		EstadoSTriag2,
		TotalClientesFilaSTriag,
		EstadoSMed1,
		EstadoSMed2,
		EstadoSMed3,
		EstadoSMed4,
		TotalClientesFilaSMed,
		EstadoSExam1,
		EstadoSExam2,
		EstadoSExam3,
		EstadoSExam4,
		TotalClientesFilaSExam,
		TipoEvento;

	float	TempoPrimeiraChegada,
			*FilaSAtend,
			*FilaSTriag,
			*FilaSMed1,
			*FilaSMed2,
			*FilaSMed3,
			*FilaSMed4,
			*FilaSExam1,
			*FilaSExam2,
			*FilaSExam3,
			*FilaSExam4,
			Clock,
			TempoProximaChegada,
			TempoPartidaSAtend1,
			TempoPartidaSAtend2,
			TempoTotalSAtend,
			TempoPartidaSTriag1,
			TempoPartidaSTriag2,
			TempoTotalSTriag,
			TempoPartidaSMed1,
			TempoPartidaSMed2,
			TempoPartidaSMed3,
			TempoPartidaSMed4,
			TempoTotalSMed,
			TempoPartidaSExam1,
			TempoPartidaSExam2,
			TempoPartidaSExam3,
			TempoPartidaSExam4,
			TempoTotalSExam,

			TempoOcupacaoSAtend1,
			TempoOcupacaoSAtend2,
			TempoOcupacaoSTriag1,
			TempoOcupacaoSTriag2,
			TempoOcupacaoSMed1,
			TempoOcupacaoSMed2,
			TempoOcupacaoSMed3,
			TempoOcupacaoSMed4,
			TempoOcupacaoSExam1,
			TempoOcupacaoSExam2,
			TempoOcupacaoSExam3,
			TempoOcupacaoSExam4,

			TempoTotalPermanencia,
			TempoTotalSistema;


	printf("Com quantos clientes quer realizar a simulacao ? ");
	scanf("%d", &MaximoClientes);

	srand((unsigned int)time(NULL));

	TempoPrimeiraChegada = DeterminarTempoEntreChegadas(2.0);
}