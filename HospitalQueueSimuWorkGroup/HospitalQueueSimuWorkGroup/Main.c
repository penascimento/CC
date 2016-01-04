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
	scanf_s("%d", &MaximoClientes);

	srand((unsigned int)time(NULL));

	TempoPrimeiraChegada = DeterminarTempoEntreChegadas(2.0);

	Inicializacao(TempoPrimeiraChegada,
		&NumClientesSistema,
		&EstadoSAtend1,
		&EstadoSAtend2,
		&EstadoSTriag1,
		&EstadoSTriag2,
		&EstadoSMed1,
		&EstadoSMed2,
		&EstadoSMed3,
		&EstadoSMed4,
		&EstadoSExam1,
		&EstadoSExam2,
		&EstadoSExam3,
		&EstadoSExam4,
		&FilaSAtend,
		&FilaSTriag,
		&FilaSMed1,
		&FilaSMed2,
		&FilaSMed3,
		&FilaSMed4,
		&FilaSExam1,
		&FilaSExam2,
		&FilaSExam3,
		&FilaSExam4,
		&Clock,
		&TempoProximaChegada,
		&TempoPartidaSAtend1,
		&TempoPartidaSAtend2,
		&TempoPartidaSTriag1,
		&TempoPartidaSTriag2,
		&TempoPartidaSMed1,
		&TempoPartidaSMed2,
		&TempoPartidaSMed3,
		&TempoPartidaSMed4,
		&TempoPartidaSExam1,
		&TempoPartidaSExam2,
		&TempoPartidaSExam3,
		&TempoPartidaSExam4,
		&TempoTotalSAtend,
		&TempoTotalSTriag,
		&TempoTotalSMed,
		&TempoTotalSExam,
		&TempoOcupacaoSAtend1,
		&TempoOcupacaoSAtend2,
		&TempoOcupacaoSTriag1,
		&TempoOcupacaoSTriag2,
		&TempoOcupacaoSMed1,
		&TempoOcupacaoSMed2,
		&TempoOcupacaoSMed3,
		&TempoOcupacaoSMed4,
		&TempoOcupacaoSExam1,
		&TempoOcupacaoSExam2,
		&TempoOcupacaoSExam3,
		&TempoOcupacaoSExam4,
		&TempoTotalPermanencia,
		&TotalClientesFilaSAtend,
		&TotalClientesFilaSTriag,
		&TotalClientesFilaSMed,
		&TotalClientesFilaSExam);

	while (flag == 0)
	{
		GestaoTempo(TempoProximaChegada,
					TempoPartidaSAtend1,
					TempoPartidaSAtend2,
					TempoPartidaSTriag1,
					TempoPartidaSTriag2,
					TempoPartidaSMed1,
					TempoPartidaSMed2,
					TempoPartidaSMed3,
					TempoPartidaSMed4,
					TempoPartidaSExam1,
					TempoPartidaSExam2,
					TempoPartidaSExam3,
					TempoPartidaSExam4,
					&Clock,
					&TipoEvento);

		if (Clock < Infinito)
			TempoTotalSistema = Clock;

		printf("TempoProximaChegada = %f", TempoProximaChegada);
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSAtend1);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSAtend2);
		printf("\n TempoPartidaSTriag1 = %f", TempoPartidaSTriag1);
		printf("\n TempoPartidaSTriag2 = %f", TempoPartidaSTriag2);
		printf("\n TempoPartidaSMed1 = %f", TempoPartidaSMed1);
		printf("\n TempoPartidaSMed2 = %f", TempoPartidaSMed2);
		printf("\n TempoPartidaSMed3 = %f", TempoPartidaSMed3);
		printf("\n TempoPartidaSMed4 = %f", TempoPartidaSMed4);
		printf("\n TempoPartidaSExam1 = %f", TempoPartidaSExam1);
		printf("\n TempoPartidaSExam2 = %f", TempoPartidaSExam2);
		printf("\n TempoPartidaSExam3 = %f", TempoPartidaSExam3);
		printf("\n TempoPartidaSExam4 = %f", TempoPartidaSExam4);
		printf("\n Clock = %f", Clock);
		printf("\n TipoEvento = %d ", TipoEvento);
		
		if (TipoEvento == -1)
			break;
		
		switch (TipoEvento)
		{
		case 0:
			NumClientes++;
			EventoChegadaSAtend(Clock,
								&NumClientesSistema,
								&EstadoSAtend1,
								&EstadoSAtend2,
								&FilaSAtend,
								&TempoProximaChegada,
								&TempoPartidaSAtend1,
								&TempoPartidaSAtend2,
								&TempoOcupacaoSAtend1,
								&TempoOcupacaoSAtend2,
								&TempoTotalPermanencia,
								&TotalClientesFilaSAtend);

			if (NumClientes == MaximoClientes)
				TempoProximaChegada = Infinito;
			break;
		case 1:
			EventoPartidaSAtend1(Clock,
								&NumClientesSistema,
								&EstadoSAtend1,
								&FilaSAtend,
								&TempoPartidaSAtend1,
								&TempoOcupacaoSAtend1,
								&TempoTotalSAtend,
								&TempoTotalPermanencia);
			break;
		case 2:
			EventoPartidaSAtend2(Clock,
				&NumClientesSistema,
				&EstadoSAtend2,
				&FilaSAtend,
				&TempoPartidaSAtend2,
				&TempoOcupacaoSAtend2,
				&TempoTotalSAtend,
				&TempoTotalPermanencia);
			break;
		/*case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 12:
			break;*/
		default: terminar = 1;
		}

		if (terminar == 1)
		{
			flag = 1;
			break;
		}

		printf("NumClientes = %d", NumClientes);
		printf("\n NumClientesSistema = %d \n", NumClientesSistema);
	}

	printf("\n");
	if (EmptyQueue(FilaSAtend))
		ShowQueue(FilaSAtend);
	if (EmptyQueue(FilaSTriag))
		ShowQueue(FilaSTriag);
	if (EmptyQueue(FilaSMed1))
		ShowQueue(FilaSMed1);
	if (EmptyQueue(FilaSMed2))
		ShowQueue(FilaSMed2);
	if (EmptyQueue(FilaSMed3))
		ShowQueue(FilaSMed3);
	if (EmptyQueue(FilaSMed4))
		ShowQueue(FilaSMed4);
	if (EmptyQueue(FilaSExam1))
		ShowQueue(FilaSExam1);
	if (EmptyQueue(FilaSExam2))
		ShowQueue(FilaSExam2);
	if (EmptyQueue(FilaSExam3))
		ShowQueue(FilaSExam3);
	if (EmptyQueue(FilaSExam3))
		ShowQueue(FilaSExam3);

	system("PAUSE");
}
