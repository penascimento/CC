#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Infinito 10000.0

#include "Queue.h"
#include "SimulationRoutines.h"

main()
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
		TipoEvento;

	float	TempoPrimeiraChegada,
		*FilaEventosChegadaSAtend,
		*FilaEventosChegadaSTriag,
		Clock,
		TempoProximaChegadaSAtend,
		TempoProximaChegadaSTriag,
		TempoProximaChegadaSMed,
		TempoPartidaSAtend1,
		TempoPartidaSAtend2,
		TempoTotalEsperaSAtend,
		TempoOcupacaoSAtend1,
		TempoOcupacaoSAtend2,
		TempoPartidaSTriag1,
		TempoPartidaSTriag2,
		TempoTotalEsperaSTriag,
		TempoOcupacaoSTriag1,
		TempoOcupacaoSTriag2,
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
		&FilaEventosChegadaSAtend,
		&Clock,
		&TempoProximaChegadaSAtend,
		&TempoPartidaSAtend1,
		&TempoPartidaSAtend2,
		&TempoTotalEsperaSAtend,
		&TempoOcupacaoSAtend1,
		&TempoOcupacaoSAtend2,
		&TempoTotalPermanencia,
		&TotalClientesFilaSAtend,
		&EstadoSTriag1,
		&EstadoSTriag2,
		&FilaEventosChegadaSTriag,
		&TempoProximaChegadaSTriag,
		&TempoPartidaSTriag1,
		&TempoPartidaSTriag2,
		&TempoTotalEsperaSTriag,
		&TempoOcupacaoSTriag1,
		&TempoOcupacaoSTriag2,
		&TotalClientesFilaSTriag,
		&TempoProximaChegadaSMed);

	while (flag == 0)
	{
		GestaoTempo(TempoProximaChegadaSAtend,
					TempoPartidaSAtend1,
					TempoPartidaSAtend2,
					TempoProximaChegadaSTriag,
					TempoPartidaSTriag1,
					TempoPartidaSTriag2,
					&Clock,
					&TipoEvento);

		if (Clock < Infinito)
			TempoTotalSistema = Clock;

		printf("\n\n Clock = %f", Clock);
		printf("\n TipoEvento = %d ", TipoEvento);

		printf("\nTempoProximaChegadaSAtend = %f", TempoProximaChegadaSAtend);
		printf("\nFila espera Atendimento:  ");
		ShowQueue(FilaEventosChegadaSAtend);	
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSAtend1);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSAtend2);
		printf("\n TempoProximaChegadaSTriag = %f", TempoProximaChegadaSTriag);
		printf("\nFila espera Atendimento:  ");
		ShowQueue(FilaEventosChegadaSTriag);
		printf("\n TempoPartidaSTriag1 = %f", TempoPartidaSTriag1);
		printf("\n TempoPartidaSTriag2 = %f", TempoPartidaSTriag2);
		printf("\n TempoProximaChegadaSMed = %f", TempoProximaChegadaSMed);

		if (TipoEvento == -1)
			break;

		switch (TipoEvento)
		{
		case 0: NumClientes++;
			EventoChegada(Clock,
				&NumClientesSistema,
				&EstadoSAtend1,
				&EstadoSAtend2,
				&FilaEventosChegadaSAtend,
				&TempoProximaChegadaSAtend,
				&TempoPartidaSAtend1,
				&TempoPartidaSAtend2,
				&TempoOcupacaoSAtend1,
				&TempoOcupacaoSAtend2,
				&TempoTotalPermanencia,
				&TotalClientesFilaSAtend);

			if (NumClientes == MaximoClientes)
				TempoProximaChegadaSAtend = Infinito;
			break;
		case 1: EventoPartida(Clock,
			&NumClientesSistema,
			&EstadoSAtend1,
			&FilaEventosChegadaSAtend,
			&TempoPartidaSAtend1,
			&TempoProximaChegadaSTriag,
			&TempoOcupacaoSAtend1,
			&TempoTotalEsperaSAtend,
			&TempoTotalPermanencia);
			break;
		case 2: EventoPartida(Clock,
			&NumClientesSistema,
			&EstadoSAtend2,
			&FilaEventosChegadaSAtend,
			&TempoPartidaSAtend2,
			&TempoProximaChegadaSTriag,
			&TempoOcupacaoSAtend2,
			&TempoTotalEsperaSAtend,
			&TempoTotalPermanencia);
			break;
		case 3: EventoChegadaProcServ(Clock,
							&NumClientesSistema,
							&EstadoSTriag1,
							&EstadoSTriag2,
							&FilaEventosChegadaSTriag,
							&TempoProximaChegadaSTriag,
							&TempoPartidaSTriag1,
							&TempoPartidaSTriag2,
							&TempoOcupacaoSTriag1,
							&TempoOcupacaoSTriag2,
							&TempoTotalPermanencia,
							&TotalClientesFilaSTriag);
			if (NumClientes == MaximoClientes)
				TempoProximaChegadaSTriag = Infinito;
			break;
		case 4: EventoPartida(Clock,
							&NumClientesSistema,
							&EstadoSTriag1,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag1,
							&TempoProximaChegadaSMed,
							&TempoOcupacaoSTriag1,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);
				break;
		case 5: EventoPartida (Clock,
							&NumClientesSistema,
							&EstadoSTriag2,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag2,
							&TempoProximaChegadaSMed,
							&TempoOcupacaoSTriag2,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);
			break;
		default: terminar = 1;
		}

		if (terminar == 1)
		{
			flag = 1;
			break;
		}

		printf("\n\nNumClientes = %d", NumClientes);
		printf("\n NumClientesSistema = %d \n", NumClientesSistema);
	}

	printf("\n\nCONTADORES ESTATISTICOS\n");
	printf("NumClientesSistema = %d\n", NumClientesSistema);
	printf("TotalClientesFila = %d\n", TotalClientesFilaSAtend);
	printf("TempoTotalSistema = %.3f\n", TempoTotalSistema);
	printf("TempoOcupacaoSAtend1 = %.3f\n", TempoOcupacaoSAtend1);
	printf("TempoOcupacaoSAtend2 = %.3f\n", TempoOcupacaoSAtend2);
	printf("TempoTotalEspera = %.3f\n", TempoTotalEsperaSAtend);
	printf("TempoTotalPermanencia = %.3f\n\n", TempoTotalPermanencia);

	ContadoresEstatisticos(NumClientesSistema,
		TotalClientesFilaSAtend,
		TempoOcupacaoSAtend1,
		TempoOcupacaoSAtend2,
		TempoTotalEsperaSAtend,
		TempoTotalPermanencia,
		TempoTotalSistema);

	printf("\n");
	if (EmptyQueue(FilaEventosChegadaSAtend))
		ShowQueue(FilaEventosChegadaSAtend);

	system("PAUSE");


}