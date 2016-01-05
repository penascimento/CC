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
		EstadoSMed1,
		TotalClientesFilaSMed1,
		EstadoSMed2,
		TotalClientesFilaSMed2,
		EstadoSMed3,
		TotalClientesFilaSMed3,
		EstadoSMed4,
		TotalClientesFilaSMed4,
		TipoEvento;

	float	TempoPrimeiraChegada,
		*FilaEventosChegadaSAtend,
		*FilaEventosChegadaSTriag,
		*FilaEventosChegadaSMed1,
		*FilaEventosChegadaSMed2,
		*FilaEventosChegadaSMed3,
		*FilaEventosChegadaSMed4,
		Clock,
		TempoProximaChegadaSAtend,
		TempoProximaChegadaSTriag,
		TempoProximaChegadaSMed1,
		TempoProximaChegadaSMed2,
		TempoProximaChegadaSMed3,
		TempoProximaChegadaSMed4,
		TempoPartidaSAtend1,
		TempoPartidaSAtend2,
		TempoPartidaSMed1,
		TempoPartidaSMed2,
		TempoPartidaSMed3,
		TempoPartidaSMed4,
		TempoTotalEsperaSAtend,
		TempoOcupacaoSAtend1,
		TempoOcupacaoSAtend2,
		TempoOcupacaoSMed1,
		TempoOcupacaoSMed2,
		TempoOcupacaoSMed3,
		TempoOcupacaoSMed4,
		TempoPartidaSTriag1,
		TempoPartidaSTriag2,
		TempoTotalEsperaSTriag,
		TempoTotalEsperaSMed1,
		TempoTotalEsperaSMed2,
		TempoTotalEsperaSMed3,
		TempoTotalEsperaSMed4,
		TempoOcupacaoSTriag1,
		TempoOcupacaoSTriag2,
		TempoTotalPermanencia,
		TempoTotalSistema,
		TempoProximaChegadaSMedTemp=0;
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
		&EstadoSMed1,
		&FilaEventosChegadaSMed1,
		&TempoProximaChegadaSMed1,
		&TempoPartidaSMed1,
		&TempoTotalEsperaSMed1,
		&TempoOcupacaoSMed1,
		&TotalClientesFilaSMed1,
		&EstadoSMed2,
		&FilaEventosChegadaSMed2,
		&TempoProximaChegadaSMed2,
		&TempoPartidaSMed2,
		&TempoTotalEsperaSMed2,
		&TempoOcupacaoSMed2,
		&TotalClientesFilaSMed2,
		&EstadoSMed3,
		&FilaEventosChegadaSMed3,
		&TempoProximaChegadaSMed3,
		&TempoPartidaSMed3,
		&TempoTotalEsperaSMed3,
		&TempoOcupacaoSMed3,
		&TotalClientesFilaSMed3,
		&EstadoSMed4,
		&FilaEventosChegadaSMed4,
		&TempoProximaChegadaSMed4,
		&TempoPartidaSMed4,
		&TempoTotalEsperaSMed4,
		&TempoOcupacaoSMed4,
		&TotalClientesFilaSMed4);

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
		printf("\nTempoProximaChegadaSMed1 = %f", TempoProximaChegadaSMed1);
		printf("\nFila espera Atendimento Medico1:  ");
		ShowQueue(FilaEventosChegadaSMed1);
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSMed1);
		printf("\nTempoProximaChegadaSMed2 = %f", TempoProximaChegadaSMed2);
		printf("\nFila espera Atendimento Medico2:  ");
		ShowQueue(FilaEventosChegadaSMed2);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSMed2);
		printf("\nTempoProximaChegadaSMed3 = %f", TempoProximaChegadaSMed3);
		printf("\nFila espera Atendimento Medico3:  ");
		ShowQueue(FilaEventosChegadaSMed3);
		printf("\n TempoPartidaSMed3 = %f", TempoPartidaSMed3);
		printf("\nTempoProximaChegadaSMed4 = %f", TempoProximaChegadaSMed4);
		printf("\nFila espera Atendimento Medico4:  ");
		ShowQueue(FilaEventosChegadaSMed4);
		printf("\n TempoPartidaSMed4 = %f\n", TempoPartidaSMed4);
		
		system("PAUSE");

		if (TipoEvento == -1)
			break;

		switch (TipoEvento)
		{
		case 0: NumClientes++;
			EventoChegadaSistema(Clock,
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
		case 3: EventoChegadaProcServCom2Serv(Clock,
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
		case 4: 			
			EventoPartida(Clock,
							&NumClientesSistema,
							&EstadoSTriag1,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag1,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSTriag1,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);

			SelectMedic(TempoProximaChegadaSMedTemp,
						&TempoProximaChegadaSMed1,
						&TempoProximaChegadaSMed2,
						&TempoProximaChegadaSMed3,
						&TempoProximaChegadaSMed4);
				break;
		case 5: EventoPartida (Clock,
							&NumClientesSistema,
							&EstadoSTriag2,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag2,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSTriag2,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);

			SelectMedic(TempoProximaChegadaSMedTemp,
						&TempoProximaChegadaSMed1,
						&TempoProximaChegadaSMed2,
						&TempoProximaChegadaSMed3,
						&TempoProximaChegadaSMed4);
			break;
		//case 6: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
		//					&NumClientesSistema,
		//					&EstadoSMed1,
		//					&FilaEventosChegadaSMed1,
		//					&TempoProximaChegadaSMed1,
		//					&TempoPartidaSMed1,
		//					&TempoOcupacaoSMed1,
		//					&TempoTotalPermanencia,
		//					&TotalClientesFilaSMed1);
		//	break;
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